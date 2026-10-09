#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00129240
// Address: 0x129240 - 0x1292e0
void sub_00129240_0x129240(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00129240_0x129240");
#endif

    switch (ctx->pc) {
        case 0x129274u: goto label_129274;
        case 0x12927cu: goto label_12927c;
        case 0x129298u: goto label_129298;
        case 0x1292acu: goto label_1292ac;
        case 0x1292c4u: goto label_1292c4;
        default: break;
    }

    ctx->pc = 0x129240u;

    // 0x129240: 0x27bdffe0  addiu       $sp, $sp, -0x20
    ctx->pc = 0x129240u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967264));
    // 0x129244: 0x2408ffff  addiu       $t0, $zero, -0x1
    ctx->pc = 0x129244u;
    SET_GPR_S32(ctx, 8, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
    // 0x129248: 0xffb10008  sd          $s1, 0x8($sp)
    ctx->pc = 0x129248u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 8), GPR_U64(ctx, 17));
    // 0x12924c: 0xa0882d  daddu       $s1, $a1, $zero
    ctx->pc = 0x12924cu;
    SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
    // 0x129250: 0xffb20010  sd          $s2, 0x10($sp)
    ctx->pc = 0x129250u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 18));
    // 0x129254: 0x80902d  daddu       $s2, $a0, $zero
    ctx->pc = 0x129254u;
    SET_GPR_U64(ctx, 18, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x129258: 0x282d  daddu       $a1, $zero, $zero
    ctx->pc = 0x129258u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x12925c: 0x240302d  daddu       $a2, $s2, $zero
    ctx->pc = 0x12925cu;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 18) + (uint64_t)GPR_U64(ctx, 0));
    // 0x129260: 0x24040002  addiu       $a0, $zero, 0x2
    ctx->pc = 0x129260u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 2));
    // 0x129264: 0xffb00000  sd          $s0, 0x0($sp)
    ctx->pc = 0x129264u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x129268: 0xffbf0018  sd          $ra, 0x18($sp)
    ctx->pc = 0x129268u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 24), GPR_U64(ctx, 31));
    // 0x12926c: 0xc04a13e  jal         func_1284F8
    ctx->pc = 0x12926Cu;
    SET_GPR_U32(ctx, 31, 0x129274u);
    ctx->pc = 0x129270u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x12926Cu;
            // 0x129270: 0x220382d  daddu       $a3, $s1, $zero (Delay Slot)
        SET_GPR_U64(ctx, 7, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1284F8u;
    if (runtime->hasFunction(0x1284F8u)) {
        auto targetFn = runtime->lookupFunction(0x1284F8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x129274u; }
        if (ctx->pc != 0x129274u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001284F8_0x1284f8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x129274u; }
        if (ctx->pc != 0x129274u) { return; }
    }
    ctx->pc = 0x129274u;
label_129274:
    // 0x129274: 0xc04a3e0  jal         func_128F80
    ctx->pc = 0x129274u;
    SET_GPR_U32(ctx, 31, 0x12927Cu);
    ctx->pc = 0x128F80u;
    if (runtime->hasFunction(0x128F80u)) {
        auto targetFn = runtime->lookupFunction(0x128F80u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x12927Cu; }
        if (ctx->pc != 0x12927Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00128F80_0x128f80(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x12927Cu; }
        if (ctx->pc != 0x12927Cu) { return; }
    }
    ctx->pc = 0x12927Cu;
label_12927c:
    // 0x12927c: 0x240282d  daddu       $a1, $s2, $zero
    ctx->pc = 0x12927cu;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 18) + (uint64_t)GPR_U64(ctx, 0));
    // 0x129280: 0x40802d  daddu       $s0, $v0, $zero
    ctx->pc = 0x129280u;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x129284: 0x220302d  daddu       $a2, $s1, $zero
    ctx->pc = 0x129284u;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
    // 0x129288: 0x12000008  beqz        $s0, . + 4 + (0x8 << 2)
    ctx->pc = 0x129288u;
    {
        const bool branch_taken_0x129288 = (GPR_U64(ctx, 16) == GPR_U64(ctx, 0));
        ctx->pc = 0x12928Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x129288u;
            // 0x12928c: 0x200202d  daddu       $a0, $s0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x129288) {
            ctx->pc = 0x1292ACu;
            goto label_1292ac;
        }
    }
    ctx->pc = 0x129290u;
    // 0x129290: 0xc04a45a  jal         func_129168
    ctx->pc = 0x129290u;
    SET_GPR_U32(ctx, 31, 0x129298u);
    ctx->pc = 0x129168u;
    if (runtime->hasFunction(0x129168u)) {
        auto targetFn = runtime->lookupFunction(0x129168u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x129298u; }
        if (ctx->pc != 0x129298u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00129168_0x129168(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x129298u; }
        if (ctx->pc != 0x129298u) { return; }
    }
    ctx->pc = 0x129298u;
label_129298:
    // 0x129298: 0x4410005  bgez        $v0, . + 4 + (0x5 << 2)
    ctx->pc = 0x129298u;
    {
        const bool branch_taken_0x129298 = (GPR_S64(ctx, 2) >= 0);
        ctx->pc = 0x12929Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x129298u;
            // 0x12929c: 0x240302d  daddu       $a2, $s2, $zero (Delay Slot)
        SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 18) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x129298) {
            ctx->pc = 0x1292B0u;
            goto label_1292b0;
        }
    }
    ctx->pc = 0x1292A0u;
    // 0x1292a0: 0x200202d  daddu       $a0, $s0, $zero
    ctx->pc = 0x1292a0u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1292a4: 0xc04a4d4  jal         func_129350
    ctx->pc = 0x1292A4u;
    SET_GPR_U32(ctx, 31, 0x1292ACu);
    ctx->pc = 0x1292A8u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1292A4u;
            // 0x1292a8: 0x802d  daddu       $s0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x129350u;
    if (runtime->hasFunction(0x129350u)) {
        auto targetFn = runtime->lookupFunction(0x129350u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1292ACu; }
        if (ctx->pc != 0x1292ACu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00129350_0x129350(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1292ACu; }
        if (ctx->pc != 0x1292ACu) { return; }
    }
    ctx->pc = 0x1292ACu;
label_1292ac:
    // 0x1292ac: 0x240302d  daddu       $a2, $s2, $zero
    ctx->pc = 0x1292acu;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 18) + (uint64_t)GPR_U64(ctx, 0));
label_1292b0:
    // 0x1292b0: 0x220382d  daddu       $a3, $s1, $zero
    ctx->pc = 0x1292b0u;
    SET_GPR_U64(ctx, 7, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1292b4: 0x24040002  addiu       $a0, $zero, 0x2
    ctx->pc = 0x1292b4u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 2));
    // 0x1292b8: 0x24050001  addiu       $a1, $zero, 0x1
    ctx->pc = 0x1292b8u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x1292bc: 0xc04a13e  jal         func_1284F8
    ctx->pc = 0x1292BCu;
    SET_GPR_U32(ctx, 31, 0x1292C4u);
    ctx->pc = 0x1292C0u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1292BCu;
            // 0x1292c0: 0x2408ffff  addiu       $t0, $zero, -0x1 (Delay Slot)
        SET_GPR_S32(ctx, 8, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1284F8u;
    if (runtime->hasFunction(0x1284F8u)) {
        auto targetFn = runtime->lookupFunction(0x1284F8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1292C4u; }
        if (ctx->pc != 0x1292C4u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001284F8_0x1284f8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1292C4u; }
        if (ctx->pc != 0x1292C4u) { return; }
    }
    ctx->pc = 0x1292C4u;
label_1292c4:
    // 0x1292c4: 0x200102d  daddu       $v0, $s0, $zero
    ctx->pc = 0x1292c4u;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1292c8: 0xdfb10008  ld          $s1, 0x8($sp)
    ctx->pc = 0x1292c8u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x1292cc: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x1292ccu;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1292d0: 0xdfb20010  ld          $s2, 0x10($sp)
    ctx->pc = 0x1292d0u;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x1292d4: 0xdfbf0018  ld          $ra, 0x18($sp)
    ctx->pc = 0x1292d4u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 24)));
    // 0x1292d8: 0x3e00008  jr          $ra
    ctx->pc = 0x1292D8u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1292DCu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1292D8u;
            // 0x1292dc: 0x27bd0020  addiu       $sp, $sp, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x129274u: goto label_129274;
            case 0x12927Cu: goto label_12927c;
            case 0x129298u: goto label_129298;
            case 0x1292ACu: goto label_1292ac;
            case 0x1292B0u: goto label_1292b0;
            case 0x1292C4u: goto label_1292c4;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1292E0u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
