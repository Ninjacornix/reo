#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00146368
// Address: 0x146368 - 0x14645c
void sub_00146368_0x146368(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00146368_0x146368");
#endif

    switch (ctx->pc) {
        case 0x1463e8u: goto label_1463e8;
        case 0x1463f0u: goto label_1463f0;
        case 0x146408u: goto label_146408;
        case 0x146418u: goto label_146418;
        case 0x14642cu: goto label_14642c;
        default: break;
    }

    ctx->pc = 0x146368u;

    // 0x146368: 0x27bdff90  addiu       $sp, $sp, -0x70
    ctx->pc = 0x146368u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967184));
    // 0x14636c: 0xffb10010  sd          $s1, 0x10($sp)
    ctx->pc = 0x14636cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 17));
    // 0x146370: 0xffbf0060  sd          $ra, 0x60($sp)
    ctx->pc = 0x146370u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 96), GPR_U64(ctx, 31));
    // 0x146374: 0x80882d  daddu       $s1, $a0, $zero
    ctx->pc = 0x146374u;
    SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x146378: 0xffb50050  sd          $s5, 0x50($sp)
    ctx->pc = 0x146378u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 80), GPR_U64(ctx, 21));
    // 0x14637c: 0xffb40040  sd          $s4, 0x40($sp)
    ctx->pc = 0x14637cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 64), GPR_U64(ctx, 20));
    // 0x146380: 0xffb30030  sd          $s3, 0x30($sp)
    ctx->pc = 0x146380u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 48), GPR_U64(ctx, 19));
    // 0x146384: 0xffb20020  sd          $s2, 0x20($sp)
    ctx->pc = 0x146384u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 32), GPR_U64(ctx, 18));
    // 0x146388: 0xffb00000  sd          $s0, 0x0($sp)
    ctx->pc = 0x146388u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x14638c: 0x8e220154  lw          $v0, 0x154($s1)
    ctx->pc = 0x14638cu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 340)));
    // 0x146390: 0x50400008  beql        $v0, $zero, . + 4 + (0x8 << 2)
    ctx->pc = 0x146390u;
    {
        const bool branch_taken_0x146390 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        if (branch_taken_0x146390) {
            ctx->pc = 0x146394u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x146390u;
            // 0x146394: 0x8e23018c  lw          $v1, 0x18C($s1) (Delay Slot)
        SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 396)));
        ctx->in_delay_slot = false;
            ctx->pc = 0x1463B4u;
            goto label_1463b4;
        }
    }
    ctx->pc = 0x146398u;
    // 0x146398: 0x8e22019c  lw          $v0, 0x19C($s1)
    ctx->pc = 0x146398u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 412)));
    // 0x14639c: 0x10400008  beqz        $v0, . + 4 + (0x8 << 2)
    ctx->pc = 0x14639Cu;
    {
        const bool branch_taken_0x14639c = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x1463A0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x14639Cu;
            // 0x1463a0: 0x24130002  addiu       $s3, $zero, 0x2 (Delay Slot)
        SET_GPR_S32(ctx, 19, (int32_t)ADD32(GPR_U32(ctx, 0), 2));
        ctx->in_delay_slot = false;
        if (branch_taken_0x14639c) {
            ctx->pc = 0x1463C0u;
            goto label_1463c0;
        }
    }
    ctx->pc = 0x1463A4u;
    // 0x1463a4: 0x8e230190  lw          $v1, 0x190($s1)
    ctx->pc = 0x1463a4u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 400)));
    // 0x1463a8: 0x24020003  addiu       $v0, $zero, 0x3
    ctx->pc = 0x1463a8u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 3));
    // 0x1463ac: 0x10000008  b           . + 4 + (0x8 << 2)
    ctx->pc = 0x1463ACu;
    {
        const bool branch_taken_0x1463ac = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1463B0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1463ACu;
            // 0x1463b0: 0x43980b  movn        $s3, $v0, $v1 (Delay Slot)
        if (GPR_U64(ctx, 3) != 0) SET_GPR_VEC(ctx, 19, GPR_VEC(ctx, 2));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1463ac) {
            ctx->pc = 0x1463D0u;
            goto label_1463d0;
        }
    }
    ctx->pc = 0x1463B4u;
label_1463b4:
    // 0x1463b4: 0x24020003  addiu       $v0, $zero, 0x3
    ctx->pc = 0x1463b4u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 3));
    // 0x1463b8: 0x50620003  beql        $v1, $v0, . + 4 + (0x3 << 2)
    ctx->pc = 0x1463B8u;
    {
        const bool branch_taken_0x1463b8 = (GPR_U64(ctx, 3) == GPR_U64(ctx, 2));
        if (branch_taken_0x1463b8) {
            ctx->pc = 0x1463BCu;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x1463B8u;
            // 0x1463bc: 0x8e22019c  lw          $v0, 0x19C($s1) (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 412)));
        ctx->in_delay_slot = false;
            ctx->pc = 0x1463C8u;
            goto label_1463c8;
        }
    }
    ctx->pc = 0x1463C0u;
label_1463c0:
    // 0x1463c0: 0x10000003  b           . + 4 + (0x3 << 2)
    ctx->pc = 0x1463C0u;
    {
        const bool branch_taken_0x1463c0 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1463C4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1463C0u;
            // 0x1463c4: 0x24130001  addiu       $s3, $zero, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 19, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1463c0) {
            ctx->pc = 0x1463D0u;
            goto label_1463d0;
        }
    }
    ctx->pc = 0x1463C8u;
label_1463c8:
    // 0x1463c8: 0x24130002  addiu       $s3, $zero, 0x2
    ctx->pc = 0x1463c8u;
    SET_GPR_S32(ctx, 19, (int32_t)ADD32(GPR_U32(ctx, 0), 2));
    // 0x1463cc: 0x62980b  movn        $s3, $v1, $v0
    ctx->pc = 0x1463ccu;
    if (GPR_U64(ctx, 2) != 0) SET_GPR_VEC(ctx, 19, GPR_VEC(ctx, 3));
label_1463d0:
    // 0x1463d0: 0x1a600019  blez        $s3, . + 4 + (0x19 << 2)
    ctx->pc = 0x1463D0u;
    {
        const bool branch_taken_0x1463d0 = (GPR_S64(ctx, 19) <= 0);
        ctx->pc = 0x1463D4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1463D0u;
            // 0x1463d4: 0x902d  daddu       $s2, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 18, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1463d0) {
            ctx->pc = 0x146438u;
            goto label_146438;
        }
    }
    ctx->pc = 0x1463D8u;
    // 0x1463d8: 0x263501a4  addiu       $s5, $s1, 0x1A4
    ctx->pc = 0x1463d8u;
    SET_GPR_S32(ctx, 21, (int32_t)ADD32(GPR_U32(ctx, 17), 420));
    // 0x1463dc: 0x263401b0  addiu       $s4, $s1, 0x1B0
    ctx->pc = 0x1463dcu;
    SET_GPR_S32(ctx, 20, (int32_t)ADD32(GPR_U32(ctx, 17), 432));
    // 0x1463e0: 0x220202d  daddu       $a0, $s1, $zero
    ctx->pc = 0x1463e0u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1463e4: 0x0  nop
    ctx->pc = 0x1463e4u;
    // NOP
label_1463e8:
    // 0x1463e8: 0xc05167a  jal         func_1459E8
    ctx->pc = 0x1463E8u;
    SET_GPR_U32(ctx, 31, 0x1463F0u);
    ctx->pc = 0x1463ECu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1463E8u;
            // 0x1463ec: 0x24050010  addiu       $a1, $zero, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 16));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1459E8u;
    if (runtime->hasFunction(0x1459E8u)) {
        auto targetFn = runtime->lookupFunction(0x1459E8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1463F0u; }
        if (ctx->pc != 0x1463F0u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001459E8_0x1459e8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1463F0u; }
        if (ctx->pc != 0x1463F0u) { return; }
    }
    ctx->pc = 0x1463F0u;
label_1463f0:
    // 0x1463f0: 0x128080  sll         $s0, $s2, 2
    ctx->pc = 0x1463f0u;
    SET_GPR_S32(ctx, 16, (int32_t)SLL32(GPR_U32(ctx, 18), 2));
    // 0x1463f4: 0x2b01821  addu        $v1, $s5, $s0
    ctx->pc = 0x1463f4u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 21), GPR_U32(ctx, 16)));
    // 0x1463f8: 0x220202d  daddu       $a0, $s1, $zero
    ctx->pc = 0x1463f8u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1463fc: 0xac620000  sw          $v0, 0x0($v1)
    ctx->pc = 0x1463fcu;
    WRITE32(ADD32(GPR_U32(ctx, 3), 0), GPR_U32(ctx, 2));
    // 0x146400: 0xc05167a  jal         func_1459E8
    ctx->pc = 0x146400u;
    SET_GPR_U32(ctx, 31, 0x146408u);
    ctx->pc = 0x146404u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x146400u;
            // 0x146404: 0x24050001  addiu       $a1, $zero, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1459E8u;
    if (runtime->hasFunction(0x1459E8u)) {
        auto targetFn = runtime->lookupFunction(0x1459E8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x146408u; }
        if (ctx->pc != 0x146408u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001459E8_0x1459e8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x146408u; }
        if (ctx->pc != 0x146408u) { return; }
    }
    ctx->pc = 0x146408u;
label_146408:
    // 0x146408: 0x26520001  addiu       $s2, $s2, 0x1
    ctx->pc = 0x146408u;
    SET_GPR_S32(ctx, 18, (int32_t)ADD32(GPR_U32(ctx, 18), 1));
    // 0x14640c: 0x220202d  daddu       $a0, $s1, $zero
    ctx->pc = 0x14640cu;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
    // 0x146410: 0xc05167a  jal         func_1459E8
    ctx->pc = 0x146410u;
    SET_GPR_U32(ctx, 31, 0x146418u);
    ctx->pc = 0x146414u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x146410u;
            // 0x146414: 0x24050010  addiu       $a1, $zero, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 16));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1459E8u;
    if (runtime->hasFunction(0x1459E8u)) {
        auto targetFn = runtime->lookupFunction(0x1459E8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x146418u; }
        if (ctx->pc != 0x146418u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001459E8_0x1459e8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x146418u; }
        if (ctx->pc != 0x146418u) { return; }
    }
    ctx->pc = 0x146418u;
label_146418:
    // 0x146418: 0x2908021  addu        $s0, $s4, $s0
    ctx->pc = 0x146418u;
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 20), GPR_U32(ctx, 16)));
    // 0x14641c: 0x220202d  daddu       $a0, $s1, $zero
    ctx->pc = 0x14641cu;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
    // 0x146420: 0xae020000  sw          $v0, 0x0($s0)
    ctx->pc = 0x146420u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 0), GPR_U32(ctx, 2));
    // 0x146424: 0xc05167a  jal         func_1459E8
    ctx->pc = 0x146424u;
    SET_GPR_U32(ctx, 31, 0x14642Cu);
    ctx->pc = 0x146428u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x146424u;
            // 0x146428: 0x24050001  addiu       $a1, $zero, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1459E8u;
    if (runtime->hasFunction(0x1459E8u)) {
        auto targetFn = runtime->lookupFunction(0x1459E8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x14642Cu; }
        if (ctx->pc != 0x14642Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001459E8_0x1459e8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x14642Cu; }
        if (ctx->pc != 0x14642Cu) { return; }
    }
    ctx->pc = 0x14642Cu;
label_14642c:
    // 0x14642c: 0x253182a  slt         $v1, $s2, $s3
    ctx->pc = 0x14642cu;
    SET_GPR_U64(ctx, 3, ((int64_t)GPR_S64(ctx, 18) < (int64_t)GPR_S64(ctx, 19)) ? 1 : 0);
    // 0x146430: 0x1460ffed  bnez        $v1, . + 4 + (-0x13 << 2)
    ctx->pc = 0x146430u;
    {
        const bool branch_taken_0x146430 = (GPR_U64(ctx, 3) != GPR_U64(ctx, 0));
        ctx->pc = 0x146434u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x146430u;
            // 0x146434: 0x220202d  daddu       $a0, $s1, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x146430) {
            ctx->pc = 0x1463E8u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_1463e8;
        }
    }
    ctx->pc = 0x146438u;
label_146438:
    // 0x146438: 0xdfbf0060  ld          $ra, 0x60($sp)
    ctx->pc = 0x146438u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 96)));
    // 0x14643c: 0xdfb50050  ld          $s5, 0x50($sp)
    ctx->pc = 0x14643cu;
    SET_GPR_U64(ctx, 21, READ64(ADD32(GPR_U32(ctx, 29), 80)));
    // 0x146440: 0xdfb40040  ld          $s4, 0x40($sp)
    ctx->pc = 0x146440u;
    SET_GPR_U64(ctx, 20, READ64(ADD32(GPR_U32(ctx, 29), 64)));
    // 0x146444: 0xdfb30030  ld          $s3, 0x30($sp)
    ctx->pc = 0x146444u;
    SET_GPR_U64(ctx, 19, READ64(ADD32(GPR_U32(ctx, 29), 48)));
    // 0x146448: 0xdfb20020  ld          $s2, 0x20($sp)
    ctx->pc = 0x146448u;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x14644c: 0xdfb10010  ld          $s1, 0x10($sp)
    ctx->pc = 0x14644cu;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x146450: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x146450u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x146454: 0x3e00008  jr          $ra
    ctx->pc = 0x146454u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x146458u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x146454u;
            // 0x146458: 0x27bd0070  addiu       $sp, $sp, 0x70 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 112));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1463B4u: goto label_1463b4;
            case 0x1463C0u: goto label_1463c0;
            case 0x1463C8u: goto label_1463c8;
            case 0x1463D0u: goto label_1463d0;
            case 0x1463E8u: goto label_1463e8;
            case 0x1463F0u: goto label_1463f0;
            case 0x146408u: goto label_146408;
            case 0x146418u: goto label_146418;
            case 0x14642Cu: goto label_14642c;
            case 0x146438u: goto label_146438;
            default: break;
        }
        return;
    }
    ctx->pc = 0x14645Cu;
    ctx->pc = GPR_U32(ctx, 31); return;
}
