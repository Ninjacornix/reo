#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001290C8
// Address: 0x1290c8 - 0x129168
void sub_001290C8_0x1290c8(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001290C8_0x1290c8");
#endif

    switch (ctx->pc) {
        case 0x1290fcu: goto label_1290fc;
        case 0x129104u: goto label_129104;
        case 0x129120u: goto label_129120;
        case 0x129134u: goto label_129134;
        case 0x12914cu: goto label_12914c;
        default: break;
    }

    ctx->pc = 0x1290c8u;

    // 0x1290c8: 0x27bdffe0  addiu       $sp, $sp, -0x20
    ctx->pc = 0x1290c8u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967264));
    // 0x1290cc: 0x2408ffff  addiu       $t0, $zero, -0x1
    ctx->pc = 0x1290ccu;
    SET_GPR_S32(ctx, 8, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
    // 0x1290d0: 0xffb10008  sd          $s1, 0x8($sp)
    ctx->pc = 0x1290d0u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 8), GPR_U64(ctx, 17));
    // 0x1290d4: 0xa0882d  daddu       $s1, $a1, $zero
    ctx->pc = 0x1290d4u;
    SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1290d8: 0xffb20010  sd          $s2, 0x10($sp)
    ctx->pc = 0x1290d8u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 18));
    // 0x1290dc: 0x80902d  daddu       $s2, $a0, $zero
    ctx->pc = 0x1290dcu;
    SET_GPR_U64(ctx, 18, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1290e0: 0x282d  daddu       $a1, $zero, $zero
    ctx->pc = 0x1290e0u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1290e4: 0x240302d  daddu       $a2, $s2, $zero
    ctx->pc = 0x1290e4u;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 18) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1290e8: 0x24040001  addiu       $a0, $zero, 0x1
    ctx->pc = 0x1290e8u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x1290ec: 0xffb00000  sd          $s0, 0x0($sp)
    ctx->pc = 0x1290ecu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x1290f0: 0xffbf0018  sd          $ra, 0x18($sp)
    ctx->pc = 0x1290f0u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 24), GPR_U64(ctx, 31));
    // 0x1290f4: 0xc04a13e  jal         func_1284F8
    ctx->pc = 0x1290F4u;
    SET_GPR_U32(ctx, 31, 0x1290FCu);
    ctx->pc = 0x1290F8u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1290F4u;
            // 0x1290f8: 0x220382d  daddu       $a3, $s1, $zero (Delay Slot)
        SET_GPR_U64(ctx, 7, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1284F8u;
    if (runtime->hasFunction(0x1284F8u)) {
        auto targetFn = runtime->lookupFunction(0x1284F8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1290FCu; }
        if (ctx->pc != 0x1290FCu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001284F8_0x1284f8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1290FCu; }
        if (ctx->pc != 0x1290FCu) { return; }
    }
    ctx->pc = 0x1290FCu;
label_1290fc:
    // 0x1290fc: 0xc04a3e0  jal         func_128F80
    ctx->pc = 0x1290FCu;
    SET_GPR_U32(ctx, 31, 0x129104u);
    ctx->pc = 0x128F80u;
    if (runtime->hasFunction(0x128F80u)) {
        auto targetFn = runtime->lookupFunction(0x128F80u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x129104u; }
        if (ctx->pc != 0x129104u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00128F80_0x128f80(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x129104u; }
        if (ctx->pc != 0x129104u) { return; }
    }
    ctx->pc = 0x129104u;
label_129104:
    // 0x129104: 0x240282d  daddu       $a1, $s2, $zero
    ctx->pc = 0x129104u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 18) + (uint64_t)GPR_U64(ctx, 0));
    // 0x129108: 0x40802d  daddu       $s0, $v0, $zero
    ctx->pc = 0x129108u;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x12910c: 0x220302d  daddu       $a2, $s1, $zero
    ctx->pc = 0x12910cu;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
    // 0x129110: 0x12000008  beqz        $s0, . + 4 + (0x8 << 2)
    ctx->pc = 0x129110u;
    {
        const bool branch_taken_0x129110 = (GPR_U64(ctx, 16) == GPR_U64(ctx, 0));
        ctx->pc = 0x129114u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x129110u;
            // 0x129114: 0x200202d  daddu       $a0, $s0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x129110) {
            ctx->pc = 0x129134u;
            goto label_129134;
        }
    }
    ctx->pc = 0x129118u;
    // 0x129118: 0xc04a404  jal         func_129010
    ctx->pc = 0x129118u;
    SET_GPR_U32(ctx, 31, 0x129120u);
    ctx->pc = 0x129010u;
    if (runtime->hasFunction(0x129010u)) {
        auto targetFn = runtime->lookupFunction(0x129010u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x129120u; }
        if (ctx->pc != 0x129120u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00129010_0x129010(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x129120u; }
        if (ctx->pc != 0x129120u) { return; }
    }
    ctx->pc = 0x129120u;
label_129120:
    // 0x129120: 0x4410005  bgez        $v0, . + 4 + (0x5 << 2)
    ctx->pc = 0x129120u;
    {
        const bool branch_taken_0x129120 = (GPR_S64(ctx, 2) >= 0);
        ctx->pc = 0x129124u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x129120u;
            // 0x129124: 0x240302d  daddu       $a2, $s2, $zero (Delay Slot)
        SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 18) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x129120) {
            ctx->pc = 0x129138u;
            goto label_129138;
        }
    }
    ctx->pc = 0x129128u;
    // 0x129128: 0x200202d  daddu       $a0, $s0, $zero
    ctx->pc = 0x129128u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x12912c: 0xc04a4d4  jal         func_129350
    ctx->pc = 0x12912Cu;
    SET_GPR_U32(ctx, 31, 0x129134u);
    ctx->pc = 0x129130u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x12912Cu;
            // 0x129130: 0x802d  daddu       $s0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x129350u;
    if (runtime->hasFunction(0x129350u)) {
        auto targetFn = runtime->lookupFunction(0x129350u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x129134u; }
        if (ctx->pc != 0x129134u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00129350_0x129350(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x129134u; }
        if (ctx->pc != 0x129134u) { return; }
    }
    ctx->pc = 0x129134u;
label_129134:
    // 0x129134: 0x240302d  daddu       $a2, $s2, $zero
    ctx->pc = 0x129134u;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 18) + (uint64_t)GPR_U64(ctx, 0));
label_129138:
    // 0x129138: 0x220382d  daddu       $a3, $s1, $zero
    ctx->pc = 0x129138u;
    SET_GPR_U64(ctx, 7, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
    // 0x12913c: 0x24040001  addiu       $a0, $zero, 0x1
    ctx->pc = 0x12913cu;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x129140: 0x24050001  addiu       $a1, $zero, 0x1
    ctx->pc = 0x129140u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x129144: 0xc04a13e  jal         func_1284F8
    ctx->pc = 0x129144u;
    SET_GPR_U32(ctx, 31, 0x12914Cu);
    ctx->pc = 0x129148u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x129144u;
            // 0x129148: 0x2408ffff  addiu       $t0, $zero, -0x1 (Delay Slot)
        SET_GPR_S32(ctx, 8, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1284F8u;
    if (runtime->hasFunction(0x1284F8u)) {
        auto targetFn = runtime->lookupFunction(0x1284F8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x12914Cu; }
        if (ctx->pc != 0x12914Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001284F8_0x1284f8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x12914Cu; }
        if (ctx->pc != 0x12914Cu) { return; }
    }
    ctx->pc = 0x12914Cu;
label_12914c:
    // 0x12914c: 0x200102d  daddu       $v0, $s0, $zero
    ctx->pc = 0x12914cu;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x129150: 0xdfb10008  ld          $s1, 0x8($sp)
    ctx->pc = 0x129150u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x129154: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x129154u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x129158: 0xdfb20010  ld          $s2, 0x10($sp)
    ctx->pc = 0x129158u;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x12915c: 0xdfbf0018  ld          $ra, 0x18($sp)
    ctx->pc = 0x12915cu;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 24)));
    // 0x129160: 0x3e00008  jr          $ra
    ctx->pc = 0x129160u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x129164u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x129160u;
            // 0x129164: 0x27bd0020  addiu       $sp, $sp, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1290FCu: goto label_1290fc;
            case 0x129104u: goto label_129104;
            case 0x129120u: goto label_129120;
            case 0x129134u: goto label_129134;
            case 0x129138u: goto label_129138;
            case 0x12914Cu: goto label_12914c;
            default: break;
        }
        return;
    }
    ctx->pc = 0x129168u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
