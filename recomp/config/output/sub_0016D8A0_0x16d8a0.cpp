#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_0016D8A0
// Address: 0x16d8a0 - 0x16d960
void sub_0016D8A0_0x16d8a0(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_0016D8A0_0x16d8a0");
#endif

    switch (ctx->pc) {
        case 0x16d8f8u: goto label_16d8f8;
        case 0x16d914u: goto label_16d914;
        case 0x16d938u: goto label_16d938;
        default: break;
    }

    ctx->pc = 0x16d8a0u;

    // 0x16d8a0: 0x27bdffb0  addiu       $sp, $sp, -0x50
    ctx->pc = 0x16d8a0u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967216));
    // 0x16d8a4: 0x2402ffff  addiu       $v0, $zero, -0x1
    ctx->pc = 0x16d8a4u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
    // 0x16d8a8: 0xffb10018  sd          $s1, 0x18($sp)
    ctx->pc = 0x16d8a8u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 24), GPR_U64(ctx, 17));
    // 0x16d8ac: 0x80882d  daddu       $s1, $a0, $zero
    ctx->pc = 0x16d8acu;
    SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x16d8b0: 0xffb20020  sd          $s2, 0x20($sp)
    ctx->pc = 0x16d8b0u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 32), GPR_U64(ctx, 18));
    // 0x16d8b4: 0x100902d  daddu       $s2, $t0, $zero
    ctx->pc = 0x16d8b4u;
    SET_GPR_U64(ctx, 18, (uint64_t)GPR_U64(ctx, 8) + (uint64_t)GPR_U64(ctx, 0));
    // 0x16d8b8: 0xffb30028  sd          $s3, 0x28($sp)
    ctx->pc = 0x16d8b8u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 40), GPR_U64(ctx, 19));
    // 0x16d8bc: 0xa0982d  daddu       $s3, $a1, $zero
    ctx->pc = 0x16d8bcu;
    SET_GPR_U64(ctx, 19, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
    // 0x16d8c0: 0xffb40030  sd          $s4, 0x30($sp)
    ctx->pc = 0x16d8c0u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 48), GPR_U64(ctx, 20));
    // 0x16d8c4: 0xe0a02d  daddu       $s4, $a3, $zero
    ctx->pc = 0x16d8c4u;
    SET_GPR_U64(ctx, 20, (uint64_t)GPR_U64(ctx, 7) + (uint64_t)GPR_U64(ctx, 0));
    // 0x16d8c8: 0xffb00010  sd          $s0, 0x10($sp)
    ctx->pc = 0x16d8c8u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 16));
    // 0x16d8cc: 0x26271b28  addiu       $a3, $s1, 0x1B28
    ctx->pc = 0x16d8ccu;
    SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 17), 6952));
    // 0x16d8d0: 0xffb50038  sd          $s5, 0x38($sp)
    ctx->pc = 0x16d8d0u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 56), GPR_U64(ctx, 21));
    // 0x16d8d4: 0xc0182d  daddu       $v1, $a2, $zero
    ctx->pc = 0x16d8d4u;
    SET_GPR_U64(ctx, 3, (uint64_t)GPR_U64(ctx, 6) + (uint64_t)GPR_U64(ctx, 0));
    // 0x16d8d8: 0xffbf0040  sd          $ra, 0x40($sp)
    ctx->pc = 0x16d8d8u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 64), GPR_U64(ctx, 31));
    // 0x16d8dc: 0x24060004  addiu       $a2, $zero, 0x4
    ctx->pc = 0x16d8dcu;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 0), 4));
    // 0x16d8e0: 0x8cf50008  lw          $s5, 0x8($a3)
    ctx->pc = 0x16d8e0u;
    SET_GPR_S32(ctx, 21, (int32_t)READ32(ADD32(GPR_U32(ctx, 7), 8)));
    // 0x16d8e4: 0xae820000  sw          $v0, 0x0($s4)
    ctx->pc = 0x16d8e4u;
    WRITE32(ADD32(GPR_U32(ctx, 20), 0), GPR_U32(ctx, 2));
    // 0x16d8e8: 0x8c640000  lw          $a0, 0x0($v1)
    ctx->pc = 0x16d8e8u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 3), 0)));
    // 0x16d8ec: 0x8c650004  lw          $a1, 0x4($v1)
    ctx->pc = 0x16d8ecu;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 3), 4)));
    // 0x16d8f0: 0xc0561d4  jal         func_158750
    ctx->pc = 0x16D8F0u;
    SET_GPR_U32(ctx, 31, 0x16D8F8u);
    ctx->pc = 0x16D8F4u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x16D8F0u;
            // 0x16d8f4: 0x8cf00010  lw          $s0, 0x10($a3) (Delay Slot)
        SET_GPR_S32(ctx, 16, (int32_t)READ32(ADD32(GPR_U32(ctx, 7), 16)));
        ctx->in_delay_slot = false;
    ctx->pc = 0x158750u;
    if (runtime->hasFunction(0x158750u)) {
        auto targetFn = runtime->lookupFunction(0x158750u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x16D8F8u; }
        if (ctx->pc != 0x16D8F8u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00158750_0x158750(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x16D8F8u; }
        if (ctx->pc != 0x16D8F8u) { return; }
    }
    ctx->pc = 0x16D8F8u;
label_16d8f8:
    // 0x16d8f8: 0x220202d  daddu       $a0, $s1, $zero
    ctx->pc = 0x16d8f8u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
    // 0x16d8fc: 0x200282d  daddu       $a1, $s0, $zero
    ctx->pc = 0x16d8fcu;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x16d900: 0x40302d  daddu       $a2, $v0, $zero
    ctx->pc = 0x16d900u;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x16d904: 0x1040000d  beqz        $v0, . + 4 + (0xD << 2)
    ctx->pc = 0x16D904u;
    {
        const bool branch_taken_0x16d904 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x16D908u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x16D904u;
            // 0x16d908: 0x3a0382d  daddu       $a3, $sp, $zero (Delay Slot)
        SET_GPR_U64(ctx, 7, (uint64_t)GPR_U64(ctx, 29) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x16d904) {
            ctx->pc = 0x16D93Cu;
            goto label_16d93c;
        }
    }
    ctx->pc = 0x16D90Cu;
    // 0x16d90c: 0xc05d0ca  jal         func_174328
    ctx->pc = 0x16D90Cu;
    SET_GPR_U32(ctx, 31, 0x16D914u);
    ctx->pc = 0x174328u;
    if (runtime->hasFunction(0x174328u)) {
        auto targetFn = runtime->lookupFunction(0x174328u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x16D914u; }
        if (ctx->pc != 0x16D914u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00174328_0x174328(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x16D914u; }
        if (ctx->pc != 0x16D914u) { return; }
    }
    ctx->pc = 0x16D914u;
label_16d914:
    // 0x16d914: 0x26240cc0  addiu       $a0, $s1, 0xCC0
    ctx->pc = 0x16d914u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 17), 3264));
    // 0x16d918: 0x8fa20000  lw          $v0, 0x0($sp)
    ctx->pc = 0x16d918u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x16d91c: 0x240402d  daddu       $t0, $s2, $zero
    ctx->pc = 0x16d91cu;
    SET_GPR_U64(ctx, 8, (uint64_t)GPR_U64(ctx, 18) + (uint64_t)GPR_U64(ctx, 0));
    // 0x16d920: 0x26a500ec  addiu       $a1, $s5, 0xEC
    ctx->pc = 0x16d920u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 21), 236));
    // 0x16d924: 0x260302d  daddu       $a2, $s3, $zero
    ctx->pc = 0x16d924u;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 19) + (uint64_t)GPR_U64(ctx, 0));
    // 0x16d928: 0x4400004  bltz        $v0, . + 4 + (0x4 << 2)
    ctx->pc = 0x16D928u;
    {
        const bool branch_taken_0x16d928 = (GPR_S64(ctx, 2) < 0);
        ctx->pc = 0x16D92Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x16D928u;
            // 0x16d92c: 0x3a0382d  daddu       $a3, $sp, $zero (Delay Slot)
        SET_GPR_U64(ctx, 7, (uint64_t)GPR_U64(ctx, 29) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x16d928) {
            ctx->pc = 0x16D93Cu;
            goto label_16d93c;
        }
    }
    ctx->pc = 0x16D930u;
    // 0x16d930: 0xc05b662  jal         func_16D988
    ctx->pc = 0x16D930u;
    SET_GPR_U32(ctx, 31, 0x16D938u);
    ctx->pc = 0x16D988u;
    if (runtime->hasFunction(0x16D988u)) {
        auto targetFn = runtime->lookupFunction(0x16D988u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x16D938u; }
        if (ctx->pc != 0x16D938u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0016D988_0x16d988(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x16D938u; }
        if (ctx->pc != 0x16D938u) { return; }
    }
    ctx->pc = 0x16D938u;
label_16d938:
    // 0x16d938: 0xae820000  sw          $v0, 0x0($s4)
    ctx->pc = 0x16d938u;
    WRITE32(ADD32(GPR_U32(ctx, 20), 0), GPR_U32(ctx, 2));
label_16d93c:
    // 0x16d93c: 0xdfb00010  ld          $s0, 0x10($sp)
    ctx->pc = 0x16d93cu;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x16d940: 0xdfb10018  ld          $s1, 0x18($sp)
    ctx->pc = 0x16d940u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 24)));
    // 0x16d944: 0xdfb20020  ld          $s2, 0x20($sp)
    ctx->pc = 0x16d944u;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x16d948: 0xdfb30028  ld          $s3, 0x28($sp)
    ctx->pc = 0x16d948u;
    SET_GPR_U64(ctx, 19, READ64(ADD32(GPR_U32(ctx, 29), 40)));
    // 0x16d94c: 0xdfb40030  ld          $s4, 0x30($sp)
    ctx->pc = 0x16d94cu;
    SET_GPR_U64(ctx, 20, READ64(ADD32(GPR_U32(ctx, 29), 48)));
    // 0x16d950: 0xdfb50038  ld          $s5, 0x38($sp)
    ctx->pc = 0x16d950u;
    SET_GPR_U64(ctx, 21, READ64(ADD32(GPR_U32(ctx, 29), 56)));
    // 0x16d954: 0xdfbf0040  ld          $ra, 0x40($sp)
    ctx->pc = 0x16d954u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 64)));
    // 0x16d958: 0x3e00008  jr          $ra
    ctx->pc = 0x16D958u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x16D95Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x16D958u;
            // 0x16d95c: 0x27bd0050  addiu       $sp, $sp, 0x50 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 80));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x16D8F8u: goto label_16d8f8;
            case 0x16D914u: goto label_16d914;
            case 0x16D938u: goto label_16d938;
            case 0x16D93Cu: goto label_16d93c;
            default: break;
        }
        return;
    }
    ctx->pc = 0x16D960u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
