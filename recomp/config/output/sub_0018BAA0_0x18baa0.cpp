#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_0018BAA0
// Address: 0x18baa0 - 0x18bc70
void sub_0018BAA0_0x18baa0(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_0018BAA0_0x18baa0");
#endif

    switch (ctx->pc) {
        case 0x18bb04u: goto label_18bb04;
        case 0x18bb24u: goto label_18bb24;
        case 0x18bb4cu: goto label_18bb4c;
        case 0x18bb6cu: goto label_18bb6c;
        case 0x18bb94u: goto label_18bb94;
        case 0x18bbb4u: goto label_18bbb4;
        case 0x18bbdcu: goto label_18bbdc;
        case 0x18bc2cu: goto label_18bc2c;
        default: break;
    }

    ctx->pc = 0x18baa0u;

    // 0x18baa0: 0x27bdff70  addiu       $sp, $sp, -0x90
    ctx->pc = 0x18baa0u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967152));
    // 0x18baa4: 0x3c030023  lui         $v1, 0x23
    ctx->pc = 0x18baa4u;
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)35 << 16));
    // 0x18baa8: 0xffbf0080  sd          $ra, 0x80($sp)
    ctx->pc = 0x18baa8u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 128), GPR_U64(ctx, 31));
    // 0x18baac: 0x2463fd40  addiu       $v1, $v1, -0x2C0
    ctx->pc = 0x18baacu;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 4294966592));
    // 0x18bab0: 0x7fb40070  sq          $s4, 0x70($sp)
    ctx->pc = 0x18bab0u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 112), GPR_VEC(ctx, 20));
    // 0x18bab4: 0x2ca10006  sltiu       $at, $a1, 0x6
    ctx->pc = 0x18bab4u;
    SET_GPR_U64(ctx, 1, ((uint64_t)GPR_U64(ctx, 5) < (uint64_t)(int64_t)(int32_t)6) ? 1 : 0);
    // 0x18bab8: 0x7fb30060  sq          $s3, 0x60($sp)
    ctx->pc = 0x18bab8u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 96), GPR_VEC(ctx, 19));
    // 0x18babc: 0x80a02d  daddu       $s4, $a0, $zero
    ctx->pc = 0x18babcu;
    SET_GPR_U64(ctx, 20, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x18bac0: 0x7fb20050  sq          $s2, 0x50($sp)
    ctx->pc = 0x18bac0u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 80), GPR_VEC(ctx, 18));
    // 0x18bac4: 0x52080  sll         $a0, $a1, 2
    ctx->pc = 0x18bac4u;
    SET_GPR_S32(ctx, 4, (int32_t)SLL32(GPR_U32(ctx, 5), 2));
    // 0x18bac8: 0x7fb10040  sq          $s1, 0x40($sp)
    ctx->pc = 0x18bac8u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 64), GPR_VEC(ctx, 17));
    // 0x18bacc: 0x641821  addu        $v1, $v1, $a0
    ctx->pc = 0x18baccu;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 4)));
    // 0x18bad0: 0x7fb00030  sq          $s0, 0x30($sp)
    ctx->pc = 0x18bad0u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 48), GPR_VEC(ctx, 16));
    // 0x18bad4: 0xc0982d  daddu       $s3, $a2, $zero
    ctx->pc = 0x18bad4u;
    SET_GPR_U64(ctx, 19, (uint64_t)GPR_U64(ctx, 6) + (uint64_t)GPR_U64(ctx, 0));
    // 0x18bad8: 0x8c710000  lw          $s1, 0x0($v1)
    ctx->pc = 0x18bad8u;
    SET_GPR_S32(ctx, 17, (int32_t)READ32(ADD32(GPR_U32(ctx, 3), 0)));
    // 0x18badc: 0x10200059  beqz        $at, . + 4 + (0x59 << 2)
    ctx->pc = 0x18BADCu;
    {
        const bool branch_taken_0x18badc = (GPR_U64(ctx, 1) == GPR_U64(ctx, 0));
        ctx->pc = 0x18BAE0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x18BADCu;
            // 0x18bae0: 0xe0902d  daddu       $s2, $a3, $zero (Delay Slot)
        SET_GPR_U64(ctx, 18, (uint64_t)GPR_U64(ctx, 7) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x18badc) {
            ctx->pc = 0x18BC44u;
            goto label_18bc44;
        }
    }
    ctx->pc = 0x18BAE4u;
    // 0x18bae4: 0x3c030024  lui         $v1, 0x24
    ctx->pc = 0x18bae4u;
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)36 << 16));
    // 0x18bae8: 0x24631bd0  addiu       $v1, $v1, 0x1BD0
    ctx->pc = 0x18bae8u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 7120));
    // 0x18baec: 0x831821  addu        $v1, $a0, $v1
    ctx->pc = 0x18baecu;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 4), GPR_U32(ctx, 3)));
    // 0x18baf0: 0x8c630000  lw          $v1, 0x0($v1)
    ctx->pc = 0x18baf0u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 3), 0)));
    // 0x18baf4: 0x600008  jr          $v1
    ctx->pc = 0x18BAF4u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 3);
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x18BAFCu: goto label_18bafc;
            case 0x18BB44u: goto label_18bb44;
            case 0x18BB8Cu: goto label_18bb8c;
            case 0x18BBD4u: goto label_18bbd4;
            case 0x18BC44u: goto label_18bc44;
            default: break;
        }
        return;
    }
    ctx->pc = 0x18BAFCu;
label_18bafc:
    // 0x18bafc: 0x1000000c  b           . + 4 + (0xC << 2)
    ctx->pc = 0x18BAFCu;
    {
        const bool branch_taken_0x18bafc = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x18BB00u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x18BAFCu;
            // 0x18bb00: 0x802d  daddu       $s0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x18bafc) {
            ctx->pc = 0x18BB30u;
            goto label_18bb30;
        }
    }
    ctx->pc = 0x18BB04u;
label_18bb04:
    // 0x18bb04: 0x8e440000  lw          $a0, 0x0($s2)
    ctx->pc = 0x18bb04u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 18), 0)));
    // 0x18bb08: 0x26650040  addiu       $a1, $s3, 0x40
    ctx->pc = 0x18bb08u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 19), 64));
    // 0x18bb0c: 0x26660050  addiu       $a2, $s3, 0x50
    ctx->pc = 0x18bb0cu;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 19), 80));
    // 0x18bb10: 0x26670060  addiu       $a3, $s3, 0x60
    ctx->pc = 0x18bb10u;
    SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 19), 96));
    // 0x18bb14: 0x26680070  addiu       $t0, $s3, 0x70
    ctx->pc = 0x18bb14u;
    SET_GPR_S32(ctx, 8, (int32_t)ADD32(GPR_U32(ctx, 19), 112));
    // 0x18bb18: 0x26690080  addiu       $t1, $s3, 0x80
    ctx->pc = 0x18bb18u;
    SET_GPR_S32(ctx, 9, (int32_t)ADD32(GPR_U32(ctx, 19), 128));
    // 0x18bb1c: 0xc062f1c  jal         func_18BC70
    ctx->pc = 0x18BB1Cu;
    SET_GPR_U32(ctx, 31, 0x18BB24u);
    ctx->pc = 0x18BB20u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x18BB1Cu;
            // 0x18bb20: 0x266a0090  addiu       $t2, $s3, 0x90 (Delay Slot)
        SET_GPR_S32(ctx, 10, (int32_t)ADD32(GPR_U32(ctx, 19), 144));
        ctx->in_delay_slot = false;
    ctx->pc = 0x18BC70u;
    if (runtime->hasFunction(0x18BC70u)) {
        auto targetFn = runtime->lookupFunction(0x18BC70u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x18BB24u; }
        if (ctx->pc != 0x18BB24u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0018BC70_0x18bc70(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x18BB24u; }
        if (ctx->pc != 0x18BB24u) { return; }
    }
    ctx->pc = 0x18BB24u;
label_18bb24:
    // 0x18bb24: 0x2719821  addu        $s3, $s3, $s1
    ctx->pc = 0x18bb24u;
    SET_GPR_S32(ctx, 19, (int32_t)ADD32(GPR_U32(ctx, 19), GPR_U32(ctx, 17)));
    // 0x18bb28: 0x26520004  addiu       $s2, $s2, 0x4
    ctx->pc = 0x18bb28u;
    SET_GPR_S32(ctx, 18, (int32_t)ADD32(GPR_U32(ctx, 18), 4));
    // 0x18bb2c: 0x26100001  addiu       $s0, $s0, 0x1
    ctx->pc = 0x18bb2cu;
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 16), 1));
label_18bb30:
    // 0x18bb30: 0x214182a  slt         $v1, $s0, $s4
    ctx->pc = 0x18bb30u;
    SET_GPR_U64(ctx, 3, ((int64_t)GPR_S64(ctx, 16) < (int64_t)GPR_S64(ctx, 20)) ? 1 : 0);
    // 0x18bb34: 0x1460fff3  bnez        $v1, . + 4 + (-0xD << 2)
    ctx->pc = 0x18BB34u;
    {
        const bool branch_taken_0x18bb34 = (GPR_U64(ctx, 3) != GPR_U64(ctx, 0));
        if (branch_taken_0x18bb34) {
            ctx->pc = 0x18BB04u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_18bb04;
        }
    }
    ctx->pc = 0x18BB3Cu;
    // 0x18bb3c: 0x10000042  b           . + 4 + (0x42 << 2)
    ctx->pc = 0x18BB3Cu;
    {
        const bool branch_taken_0x18bb3c = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x18BB40u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x18BB3Cu;
            // 0x18bb40: 0xdfbf0080  ld          $ra, 0x80($sp) (Delay Slot)
        SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 128)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x18bb3c) {
            ctx->pc = 0x18BC48u;
            goto label_18bc48;
        }
    }
    ctx->pc = 0x18BB44u;
label_18bb44:
    // 0x18bb44: 0x1000000c  b           . + 4 + (0xC << 2)
    ctx->pc = 0x18BB44u;
    {
        const bool branch_taken_0x18bb44 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x18BB48u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x18BB44u;
            // 0x18bb48: 0x802d  daddu       $s0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x18bb44) {
            ctx->pc = 0x18BB78u;
            goto label_18bb78;
        }
    }
    ctx->pc = 0x18BB4Cu;
label_18bb4c:
    // 0x18bb4c: 0x8e440000  lw          $a0, 0x0($s2)
    ctx->pc = 0x18bb4cu;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 18), 0)));
    // 0x18bb50: 0x26650040  addiu       $a1, $s3, 0x40
    ctx->pc = 0x18bb50u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 19), 64));
    // 0x18bb54: 0x26660050  addiu       $a2, $s3, 0x50
    ctx->pc = 0x18bb54u;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 19), 80));
    // 0x18bb58: 0x26670060  addiu       $a3, $s3, 0x60
    ctx->pc = 0x18bb58u;
    SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 19), 96));
    // 0x18bb5c: 0x26680070  addiu       $t0, $s3, 0x70
    ctx->pc = 0x18bb5cu;
    SET_GPR_S32(ctx, 8, (int32_t)ADD32(GPR_U32(ctx, 19), 112));
    // 0x18bb60: 0x26690080  addiu       $t1, $s3, 0x80
    ctx->pc = 0x18bb60u;
    SET_GPR_S32(ctx, 9, (int32_t)ADD32(GPR_U32(ctx, 19), 128));
    // 0x18bb64: 0xc062f1c  jal         func_18BC70
    ctx->pc = 0x18BB64u;
    SET_GPR_U32(ctx, 31, 0x18BB6Cu);
    ctx->pc = 0x18BB68u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x18BB64u;
            // 0x18bb68: 0x266a0090  addiu       $t2, $s3, 0x90 (Delay Slot)
        SET_GPR_S32(ctx, 10, (int32_t)ADD32(GPR_U32(ctx, 19), 144));
        ctx->in_delay_slot = false;
    ctx->pc = 0x18BC70u;
    if (runtime->hasFunction(0x18BC70u)) {
        auto targetFn = runtime->lookupFunction(0x18BC70u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x18BB6Cu; }
        if (ctx->pc != 0x18BB6Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0018BC70_0x18bc70(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x18BB6Cu; }
        if (ctx->pc != 0x18BB6Cu) { return; }
    }
    ctx->pc = 0x18BB6Cu;
label_18bb6c:
    // 0x18bb6c: 0x2719821  addu        $s3, $s3, $s1
    ctx->pc = 0x18bb6cu;
    SET_GPR_S32(ctx, 19, (int32_t)ADD32(GPR_U32(ctx, 19), GPR_U32(ctx, 17)));
    // 0x18bb70: 0x26520004  addiu       $s2, $s2, 0x4
    ctx->pc = 0x18bb70u;
    SET_GPR_S32(ctx, 18, (int32_t)ADD32(GPR_U32(ctx, 18), 4));
    // 0x18bb74: 0x26100001  addiu       $s0, $s0, 0x1
    ctx->pc = 0x18bb74u;
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 16), 1));
label_18bb78:
    // 0x18bb78: 0x214182a  slt         $v1, $s0, $s4
    ctx->pc = 0x18bb78u;
    SET_GPR_U64(ctx, 3, ((int64_t)GPR_S64(ctx, 16) < (int64_t)GPR_S64(ctx, 20)) ? 1 : 0);
    // 0x18bb7c: 0x1460fff3  bnez        $v1, . + 4 + (-0xD << 2)
    ctx->pc = 0x18BB7Cu;
    {
        const bool branch_taken_0x18bb7c = (GPR_U64(ctx, 3) != GPR_U64(ctx, 0));
        if (branch_taken_0x18bb7c) {
            ctx->pc = 0x18BB4Cu;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_18bb4c;
        }
    }
    ctx->pc = 0x18BB84u;
    // 0x18bb84: 0x1000002f  b           . + 4 + (0x2F << 2)
    ctx->pc = 0x18BB84u;
    {
        const bool branch_taken_0x18bb84 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x18bb84) {
            ctx->pc = 0x18BC44u;
            goto label_18bc44;
        }
    }
    ctx->pc = 0x18BB8Cu;
label_18bb8c:
    // 0x18bb8c: 0x1000000c  b           . + 4 + (0xC << 2)
    ctx->pc = 0x18BB8Cu;
    {
        const bool branch_taken_0x18bb8c = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x18BB90u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x18BB8Cu;
            // 0x18bb90: 0x802d  daddu       $s0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x18bb8c) {
            ctx->pc = 0x18BBC0u;
            goto label_18bbc0;
        }
    }
    ctx->pc = 0x18BB94u;
label_18bb94:
    // 0x18bb94: 0x8e440000  lw          $a0, 0x0($s2)
    ctx->pc = 0x18bb94u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 18), 0)));
    // 0x18bb98: 0x26650040  addiu       $a1, $s3, 0x40
    ctx->pc = 0x18bb98u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 19), 64));
    // 0x18bb9c: 0x26660050  addiu       $a2, $s3, 0x50
    ctx->pc = 0x18bb9cu;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 19), 80));
    // 0x18bba0: 0x26670060  addiu       $a3, $s3, 0x60
    ctx->pc = 0x18bba0u;
    SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 19), 96));
    // 0x18bba4: 0x26680070  addiu       $t0, $s3, 0x70
    ctx->pc = 0x18bba4u;
    SET_GPR_S32(ctx, 8, (int32_t)ADD32(GPR_U32(ctx, 19), 112));
    // 0x18bba8: 0x26690080  addiu       $t1, $s3, 0x80
    ctx->pc = 0x18bba8u;
    SET_GPR_S32(ctx, 9, (int32_t)ADD32(GPR_U32(ctx, 19), 128));
    // 0x18bbac: 0xc062f1c  jal         func_18BC70
    ctx->pc = 0x18BBACu;
    SET_GPR_U32(ctx, 31, 0x18BBB4u);
    ctx->pc = 0x18BBB0u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x18BBACu;
            // 0x18bbb0: 0x266a0090  addiu       $t2, $s3, 0x90 (Delay Slot)
        SET_GPR_S32(ctx, 10, (int32_t)ADD32(GPR_U32(ctx, 19), 144));
        ctx->in_delay_slot = false;
    ctx->pc = 0x18BC70u;
    if (runtime->hasFunction(0x18BC70u)) {
        auto targetFn = runtime->lookupFunction(0x18BC70u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x18BBB4u; }
        if (ctx->pc != 0x18BBB4u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0018BC70_0x18bc70(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x18BBB4u; }
        if (ctx->pc != 0x18BBB4u) { return; }
    }
    ctx->pc = 0x18BBB4u;
label_18bbb4:
    // 0x18bbb4: 0x2719821  addu        $s3, $s3, $s1
    ctx->pc = 0x18bbb4u;
    SET_GPR_S32(ctx, 19, (int32_t)ADD32(GPR_U32(ctx, 19), GPR_U32(ctx, 17)));
    // 0x18bbb8: 0x26520004  addiu       $s2, $s2, 0x4
    ctx->pc = 0x18bbb8u;
    SET_GPR_S32(ctx, 18, (int32_t)ADD32(GPR_U32(ctx, 18), 4));
    // 0x18bbbc: 0x26100001  addiu       $s0, $s0, 0x1
    ctx->pc = 0x18bbbcu;
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 16), 1));
label_18bbc0:
    // 0x18bbc0: 0x214182a  slt         $v1, $s0, $s4
    ctx->pc = 0x18bbc0u;
    SET_GPR_U64(ctx, 3, ((int64_t)GPR_S64(ctx, 16) < (int64_t)GPR_S64(ctx, 20)) ? 1 : 0);
    // 0x18bbc4: 0x1460fff3  bnez        $v1, . + 4 + (-0xD << 2)
    ctx->pc = 0x18BBC4u;
    {
        const bool branch_taken_0x18bbc4 = (GPR_U64(ctx, 3) != GPR_U64(ctx, 0));
        if (branch_taken_0x18bbc4) {
            ctx->pc = 0x18BB94u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_18bb94;
        }
    }
    ctx->pc = 0x18BBCCu;
    // 0x18bbcc: 0x1000001d  b           . + 4 + (0x1D << 2)
    ctx->pc = 0x18BBCCu;
    {
        const bool branch_taken_0x18bbcc = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x18bbcc) {
            ctx->pc = 0x18BC44u;
            goto label_18bc44;
        }
    }
    ctx->pc = 0x18BBD4u;
label_18bbd4:
    // 0x18bbd4: 0x10000018  b           . + 4 + (0x18 << 2)
    ctx->pc = 0x18BBD4u;
    {
        const bool branch_taken_0x18bbd4 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x18BBD8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x18BBD4u;
            // 0x18bbd8: 0x802d  daddu       $s0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x18bbd4) {
            ctx->pc = 0x18BC38u;
            goto label_18bc38;
        }
    }
    ctx->pc = 0x18BBDCu;
label_18bbdc:
    // 0x18bbdc: 0x266200a0  addiu       $v0, $s3, 0xA0
    ctx->pc = 0x18bbdcu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 19), 160));
    // 0x18bbe0: 0x266300b0  addiu       $v1, $s3, 0xB0
    ctx->pc = 0x18bbe0u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 19), 176));
    // 0x18bbe4: 0xffa20000  sd          $v0, 0x0($sp)
    ctx->pc = 0x18bbe4u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 2));
    // 0x18bbe8: 0x3c010029  lui         $at, 0x29
    ctx->pc = 0x18bbe8u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)41 << 16));
    // 0x18bbec: 0xffa30008  sd          $v1, 0x8($sp)
    ctx->pc = 0x18bbecu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 8), GPR_U64(ctx, 3));
    // 0x18bbf0: 0x266200c0  addiu       $v0, $s3, 0xC0
    ctx->pc = 0x18bbf0u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 19), 192));
    // 0x18bbf4: 0xffa20010  sd          $v0, 0x10($sp)
    ctx->pc = 0x18bbf4u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 2));
    // 0x18bbf8: 0x266300d0  addiu       $v1, $s3, 0xD0
    ctx->pc = 0x18bbf8u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 19), 208));
    // 0x18bbfc: 0x266200e0  addiu       $v0, $s3, 0xE0
    ctx->pc = 0x18bbfcu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 19), 224));
    // 0x18bc00: 0xffa30018  sd          $v1, 0x18($sp)
    ctx->pc = 0x18bc00u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 24), GPR_U64(ctx, 3));
    // 0x18bc04: 0xffa20020  sd          $v0, 0x20($sp)
    ctx->pc = 0x18bc04u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 32), GPR_U64(ctx, 2));
    // 0x18bc08: 0x26650040  addiu       $a1, $s3, 0x40
    ctx->pc = 0x18bc08u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 19), 64));
    // 0x18bc0c: 0x8e440000  lw          $a0, 0x0($s2)
    ctx->pc = 0x18bc0cu;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 18), 0)));
    // 0x18bc10: 0x26660050  addiu       $a2, $s3, 0x50
    ctx->pc = 0x18bc10u;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 19), 80));
    // 0x18bc14: 0x8c2b4e64  lw          $t3, 0x4E64($at)
    ctx->pc = 0x18bc14u;
    SET_GPR_S32(ctx, 11, (int32_t)READ32(ADD32(GPR_U32(ctx, 1), 20068)));
    // 0x18bc18: 0x26670060  addiu       $a3, $s3, 0x60
    ctx->pc = 0x18bc18u;
    SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 19), 96));
    // 0x18bc1c: 0x26680070  addiu       $t0, $s3, 0x70
    ctx->pc = 0x18bc1cu;
    SET_GPR_S32(ctx, 8, (int32_t)ADD32(GPR_U32(ctx, 19), 112));
    // 0x18bc20: 0x26690080  addiu       $t1, $s3, 0x80
    ctx->pc = 0x18bc20u;
    SET_GPR_S32(ctx, 9, (int32_t)ADD32(GPR_U32(ctx, 19), 128));
    // 0x18bc24: 0xc062f58  jal         func_18BD60
    ctx->pc = 0x18BC24u;
    SET_GPR_U32(ctx, 31, 0x18BC2Cu);
    ctx->pc = 0x18BC28u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x18BC24u;
            // 0x18bc28: 0x266a0090  addiu       $t2, $s3, 0x90 (Delay Slot)
        SET_GPR_S32(ctx, 10, (int32_t)ADD32(GPR_U32(ctx, 19), 144));
        ctx->in_delay_slot = false;
    ctx->pc = 0x18BD60u;
    if (runtime->hasFunction(0x18BD60u)) {
        auto targetFn = runtime->lookupFunction(0x18BD60u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x18BC2Cu; }
        if (ctx->pc != 0x18BC2Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0018BD60_0x18bd60(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x18BC2Cu; }
        if (ctx->pc != 0x18BC2Cu) { return; }
    }
    ctx->pc = 0x18BC2Cu;
label_18bc2c:
    // 0x18bc2c: 0x2719821  addu        $s3, $s3, $s1
    ctx->pc = 0x18bc2cu;
    SET_GPR_S32(ctx, 19, (int32_t)ADD32(GPR_U32(ctx, 19), GPR_U32(ctx, 17)));
    // 0x18bc30: 0x26520004  addiu       $s2, $s2, 0x4
    ctx->pc = 0x18bc30u;
    SET_GPR_S32(ctx, 18, (int32_t)ADD32(GPR_U32(ctx, 18), 4));
    // 0x18bc34: 0x26100001  addiu       $s0, $s0, 0x1
    ctx->pc = 0x18bc34u;
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 16), 1));
label_18bc38:
    // 0x18bc38: 0x214182a  slt         $v1, $s0, $s4
    ctx->pc = 0x18bc38u;
    SET_GPR_U64(ctx, 3, ((int64_t)GPR_S64(ctx, 16) < (int64_t)GPR_S64(ctx, 20)) ? 1 : 0);
    // 0x18bc3c: 0x1460ffe7  bnez        $v1, . + 4 + (-0x19 << 2)
    ctx->pc = 0x18BC3Cu;
    {
        const bool branch_taken_0x18bc3c = (GPR_U64(ctx, 3) != GPR_U64(ctx, 0));
        if (branch_taken_0x18bc3c) {
            ctx->pc = 0x18BBDCu;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_18bbdc;
        }
    }
    ctx->pc = 0x18BC44u;
label_18bc44:
    // 0x18bc44: 0xdfbf0080  ld          $ra, 0x80($sp)
    ctx->pc = 0x18bc44u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 128)));
label_18bc48:
    // 0x18bc48: 0x7bb40070  lq          $s4, 0x70($sp)
    ctx->pc = 0x18bc48u;
    SET_GPR_VEC(ctx, 20, READ128(ADD32(GPR_U32(ctx, 29), 112)));
    // 0x18bc4c: 0x7bb30060  lq          $s3, 0x60($sp)
    ctx->pc = 0x18bc4cu;
    SET_GPR_VEC(ctx, 19, READ128(ADD32(GPR_U32(ctx, 29), 96)));
    // 0x18bc50: 0x7bb20050  lq          $s2, 0x50($sp)
    ctx->pc = 0x18bc50u;
    SET_GPR_VEC(ctx, 18, READ128(ADD32(GPR_U32(ctx, 29), 80)));
    // 0x18bc54: 0x7bb10040  lq          $s1, 0x40($sp)
    ctx->pc = 0x18bc54u;
    SET_GPR_VEC(ctx, 17, READ128(ADD32(GPR_U32(ctx, 29), 64)));
    // 0x18bc58: 0x7bb00030  lq          $s0, 0x30($sp)
    ctx->pc = 0x18bc58u;
    SET_GPR_VEC(ctx, 16, READ128(ADD32(GPR_U32(ctx, 29), 48)));
    // 0x18bc5c: 0x3e00008  jr          $ra
    ctx->pc = 0x18BC5Cu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x18BC60u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x18BC5Cu;
            // 0x18bc60: 0x27bd0090  addiu       $sp, $sp, 0x90 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 144));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x18BAFCu: goto label_18bafc;
            case 0x18BB04u: goto label_18bb04;
            case 0x18BB24u: goto label_18bb24;
            case 0x18BB30u: goto label_18bb30;
            case 0x18BB44u: goto label_18bb44;
            case 0x18BB4Cu: goto label_18bb4c;
            case 0x18BB6Cu: goto label_18bb6c;
            case 0x18BB78u: goto label_18bb78;
            case 0x18BB8Cu: goto label_18bb8c;
            case 0x18BB94u: goto label_18bb94;
            case 0x18BBB4u: goto label_18bbb4;
            case 0x18BBC0u: goto label_18bbc0;
            case 0x18BBD4u: goto label_18bbd4;
            case 0x18BBDCu: goto label_18bbdc;
            case 0x18BC2Cu: goto label_18bc2c;
            case 0x18BC38u: goto label_18bc38;
            case 0x18BC44u: goto label_18bc44;
            case 0x18BC48u: goto label_18bc48;
            default: break;
        }
        return;
    }
    ctx->pc = 0x18BC64u;
    // 0x18bc64: 0x0  nop
    ctx->pc = 0x18bc64u;
    // NOP
    // 0x18bc68: 0x0  nop
    ctx->pc = 0x18bc68u;
    // NOP
    // 0x18bc6c: 0x0  nop
    ctx->pc = 0x18bc6cu;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
