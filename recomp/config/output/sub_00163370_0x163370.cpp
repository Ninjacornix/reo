#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00163370
// Address: 0x163370 - 0x163410
void sub_00163370_0x163370(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00163370_0x163370");
#endif

    switch (ctx->pc) {
        case 0x16338cu: goto label_16338c;
        case 0x1633a0u: goto label_1633a0;
        case 0x1633b4u: goto label_1633b4;
        case 0x1633bcu: goto label_1633bc;
        case 0x1633c8u: goto label_1633c8;
        case 0x1633d8u: goto label_1633d8;
        default: break;
    }

    ctx->pc = 0x163370u;

    // 0x163370: 0x27bdffe0  addiu       $sp, $sp, -0x20
    ctx->pc = 0x163370u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967264));
    // 0x163374: 0xffb10008  sd          $s1, 0x8($sp)
    ctx->pc = 0x163374u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 8), GPR_U64(ctx, 17));
    // 0x163378: 0xffb00000  sd          $s0, 0x0($sp)
    ctx->pc = 0x163378u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x16337c: 0xffb20010  sd          $s2, 0x10($sp)
    ctx->pc = 0x16337cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 18));
    // 0x163380: 0xffbf0018  sd          $ra, 0x18($sp)
    ctx->pc = 0x163380u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 24), GPR_U64(ctx, 31));
    // 0x163384: 0xc058d10  jal         func_163440
    ctx->pc = 0x163384u;
    SET_GPR_U32(ctx, 31, 0x16338Cu);
    ctx->pc = 0x163388u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x163384u;
            // 0x163388: 0x80882d  daddu       $s1, $a0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x163440u;
    if (runtime->hasFunction(0x163440u)) {
        auto targetFn = runtime->lookupFunction(0x163440u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x16338Cu; }
        if (ctx->pc != 0x16338Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00163440_0x163440(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x16338Cu; }
        if (ctx->pc != 0x16338Cu) { return; }
    }
    ctx->pc = 0x16338Cu;
label_16338c:
    // 0x16338c: 0x24030001  addiu       $v1, $zero, 0x1
    ctx->pc = 0x16338cu;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x163390: 0x5443001a  bnel        $v0, $v1, . + 4 + (0x1A << 2)
    ctx->pc = 0x163390u;
    {
        const bool branch_taken_0x163390 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 3));
        if (branch_taken_0x163390) {
            ctx->pc = 0x163394u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x163390u;
            // 0x163394: 0xdfb00000  ld          $s0, 0x0($sp) (Delay Slot)
        SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
        ctx->in_delay_slot = false;
            ctx->pc = 0x1633FCu;
            goto label_1633fc;
        }
    }
    ctx->pc = 0x163398u;
    // 0x163398: 0xc058d08  jal         func_163420
    ctx->pc = 0x163398u;
    SET_GPR_U32(ctx, 31, 0x1633A0u);
    ctx->pc = 0x163420u;
    if (runtime->hasFunction(0x163420u)) {
        auto targetFn = runtime->lookupFunction(0x163420u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1633A0u; }
        if (ctx->pc != 0x1633A0u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00163420_0x163420(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1633A0u; }
        if (ctx->pc != 0x1633A0u) { return; }
    }
    ctx->pc = 0x1633A0u;
label_1633a0:
    // 0x1633a0: 0x8e300014  lw          $s0, 0x14($s1)
    ctx->pc = 0x1633a0u;
    SET_GPR_S32(ctx, 16, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 20)));
    // 0x1633a4: 0x12000014  beqz        $s0, . + 4 + (0x14 << 2)
    ctx->pc = 0x1633A4u;
    {
        const bool branch_taken_0x1633a4 = (GPR_U64(ctx, 16) == GPR_U64(ctx, 0));
        ctx->pc = 0x1633A8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1633A4u;
            // 0x1633a8: 0x8e32000c  lw          $s2, 0xC($s1) (Delay Slot)
        SET_GPR_S32(ctx, 18, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 12)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1633a4) {
            ctx->pc = 0x1633F8u;
            goto label_1633f8;
        }
    }
    ctx->pc = 0x1633ACu;
    // 0x1633ac: 0xc058dfa  jal         func_1637E8
    ctx->pc = 0x1633ACu;
    SET_GPR_U32(ctx, 31, 0x1633B4u);
    ctx->pc = 0x1637E8u;
    if (runtime->hasFunction(0x1637E8u)) {
        auto targetFn = runtime->lookupFunction(0x1637E8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1633B4u; }
        if (ctx->pc != 0x1633B4u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001637E8_0x1637e8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1633B4u; }
        if (ctx->pc != 0x1633B4u) { return; }
    }
    ctx->pc = 0x1633B4u;
label_1633b4:
    // 0x1633b4: 0xc058bd2  jal         func_162F48
    ctx->pc = 0x1633B4u;
    SET_GPR_U32(ctx, 31, 0x1633BCu);
    ctx->pc = 0x1633B8u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1633B4u;
            // 0x1633b8: 0x200202d  daddu       $a0, $s0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x162F48u;
    if (runtime->hasFunction(0x162F48u)) {
        auto targetFn = runtime->lookupFunction(0x162F48u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1633BCu; }
        if (ctx->pc != 0x1633BCu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00162F48_0x162f48(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1633BCu; }
        if (ctx->pc != 0x1633BCu) { return; }
    }
    ctx->pc = 0x1633BCu;
label_1633bc:
    // 0x1633bc: 0xae200000  sw          $zero, 0x0($s1)
    ctx->pc = 0x1633bcu;
    WRITE32(ADD32(GPR_U32(ctx, 17), 0), GPR_U32(ctx, 0));
    // 0x1633c0: 0xc058baa  jal         func_162EA8
    ctx->pc = 0x1633C0u;
    SET_GPR_U32(ctx, 31, 0x1633C8u);
    ctx->pc = 0x1633C4u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1633C0u;
            // 0x1633c4: 0x200202d  daddu       $a0, $s0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x162EA8u;
    if (runtime->hasFunction(0x162EA8u)) {
        auto targetFn = runtime->lookupFunction(0x162EA8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1633C8u; }
        if (ctx->pc != 0x1633C8u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00162EA8_0x162ea8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1633C8u; }
        if (ctx->pc != 0x1633C8u) { return; }
    }
    ctx->pc = 0x1633C8u;
label_1633c8:
    // 0x1633c8: 0x8e430000  lw          $v1, 0x0($s2)
    ctx->pc = 0x1633c8u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 18), 0)));
    // 0x1633cc: 0x8c62000c  lw          $v0, 0xC($v1)
    ctx->pc = 0x1633ccu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 3), 12)));
    // 0x1633d0: 0x40f809  jalr        $v0
    ctx->pc = 0x1633D0u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 2);
        SET_GPR_U32(ctx, 31, 0x1633D8u);
        ctx->pc = 0x1633D4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1633D0u;
            // 0x1633d4: 0x240202d  daddu       $a0, $s2, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 18) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (jumpTarget == 0u) {
            ctx->pc = 0x1633D8u;
        } else {
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x16338Cu: goto label_16338c;
            case 0x1633A0u: goto label_1633a0;
            case 0x1633B4u: goto label_1633b4;
            case 0x1633BCu: goto label_1633bc;
            case 0x1633C8u: goto label_1633c8;
            case 0x1633D8u: goto label_1633d8;
            case 0x1633F8u: goto label_1633f8;
            case 0x1633FCu: goto label_1633fc;
            default: break;
        }
        {
            auto targetFn = runtime->lookupFunction(jumpTarget);
            const uint32_t __entryPc = ctx->pc;
            targetFn(rdram, ctx, runtime);
            if (ctx->pc == __entryPc) { ctx->pc = 0x1633D8u; }
            if (ctx->pc != 0x1633D8u) { return; }
        }
        }
    }
    ctx->pc = 0x1633D8u;
label_1633d8:
    // 0x1633d8: 0xae200014  sw          $zero, 0x14($s1)
    ctx->pc = 0x1633d8u;
    WRITE32(ADD32(GPR_U32(ctx, 17), 20), GPR_U32(ctx, 0));
    // 0x1633dc: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x1633dcu;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1633e0: 0xdfb10008  ld          $s1, 0x8($sp)
    ctx->pc = 0x1633e0u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x1633e4: 0xdfb20010  ld          $s2, 0x10($sp)
    ctx->pc = 0x1633e4u;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x1633e8: 0xdfbf0018  ld          $ra, 0x18($sp)
    ctx->pc = 0x1633e8u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 24)));
    // 0x1633ec: 0x8058b62  j           func_162D88
    ctx->pc = 0x1633ECu;
    ctx->pc = 0x1633F0u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1633ECu;
            // 0x1633f0: 0x27bd0020  addiu       $sp, $sp, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
        ctx->in_delay_slot = false;
    ctx->pc = 0x162D88u;
    if (runtime->hasFunction(0x162D88u)) {
        auto targetFn = runtime->lookupFunction(0x162D88u);
        targetFn(rdram, ctx, runtime); return;
    } else {
        sub_00162D88_0x162d88(rdram, ctx, runtime); return;
    }
    ctx->pc = 0x1633F4u;
    // 0x1633f4: 0x0  nop
    ctx->pc = 0x1633f4u;
    // NOP
label_1633f8:
    // 0x1633f8: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x1633f8u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
label_1633fc:
    // 0x1633fc: 0xdfb10008  ld          $s1, 0x8($sp)
    ctx->pc = 0x1633fcu;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x163400: 0xdfb20010  ld          $s2, 0x10($sp)
    ctx->pc = 0x163400u;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x163404: 0xdfbf0018  ld          $ra, 0x18($sp)
    ctx->pc = 0x163404u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 24)));
    // 0x163408: 0x3e00008  jr          $ra
    ctx->pc = 0x163408u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x16340Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x163408u;
            // 0x16340c: 0x27bd0020  addiu       $sp, $sp, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x16338Cu: goto label_16338c;
            case 0x1633A0u: goto label_1633a0;
            case 0x1633B4u: goto label_1633b4;
            case 0x1633BCu: goto label_1633bc;
            case 0x1633C8u: goto label_1633c8;
            case 0x1633D8u: goto label_1633d8;
            case 0x1633F8u: goto label_1633f8;
            case 0x1633FCu: goto label_1633fc;
            default: break;
        }
        return;
    }
    ctx->pc = 0x163410u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
