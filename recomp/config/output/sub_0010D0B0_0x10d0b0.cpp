#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_0010D0B0
// Address: 0x10d0b0 - 0x10d168
void sub_0010D0B0_0x10d0b0(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_0010D0B0_0x10d0b0");
#endif

    switch (ctx->pc) {
        case 0x10d114u: goto label_10d114;
        case 0x10d128u: goto label_10d128;
        default: break;
    }

    ctx->pc = 0x10d0b0u;

    // 0x10d0b0: 0x27bdfb80  addiu       $sp, $sp, -0x480
    ctx->pc = 0x10d0b0u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294966144));
    // 0x10d0b4: 0x240a0400  addiu       $t2, $zero, 0x400
    ctx->pc = 0x10d0b4u;
    SET_GPR_S32(ctx, 10, (int32_t)ADD32(GPR_U32(ctx, 0), 1024));
    // 0x10d0b8: 0xffb00460  sd          $s0, 0x460($sp)
    ctx->pc = 0x10d0b8u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 1120), GPR_U64(ctx, 16));
    // 0x10d0bc: 0x80802d  daddu       $s0, $a0, $zero
    ctx->pc = 0x10d0bcu;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x10d0c0: 0xffb10468  sd          $s1, 0x468($sp)
    ctx->pc = 0x10d0c0u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 1128), GPR_U64(ctx, 17));
    // 0x10d0c4: 0x27ab0060  addiu       $t3, $sp, 0x60
    ctx->pc = 0x10d0c4u;
    SET_GPR_S32(ctx, 11, (int32_t)ADD32(GPR_U32(ctx, 29), 96));
    // 0x10d0c8: 0xffbf0470  sd          $ra, 0x470($sp)
    ctx->pc = 0x10d0c8u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 1136), GPR_U64(ctx, 31));
    // 0x10d0cc: 0x3a0202d  daddu       $a0, $sp, $zero
    ctx->pc = 0x10d0ccu;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 29) + (uint64_t)GPR_U64(ctx, 0));
    // 0x10d0d0: 0xafab0010  sw          $t3, 0x10($sp)
    ctx->pc = 0x10d0d0u;
    WRITE32(ADD32(GPR_U32(ctx, 29), 16), GPR_U32(ctx, 11));
    // 0x10d0d4: 0x9602000c  lhu         $v0, 0xC($s0)
    ctx->pc = 0x10d0d4u;
    SET_GPR_U32(ctx, 2, (uint16_t)READ16(ADD32(GPR_U32(ctx, 16), 12)));
    // 0x10d0d8: 0x9609000e  lhu         $t1, 0xE($s0)
    ctx->pc = 0x10d0d8u;
    SET_GPR_U32(ctx, 9, (uint16_t)READ16(ADD32(GPR_U32(ctx, 16), 14)));
    // 0x10d0dc: 0x8e080054  lw          $t0, 0x54($s0)
    ctx->pc = 0x10d0dcu;
    SET_GPR_S32(ctx, 8, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 84)));
    // 0x10d0e0: 0x3042fffd  andi        $v0, $v0, 0xFFFD
    ctx->pc = 0x10d0e0u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) & (uint64_t)(uint16_t)65533);
    // 0x10d0e4: 0x8e03001c  lw          $v1, 0x1C($s0)
    ctx->pc = 0x10d0e4u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 28)));
    // 0x10d0e8: 0x8e070024  lw          $a3, 0x24($s0)
    ctx->pc = 0x10d0e8u;
    SET_GPR_S32(ctx, 7, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 36)));
    // 0x10d0ec: 0xafa80054  sw          $t0, 0x54($sp)
    ctx->pc = 0x10d0ecu;
    WRITE32(ADD32(GPR_U32(ctx, 29), 84), GPR_U32(ctx, 8));
    // 0x10d0f0: 0xa7a2000c  sh          $v0, 0xC($sp)
    ctx->pc = 0x10d0f0u;
    WRITE16(ADD32(GPR_U32(ctx, 29), 12), (uint16_t)GPR_U32(ctx, 2));
    // 0x10d0f4: 0xa7a9000e  sh          $t1, 0xE($sp)
    ctx->pc = 0x10d0f4u;
    WRITE16(ADD32(GPR_U32(ctx, 29), 14), (uint16_t)GPR_U32(ctx, 9));
    // 0x10d0f8: 0xafa3001c  sw          $v1, 0x1C($sp)
    ctx->pc = 0x10d0f8u;
    WRITE32(ADD32(GPR_U32(ctx, 29), 28), GPR_U32(ctx, 3));
    // 0x10d0fc: 0xafa70024  sw          $a3, 0x24($sp)
    ctx->pc = 0x10d0fcu;
    WRITE32(ADD32(GPR_U32(ctx, 29), 36), GPR_U32(ctx, 7));
    // 0x10d100: 0xafaa0014  sw          $t2, 0x14($sp)
    ctx->pc = 0x10d100u;
    WRITE32(ADD32(GPR_U32(ctx, 29), 20), GPR_U32(ctx, 10));
    // 0x10d104: 0xafab0000  sw          $t3, 0x0($sp)
    ctx->pc = 0x10d104u;
    WRITE32(ADD32(GPR_U32(ctx, 29), 0), GPR_U32(ctx, 11));
    // 0x10d108: 0xafaa0008  sw          $t2, 0x8($sp)
    ctx->pc = 0x10d108u;
    WRITE32(ADD32(GPR_U32(ctx, 29), 8), GPR_U32(ctx, 10));
    // 0x10d10c: 0xc04345a  jal         func_10D168
    ctx->pc = 0x10D10Cu;
    SET_GPR_U32(ctx, 31, 0x10D114u);
    ctx->pc = 0x10D110u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x10D10Cu;
            // 0x10d110: 0xafa00018  sw          $zero, 0x18($sp) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 29), 24), GPR_U32(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x10D168u;
    if (runtime->hasFunction(0x10D168u)) {
        auto targetFn = runtime->lookupFunction(0x10D168u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x10D114u; }
        if (ctx->pc != 0x10D114u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0010D168_0x10d168(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x10D114u; }
        if (ctx->pc != 0x10D114u) { return; }
    }
    ctx->pc = 0x10D114u;
label_10d114:
    // 0x10d114: 0x40882d  daddu       $s1, $v0, $zero
    ctx->pc = 0x10d114u;
    SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x10d118: 0x6200005  bltz        $s1, . + 4 + (0x5 << 2)
    ctx->pc = 0x10D118u;
    {
        const bool branch_taken_0x10d118 = (GPR_S64(ctx, 17) < 0);
        ctx->pc = 0x10D11Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x10D118u;
            // 0x10d11c: 0x3a0202d  daddu       $a0, $sp, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 29) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x10d118) {
            ctx->pc = 0x10D130u;
            goto label_10d130;
        }
    }
    ctx->pc = 0x10D120u;
    // 0x10d120: 0xc04142c  jal         func_1050B0
    ctx->pc = 0x10D120u;
    SET_GPR_U32(ctx, 31, 0x10D128u);
    ctx->pc = 0x1050B0u;
    if (runtime->hasFunction(0x1050B0u)) {
        auto targetFn = runtime->lookupFunction(0x1050B0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x10D128u; }
        if (ctx->pc != 0x10D128u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001050B0_0x1050b0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x10D128u; }
        if (ctx->pc != 0x10D128u) { return; }
    }
    ctx->pc = 0x10D128u;
label_10d128:
    // 0x10d128: 0x2403ffff  addiu       $v1, $zero, -0x1
    ctx->pc = 0x10d128u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
    // 0x10d12c: 0x62880b  movn        $s1, $v1, $v0
    ctx->pc = 0x10d12cu;
    if (GPR_U64(ctx, 2) != 0) SET_GPR_VEC(ctx, 17, GPR_VEC(ctx, 3));
label_10d130:
    // 0x10d130: 0x97a2000c  lhu         $v0, 0xC($sp)
    ctx->pc = 0x10d130u;
    SET_GPR_U32(ctx, 2, (uint16_t)READ16(ADD32(GPR_U32(ctx, 29), 12)));
    // 0x10d134: 0x30420040  andi        $v0, $v0, 0x40
    ctx->pc = 0x10d134u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) & (uint64_t)(uint16_t)64);
    // 0x10d138: 0x10400005  beqz        $v0, . + 4 + (0x5 << 2)
    ctx->pc = 0x10D138u;
    {
        const bool branch_taken_0x10d138 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x10D13Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x10D138u;
            // 0x10d13c: 0x220102d  daddu       $v0, $s1, $zero (Delay Slot)
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x10d138) {
            ctx->pc = 0x10D150u;
            goto label_10d150;
        }
    }
    ctx->pc = 0x10D140u;
    // 0x10d140: 0x9602000c  lhu         $v0, 0xC($s0)
    ctx->pc = 0x10d140u;
    SET_GPR_U32(ctx, 2, (uint16_t)READ16(ADD32(GPR_U32(ctx, 16), 12)));
    // 0x10d144: 0x34420040  ori         $v0, $v0, 0x40
    ctx->pc = 0x10d144u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) | (uint64_t)(uint16_t)64);
    // 0x10d148: 0xa602000c  sh          $v0, 0xC($s0)
    ctx->pc = 0x10d148u;
    WRITE16(ADD32(GPR_U32(ctx, 16), 12), (uint16_t)GPR_U32(ctx, 2));
    // 0x10d14c: 0x220102d  daddu       $v0, $s1, $zero
    ctx->pc = 0x10d14cu;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
label_10d150:
    // 0x10d150: 0xdfb00460  ld          $s0, 0x460($sp)
    ctx->pc = 0x10d150u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 1120)));
    // 0x10d154: 0xdfb10468  ld          $s1, 0x468($sp)
    ctx->pc = 0x10d154u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 1128)));
    // 0x10d158: 0xdfbf0470  ld          $ra, 0x470($sp)
    ctx->pc = 0x10d158u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 1136)));
    // 0x10d15c: 0x3e00008  jr          $ra
    ctx->pc = 0x10D15Cu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x10D160u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x10D15Cu;
            // 0x10d160: 0x27bd0480  addiu       $sp, $sp, 0x480 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 1152));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x10D114u: goto label_10d114;
            case 0x10D128u: goto label_10d128;
            case 0x10D130u: goto label_10d130;
            case 0x10D150u: goto label_10d150;
            default: break;
        }
        return;
    }
    ctx->pc = 0x10D164u;
    // 0x10d164: 0x0  nop
    ctx->pc = 0x10d164u;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
