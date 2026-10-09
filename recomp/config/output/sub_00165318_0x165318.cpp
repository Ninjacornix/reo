#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00165318
// Address: 0x165318 - 0x1653c0
void sub_00165318_0x165318(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00165318_0x165318");
#endif

    switch (ctx->pc) {
        case 0x16534cu: goto label_16534c;
        case 0x165360u: goto label_165360;
        case 0x165370u: goto label_165370;
        default: break;
    }

    ctx->pc = 0x165318u;

    // 0x165318: 0x27bdffd0  addiu       $sp, $sp, -0x30
    ctx->pc = 0x165318u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967248));
    // 0x16531c: 0xffb10008  sd          $s1, 0x8($sp)
    ctx->pc = 0x16531cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 8), GPR_U64(ctx, 17));
    // 0x165320: 0x80882d  daddu       $s1, $a0, $zero
    ctx->pc = 0x165320u;
    SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x165324: 0xffb30018  sd          $s3, 0x18($sp)
    ctx->pc = 0x165324u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 24), GPR_U64(ctx, 19));
    // 0x165328: 0x24130001  addiu       $s3, $zero, 0x1
    ctx->pc = 0x165328u;
    SET_GPR_S32(ctx, 19, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x16532c: 0xffb00000  sd          $s0, 0x0($sp)
    ctx->pc = 0x16532cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x165330: 0x26221b6c  addiu       $v0, $s1, 0x1B6C
    ctx->pc = 0x165330u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 17), 7020));
    // 0x165334: 0xffb20010  sd          $s2, 0x10($sp)
    ctx->pc = 0x165334u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 18));
    // 0x165338: 0xffbf0020  sd          $ra, 0x20($sp)
    ctx->pc = 0x165338u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 32), GPR_U64(ctx, 31));
    // 0x16533c: 0x8c520014  lw          $s2, 0x14($v0)
    ctx->pc = 0x16533cu;
    SET_GPR_S32(ctx, 18, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 20)));
    // 0x165340: 0x8c500010  lw          $s0, 0x10($v0)
    ctx->pc = 0x165340u;
    SET_GPR_S32(ctx, 16, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 16)));
    // 0x165344: 0xc059f30  jal         func_167CC0
    ctx->pc = 0x165344u;
    SET_GPR_U32(ctx, 31, 0x16534Cu);
    ctx->pc = 0x165348u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x165344u;
            // 0x165348: 0x240282d  daddu       $a1, $s2, $zero (Delay Slot)
        SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 18) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x167CC0u;
    if (runtime->hasFunction(0x167CC0u)) {
        auto targetFn = runtime->lookupFunction(0x167CC0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x16534Cu; }
        if (ctx->pc != 0x16534Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00167CC0_0x167cc0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x16534Cu; }
        if (ctx->pc != 0x16534Cu) { return; }
    }
    ctx->pc = 0x16534Cu;
label_16534c:
    // 0x16534c: 0x220202d  daddu       $a0, $s1, $zero
    ctx->pc = 0x16534cu;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
    // 0x165350: 0x10530013  beq         $v0, $s3, . + 4 + (0x13 << 2)
    ctx->pc = 0x165350u;
    {
        const bool branch_taken_0x165350 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 19));
        ctx->pc = 0x165354u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x165350u;
            // 0x165354: 0x200282d  daddu       $a1, $s0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x165350) {
            ctx->pc = 0x1653A0u;
            goto label_1653a0;
        }
    }
    ctx->pc = 0x165358u;
    // 0x165358: 0xc059f30  jal         func_167CC0
    ctx->pc = 0x165358u;
    SET_GPR_U32(ctx, 31, 0x165360u);
    ctx->pc = 0x167CC0u;
    if (runtime->hasFunction(0x167CC0u)) {
        auto targetFn = runtime->lookupFunction(0x167CC0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x165360u; }
        if (ctx->pc != 0x165360u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00167CC0_0x167cc0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x165360u; }
        if (ctx->pc != 0x165360u) { return; }
    }
    ctx->pc = 0x165360u;
label_165360:
    // 0x165360: 0x54530010  bnel        $v0, $s3, . + 4 + (0x10 << 2)
    ctx->pc = 0x165360u;
    {
        const bool branch_taken_0x165360 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 19));
        if (branch_taken_0x165360) {
            ctx->pc = 0x165364u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x165360u;
            // 0x165364: 0xdfb00000  ld          $s0, 0x0($sp) (Delay Slot)
        SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
        ctx->in_delay_slot = false;
            ctx->pc = 0x1653A4u;
            goto label_1653a4;
        }
    }
    ctx->pc = 0x165368u;
    // 0x165368: 0xc0594f0  jal         func_1653C0
    ctx->pc = 0x165368u;
    SET_GPR_U32(ctx, 31, 0x165370u);
    ctx->pc = 0x16536Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x165368u;
            // 0x16536c: 0x220202d  daddu       $a0, $s1, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1653C0u;
    if (runtime->hasFunction(0x1653C0u)) {
        auto targetFn = runtime->lookupFunction(0x1653C0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x165370u; }
        if (ctx->pc != 0x165370u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001653C0_0x1653c0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x165370u; }
        if (ctx->pc != 0x165370u) { return; }
    }
    ctx->pc = 0x165370u;
label_165370:
    // 0x165370: 0x1040000b  beqz        $v0, . + 4 + (0xB << 2)
    ctx->pc = 0x165370u;
    {
        const bool branch_taken_0x165370 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x165374u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x165370u;
            // 0x165374: 0x220202d  daddu       $a0, $s1, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x165370) {
            ctx->pc = 0x1653A0u;
            goto label_1653a0;
        }
    }
    ctx->pc = 0x165378u;
    // 0x165378: 0x240282d  daddu       $a1, $s2, $zero
    ctx->pc = 0x165378u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 18) + (uint64_t)GPR_U64(ctx, 0));
    // 0x16537c: 0xdfb20010  ld          $s2, 0x10($sp)
    ctx->pc = 0x16537cu;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x165380: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x165380u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x165384: 0x24060001  addiu       $a2, $zero, 0x1
    ctx->pc = 0x165384u;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x165388: 0xdfb10008  ld          $s1, 0x8($sp)
    ctx->pc = 0x165388u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x16538c: 0xdfb30018  ld          $s3, 0x18($sp)
    ctx->pc = 0x16538cu;
    SET_GPR_U64(ctx, 19, READ64(ADD32(GPR_U32(ctx, 29), 24)));
    // 0x165390: 0xdfbf0020  ld          $ra, 0x20($sp)
    ctx->pc = 0x165390u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x165394: 0x8059f28  j           func_167CA0
    ctx->pc = 0x165394u;
    ctx->pc = 0x165398u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x165394u;
            // 0x165398: 0x27bd0030  addiu       $sp, $sp, 0x30 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 48));
        ctx->in_delay_slot = false;
    ctx->pc = 0x167CA0u;
    if (runtime->hasFunction(0x167CA0u)) {
        auto targetFn = runtime->lookupFunction(0x167CA0u);
        targetFn(rdram, ctx, runtime); return;
    } else {
        sub_00167CA0_0x167ca0(rdram, ctx, runtime); return;
    }
    ctx->pc = 0x16539Cu;
    // 0x16539c: 0x0  nop
    ctx->pc = 0x16539cu;
    // NOP
label_1653a0:
    // 0x1653a0: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x1653a0u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
label_1653a4:
    // 0x1653a4: 0xdfb10008  ld          $s1, 0x8($sp)
    ctx->pc = 0x1653a4u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x1653a8: 0xdfb20010  ld          $s2, 0x10($sp)
    ctx->pc = 0x1653a8u;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x1653ac: 0xdfb30018  ld          $s3, 0x18($sp)
    ctx->pc = 0x1653acu;
    SET_GPR_U64(ctx, 19, READ64(ADD32(GPR_U32(ctx, 29), 24)));
    // 0x1653b0: 0xdfbf0020  ld          $ra, 0x20($sp)
    ctx->pc = 0x1653b0u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x1653b4: 0x3e00008  jr          $ra
    ctx->pc = 0x1653B4u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1653B8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1653B4u;
            // 0x1653b8: 0x27bd0030  addiu       $sp, $sp, 0x30 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 48));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x16534Cu: goto label_16534c;
            case 0x165360u: goto label_165360;
            case 0x165370u: goto label_165370;
            case 0x1653A0u: goto label_1653a0;
            case 0x1653A4u: goto label_1653a4;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1653BCu;
    // 0x1653bc: 0x0  nop
    ctx->pc = 0x1653bcu;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
