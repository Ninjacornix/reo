#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001638E8
// Address: 0x1638e8 - 0x163988
void sub_001638E8_0x1638e8(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001638E8_0x1638e8");
#endif

    switch (ctx->pc) {
        case 0x16391cu: goto label_16391c;
        case 0x163928u: goto label_163928;
        case 0x16393cu: goto label_16393c;
        case 0x163944u: goto label_163944;
        case 0x16394cu: goto label_16394c;
        default: break;
    }

    ctx->pc = 0x1638e8u;

    // 0x1638e8: 0x27bdffd0  addiu       $sp, $sp, -0x30
    ctx->pc = 0x1638e8u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967248));
    // 0x1638ec: 0x24020001  addiu       $v0, $zero, 0x1
    ctx->pc = 0x1638ecu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x1638f0: 0xffb10008  sd          $s1, 0x8($sp)
    ctx->pc = 0x1638f0u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 8), GPR_U64(ctx, 17));
    // 0x1638f4: 0x80882d  daddu       $s1, $a0, $zero
    ctx->pc = 0x1638f4u;
    SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1638f8: 0xffb00000  sd          $s0, 0x0($sp)
    ctx->pc = 0x1638f8u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x1638fc: 0xffb20010  sd          $s2, 0x10($sp)
    ctx->pc = 0x1638fcu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 18));
    // 0x163900: 0xffb30018  sd          $s3, 0x18($sp)
    ctx->pc = 0x163900u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 24), GPR_U64(ctx, 19));
    // 0x163904: 0xffbf0020  sd          $ra, 0x20($sp)
    ctx->pc = 0x163904u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 32), GPR_U64(ctx, 31));
    // 0x163908: 0x8e320118  lw          $s2, 0x118($s1)
    ctx->pc = 0x163908u;
    SET_GPR_S32(ctx, 18, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 280)));
    // 0x16390c: 0x1642000b  bne         $s2, $v0, . + 4 + (0xB << 2)
    ctx->pc = 0x16390Cu;
    {
        const bool branch_taken_0x16390c = (GPR_U64(ctx, 18) != GPR_U64(ctx, 2));
        ctx->pc = 0x163910u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x16390Cu;
            // 0x163910: 0x8e330040  lw          $s3, 0x40($s1) (Delay Slot)
        SET_GPR_S32(ctx, 19, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 64)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x16390c) {
            ctx->pc = 0x16393Cu;
            goto label_16393c;
        }
    }
    ctx->pc = 0x163914u;
    // 0x163914: 0xc058dc0  jal         func_163700
    ctx->pc = 0x163914u;
    SET_GPR_U32(ctx, 31, 0x16391Cu);
    ctx->pc = 0x163700u;
    if (runtime->hasFunction(0x163700u)) {
        auto targetFn = runtime->lookupFunction(0x163700u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x16391Cu; }
        if (ctx->pc != 0x16391Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00163700_0x163700(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x16391Cu; }
        if (ctx->pc != 0x16391Cu) { return; }
    }
    ctx->pc = 0x16391Cu;
label_16391c:
    // 0x16391c: 0x220202d  daddu       $a0, $s1, $zero
    ctx->pc = 0x16391cu;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
    // 0x163920: 0xc058ecc  jal         func_163B30
    ctx->pc = 0x163920u;
    SET_GPR_U32(ctx, 31, 0x163928u);
    ctx->pc = 0x163924u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x163920u;
            // 0x163924: 0x40802d  daddu       $s0, $v0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x163B30u;
    if (runtime->hasFunction(0x163B30u)) {
        auto targetFn = runtime->lookupFunction(0x163B30u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x163928u; }
        if (ctx->pc != 0x163928u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00163B30_0x163b30(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x163928u; }
        if (ctx->pc != 0x163928u) { return; }
    }
    ctx->pc = 0x163928u;
label_163928:
    // 0x163928: 0x14520002  bne         $v0, $s2, . + 4 + (0x2 << 2)
    ctx->pc = 0x163928u;
    {
        const bool branch_taken_0x163928 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 18));
        ctx->pc = 0x16392Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x163928u;
            // 0x16392c: 0x200202d  daddu       $a0, $s0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x163928) {
            ctx->pc = 0x163934u;
            goto label_163934;
        }
    }
    ctx->pc = 0x163930u;
    // 0x163930: 0xae200118  sw          $zero, 0x118($s1)
    ctx->pc = 0x163930u;
    WRITE32(ADD32(GPR_U32(ctx, 17), 280), GPR_U32(ctx, 0));
label_163934:
    // 0x163934: 0xc058dc8  jal         func_163720
    ctx->pc = 0x163934u;
    SET_GPR_U32(ctx, 31, 0x16393Cu);
    ctx->pc = 0x163720u;
    if (runtime->hasFunction(0x163720u)) {
        auto targetFn = runtime->lookupFunction(0x163720u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x16393Cu; }
        if (ctx->pc != 0x16393Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00163720_0x163720(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x16393Cu; }
        if (ctx->pc != 0x16393Cu) { return; }
    }
    ctx->pc = 0x16393Cu;
label_16393c:
    // 0x16393c: 0xc058e62  jal         func_163988
    ctx->pc = 0x16393Cu;
    SET_GPR_U32(ctx, 31, 0x163944u);
    ctx->pc = 0x163940u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x16393Cu;
            // 0x163940: 0x220202d  daddu       $a0, $s1, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x163988u;
    if (runtime->hasFunction(0x163988u)) {
        auto targetFn = runtime->lookupFunction(0x163988u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x163944u; }
        if (ctx->pc != 0x163944u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00163988_0x163988(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x163944u; }
        if (ctx->pc != 0x163944u) { return; }
    }
    ctx->pc = 0x163944u;
label_163944:
    // 0x163944: 0xc05d4be  jal         func_1752F8
    ctx->pc = 0x163944u;
    SET_GPR_U32(ctx, 31, 0x16394Cu);
    ctx->pc = 0x163948u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x163944u;
            // 0x163948: 0x260202d  daddu       $a0, $s3, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 19) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1752F8u;
    if (runtime->hasFunction(0x1752F8u)) {
        auto targetFn = runtime->lookupFunction(0x1752F8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x16394Cu; }
        if (ctx->pc != 0x16394Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001752F8_0x1752f8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x16394Cu; }
        if (ctx->pc != 0x16394Cu) { return; }
    }
    ctx->pc = 0x16394Cu;
label_16394c:
    // 0x16394c: 0x40182d  daddu       $v1, $v0, $zero
    ctx->pc = 0x16394cu;
    SET_GPR_U64(ctx, 3, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x163950: 0x24020004  addiu       $v0, $zero, 0x4
    ctx->pc = 0x163950u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4));
    // 0x163954: 0x10620003  beq         $v1, $v0, . + 4 + (0x3 << 2)
    ctx->pc = 0x163954u;
    {
        const bool branch_taken_0x163954 = (GPR_U64(ctx, 3) == GPR_U64(ctx, 2));
        ctx->pc = 0x163958u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x163954u;
            // 0x163958: 0x24040006  addiu       $a0, $zero, 0x6 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 6));
        ctx->in_delay_slot = false;
        if (branch_taken_0x163954) {
            ctx->pc = 0x163964u;
            goto label_163964;
        }
    }
    ctx->pc = 0x16395Cu;
    // 0x16395c: 0x14640004  bne         $v1, $a0, . + 4 + (0x4 << 2)
    ctx->pc = 0x16395Cu;
    {
        const bool branch_taken_0x16395c = (GPR_U64(ctx, 3) != GPR_U64(ctx, 4));
        ctx->pc = 0x163960u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x16395Cu;
            // 0x163960: 0xdfb00000  ld          $s0, 0x0($sp) (Delay Slot)
        SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x16395c) {
            ctx->pc = 0x163970u;
            goto label_163970;
        }
    }
    ctx->pc = 0x163964u;
label_163964:
    // 0x163964: 0x24020002  addiu       $v0, $zero, 0x2
    ctx->pc = 0x163964u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 2));
    // 0x163968: 0xae220008  sw          $v0, 0x8($s1)
    ctx->pc = 0x163968u;
    WRITE32(ADD32(GPR_U32(ctx, 17), 8), GPR_U32(ctx, 2));
    // 0x16396c: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x16396cu;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
label_163970:
    // 0x163970: 0xdfb10008  ld          $s1, 0x8($sp)
    ctx->pc = 0x163970u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x163974: 0xdfb20010  ld          $s2, 0x10($sp)
    ctx->pc = 0x163974u;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x163978: 0xdfb30018  ld          $s3, 0x18($sp)
    ctx->pc = 0x163978u;
    SET_GPR_U64(ctx, 19, READ64(ADD32(GPR_U32(ctx, 29), 24)));
    // 0x16397c: 0xdfbf0020  ld          $ra, 0x20($sp)
    ctx->pc = 0x16397cu;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x163980: 0x3e00008  jr          $ra
    ctx->pc = 0x163980u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x163984u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x163980u;
            // 0x163984: 0x27bd0030  addiu       $sp, $sp, 0x30 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 48));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x16391Cu: goto label_16391c;
            case 0x163928u: goto label_163928;
            case 0x163934u: goto label_163934;
            case 0x16393Cu: goto label_16393c;
            case 0x163944u: goto label_163944;
            case 0x16394Cu: goto label_16394c;
            case 0x163964u: goto label_163964;
            case 0x163970u: goto label_163970;
            default: break;
        }
        return;
    }
    ctx->pc = 0x163988u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
