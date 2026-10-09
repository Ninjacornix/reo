#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001C6310
// Address: 0x1c6310 - 0x1c64c0
void sub_001C6310_0x1c6310(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001C6310_0x1c6310");
#endif

    switch (ctx->pc) {
        case 0x1c6360u: goto label_1c6360;
        case 0x1c6370u: goto label_1c6370;
        case 0x1c63c8u: goto label_1c63c8;
        case 0x1c63dcu: goto label_1c63dc;
        case 0x1c6438u: goto label_1c6438;
        case 0x1c6448u: goto label_1c6448;
        case 0x1c6450u: goto label_1c6450;
        case 0x1c6460u: goto label_1c6460;
        case 0x1c6478u: goto label_1c6478;
        case 0x1c6488u: goto label_1c6488;
        case 0x1c6498u: goto label_1c6498;
        case 0x1c64a0u: goto label_1c64a0;
        default: break;
    }

    ctx->pc = 0x1c6310u;

label_1c6310:
    // 0x1c6310: 0x8c8301ac  lw          $v1, 0x1AC($a0)
    ctx->pc = 0x1c6310u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 428)));
    // 0x1c6314: 0x14600003  bnez        $v1, . + 4 + (0x3 << 2)
    ctx->pc = 0x1C6314u;
    {
        const bool branch_taken_0x1c6314 = (GPR_U64(ctx, 3) != GPR_U64(ctx, 0));
        if (branch_taken_0x1c6314) {
            ctx->pc = 0x1C6324u;
            goto label_1c6324;
        }
    }
    ctx->pc = 0x1C631Cu;
    // 0x1c631c: 0x8c8301a8  lw          $v1, 0x1A8($a0)
    ctx->pc = 0x1c631cu;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 424)));
    // 0x1c6320: 0xac8301ac  sw          $v1, 0x1AC($a0)
    ctx->pc = 0x1c6320u;
    WRITE32(ADD32(GPR_U32(ctx, 4), 428), GPR_U32(ctx, 3));
label_1c6324:
    // 0x1c6324: 0x8c8301b8  lw          $v1, 0x1B8($a0)
    ctx->pc = 0x1c6324u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 440)));
    // 0x1c6328: 0x3e00008  jr          $ra
    ctx->pc = 0x1C6328u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1C632Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1C6328u;
            // 0x1c632c: 0xac8301bc  sw          $v1, 0x1BC($a0) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 4), 444), GPR_U32(ctx, 3));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1C6310u: goto label_1c6310;
            case 0x1C6324u: goto label_1c6324;
            case 0x1C6360u: goto label_1c6360;
            case 0x1C6370u: goto label_1c6370;
            case 0x1C6384u: goto label_1c6384;
            case 0x1C6388u: goto label_1c6388;
            case 0x1C63C8u: goto label_1c63c8;
            case 0x1C63DCu: goto label_1c63dc;
            case 0x1C63F0u: goto label_1c63f0;
            case 0x1C63F4u: goto label_1c63f4;
            case 0x1C6438u: goto label_1c6438;
            case 0x1C6448u: goto label_1c6448;
            case 0x1C6450u: goto label_1c6450;
            case 0x1C6458u: goto label_1c6458;
            case 0x1C6460u: goto label_1c6460;
            case 0x1C6478u: goto label_1c6478;
            case 0x1C6488u: goto label_1c6488;
            case 0x1C6498u: goto label_1c6498;
            case 0x1C64A0u: goto label_1c64a0;
            case 0x1C64A4u: goto label_1c64a4;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1C6330u;
    // 0x1c6330: 0x80720d4  j           func_1C8350
    ctx->pc = 0x1C6330u;
    ctx->pc = 0x1C6334u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1C6330u;
            // 0x1c6334: 0x24840028  addiu       $a0, $a0, 0x28 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 40));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1C8350u;
    if (runtime->hasFunction(0x1C8350u)) {
        auto targetFn = runtime->lookupFunction(0x1C8350u);
        targetFn(rdram, ctx, runtime); return;
    } else {
        sub_001C8350_0x1c8350(rdram, ctx, runtime); return;
    }
    ctx->pc = 0x1C6338u;
    // 0x1c6338: 0x0  nop
    ctx->pc = 0x1c6338u;
    // NOP
    // 0x1c633c: 0x0  nop
    ctx->pc = 0x1c633cu;
    // NOP
    // 0x1c6340: 0x8072108  j           func_1C8420
    ctx->pc = 0x1C6340u;
    ctx->pc = 0x1C6344u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1C6340u;
            // 0x1c6344: 0x24840028  addiu       $a0, $a0, 0x28 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 40));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1C8420u;
    if (runtime->hasFunction(0x1C8420u)) {
        auto targetFn = runtime->lookupFunction(0x1C8420u);
        targetFn(rdram, ctx, runtime); return;
    } else {
        sub_001C8420_0x1c8420(rdram, ctx, runtime); return;
    }
    ctx->pc = 0x1C6348u;
    // 0x1c6348: 0x0  nop
    ctx->pc = 0x1c6348u;
    // NOP
    // 0x1c634c: 0x0  nop
    ctx->pc = 0x1c634cu;
    // NOP
    // 0x1c6350: 0x807210c  j           func_1C8430
    ctx->pc = 0x1C6350u;
    ctx->pc = 0x1C6354u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1C6350u;
            // 0x1c6354: 0x24840028  addiu       $a0, $a0, 0x28 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 40));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1C8430u;
    if (runtime->hasFunction(0x1C8430u)) {
        auto targetFn = runtime->lookupFunction(0x1C8430u);
        targetFn(rdram, ctx, runtime); return;
    } else {
        sub_001C8430_0x1c8430(rdram, ctx, runtime); return;
    }
    ctx->pc = 0x1C6358u;
    // 0x1c6358: 0x0  nop
    ctx->pc = 0x1c6358u;
    // NOP
    // 0x1c635c: 0x0  nop
    ctx->pc = 0x1c635cu;
    // NOP
label_1c6360:
    // 0x1c6360: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x1c6360u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x1c6364: 0xffbf0000  sd          $ra, 0x0($sp)
    ctx->pc = 0x1c6364u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 31));
    // 0x1c6368: 0xc0721fc  jal         func_1C87F0
    ctx->pc = 0x1C6368u;
    SET_GPR_U32(ctx, 31, 0x1C6370u);
    ctx->pc = 0x1C636Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1C6368u;
            // 0x1c636c: 0x24840028  addiu       $a0, $a0, 0x28 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 40));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1C87F0u;
    if (runtime->hasFunction(0x1C87F0u)) {
        auto targetFn = runtime->lookupFunction(0x1C87F0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1C6370u; }
        if (ctx->pc != 0x1C6370u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001C87F0_0x1c87f0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1C6370u; }
        if (ctx->pc != 0x1C6370u) { return; }
    }
    ctx->pc = 0x1C6370u;
label_1c6370:
    // 0x1c6370: 0x24030003  addiu       $v1, $zero, 0x3
    ctx->pc = 0x1c6370u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 3));
    // 0x1c6374: 0x14430003  bne         $v0, $v1, . + 4 + (0x3 << 2)
    ctx->pc = 0x1C6374u;
    {
        const bool branch_taken_0x1c6374 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 3));
        if (branch_taken_0x1c6374) {
            ctx->pc = 0x1C6384u;
            goto label_1c6384;
        }
    }
    ctx->pc = 0x1C637Cu;
    // 0x1c637c: 0x10000002  b           . + 4 + (0x2 << 2)
    ctx->pc = 0x1C637Cu;
    {
        const bool branch_taken_0x1c637c = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1C6380u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1C637Cu;
            // 0x1c6380: 0x24020001  addiu       $v0, $zero, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1c637c) {
            ctx->pc = 0x1C6388u;
            goto label_1c6388;
        }
    }
    ctx->pc = 0x1C6384u;
label_1c6384:
    // 0x1c6384: 0x102d  daddu       $v0, $zero, $zero
    ctx->pc = 0x1c6384u;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
label_1c6388:
    // 0x1c6388: 0xdfbf0000  ld          $ra, 0x0($sp)
    ctx->pc = 0x1c6388u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1c638c: 0x3e00008  jr          $ra
    ctx->pc = 0x1C638Cu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1C6390u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1C638Cu;
            // 0x1c6390: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1C6310u: goto label_1c6310;
            case 0x1C6324u: goto label_1c6324;
            case 0x1C6360u: goto label_1c6360;
            case 0x1C6370u: goto label_1c6370;
            case 0x1C6384u: goto label_1c6384;
            case 0x1C6388u: goto label_1c6388;
            case 0x1C63C8u: goto label_1c63c8;
            case 0x1C63DCu: goto label_1c63dc;
            case 0x1C63F0u: goto label_1c63f0;
            case 0x1C63F4u: goto label_1c63f4;
            case 0x1C6438u: goto label_1c6438;
            case 0x1C6448u: goto label_1c6448;
            case 0x1C6450u: goto label_1c6450;
            case 0x1C6458u: goto label_1c6458;
            case 0x1C6460u: goto label_1c6460;
            case 0x1C6478u: goto label_1c6478;
            case 0x1C6488u: goto label_1c6488;
            case 0x1C6498u: goto label_1c6498;
            case 0x1C64A0u: goto label_1c64a0;
            case 0x1C64A4u: goto label_1c64a4;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1C6394u;
    // 0x1c6394: 0x0  nop
    ctx->pc = 0x1c6394u;
    // NOP
    // 0x1c6398: 0x0  nop
    ctx->pc = 0x1c6398u;
    // NOP
    // 0x1c639c: 0x0  nop
    ctx->pc = 0x1c639cu;
    // NOP
    // 0x1c63a0: 0x80718d8  j           func_1C6360
    ctx->pc = 0x1C63A0u;
    ctx->pc = 0x1C6360u;
    if (runtime->shouldPreemptGuestExecution()) {
        return;
    }
    goto label_1c6360;
    ctx->pc = 0x1C63A8u;
    // 0x1c63a8: 0x0  nop
    ctx->pc = 0x1c63a8u;
    // NOP
    // 0x1c63ac: 0x0  nop
    ctx->pc = 0x1c63acu;
    // NOP
    // 0x1c63b0: 0x27bdffe0  addiu       $sp, $sp, -0x20
    ctx->pc = 0x1c63b0u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967264));
    // 0x1c63b4: 0xffbf0010  sd          $ra, 0x10($sp)
    ctx->pc = 0x1c63b4u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 31));
    // 0x1c63b8: 0x7fb00000  sq          $s0, 0x0($sp)
    ctx->pc = 0x1c63b8u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 0), GPR_VEC(ctx, 16));
    // 0x1c63bc: 0x80802d  daddu       $s0, $a0, $zero
    ctx->pc = 0x1c63bcu;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1c63c0: 0xc072110  jal         func_1C8440
    ctx->pc = 0x1C63C0u;
    SET_GPR_U32(ctx, 31, 0x1C63C8u);
    ctx->pc = 0x1C63C4u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1C63C0u;
            // 0x1c63c4: 0x26040028  addiu       $a0, $s0, 0x28 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 16), 40));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1C8440u;
    if (runtime->hasFunction(0x1C8440u)) {
        auto targetFn = runtime->lookupFunction(0x1C8440u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1C63C8u; }
        if (ctx->pc != 0x1C63C8u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001C8440_0x1c8440(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1C63C8u; }
        if (ctx->pc != 0x1C63C8u) { return; }
    }
    ctx->pc = 0x1C63C8u;
label_1c63c8:
    // 0x1c63c8: 0x960201e0  lhu         $v0, 0x1E0($s0)
    ctx->pc = 0x1c63c8u;
    SET_GPR_U32(ctx, 2, (uint16_t)READ16(ADD32(GPR_U32(ctx, 16), 480)));
    // 0x1c63cc: 0x26040028  addiu       $a0, $s0, 0x28
    ctx->pc = 0x1c63ccu;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 16), 40));
    // 0x1c63d0: 0x24420001  addiu       $v0, $v0, 0x1
    ctx->pc = 0x1c63d0u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 1));
    // 0x1c63d4: 0xc0721fc  jal         func_1C87F0
    ctx->pc = 0x1C63D4u;
    SET_GPR_U32(ctx, 31, 0x1C63DCu);
    ctx->pc = 0x1C63D8u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1C63D4u;
            // 0x1c63d8: 0xa60201e0  sh          $v0, 0x1E0($s0) (Delay Slot)
        WRITE16(ADD32(GPR_U32(ctx, 16), 480), (uint16_t)GPR_U32(ctx, 2));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1C87F0u;
    if (runtime->hasFunction(0x1C87F0u)) {
        auto targetFn = runtime->lookupFunction(0x1C87F0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1C63DCu; }
        if (ctx->pc != 0x1C63DCu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001C87F0_0x1c87f0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1C63DCu; }
        if (ctx->pc != 0x1C63DCu) { return; }
    }
    ctx->pc = 0x1C63DCu;
label_1c63dc:
    // 0x1c63dc: 0x24030003  addiu       $v1, $zero, 0x3
    ctx->pc = 0x1c63dcu;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 3));
    // 0x1c63e0: 0x14430003  bne         $v0, $v1, . + 4 + (0x3 << 2)
    ctx->pc = 0x1C63E0u;
    {
        const bool branch_taken_0x1c63e0 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 3));
        if (branch_taken_0x1c63e0) {
            ctx->pc = 0x1C63F0u;
            goto label_1c63f0;
        }
    }
    ctx->pc = 0x1C63E8u;
    // 0x1c63e8: 0x10000002  b           . + 4 + (0x2 << 2)
    ctx->pc = 0x1C63E8u;
    {
        const bool branch_taken_0x1c63e8 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1C63ECu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1C63E8u;
            // 0x1c63ec: 0x24020001  addiu       $v0, $zero, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1c63e8) {
            ctx->pc = 0x1C63F4u;
            goto label_1c63f4;
        }
    }
    ctx->pc = 0x1C63F0u;
label_1c63f0:
    // 0x1c63f0: 0x102d  daddu       $v0, $zero, $zero
    ctx->pc = 0x1c63f0u;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
label_1c63f4:
    // 0x1c63f4: 0xdfbf0010  ld          $ra, 0x10($sp)
    ctx->pc = 0x1c63f4u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x1c63f8: 0x7bb00000  lq          $s0, 0x0($sp)
    ctx->pc = 0x1c63f8u;
    SET_GPR_VEC(ctx, 16, READ128(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1c63fc: 0x3e00008  jr          $ra
    ctx->pc = 0x1C63FCu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1C6400u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1C63FCu;
            // 0x1c6400: 0x27bd0020  addiu       $sp, $sp, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1C6310u: goto label_1c6310;
            case 0x1C6324u: goto label_1c6324;
            case 0x1C6360u: goto label_1c6360;
            case 0x1C6370u: goto label_1c6370;
            case 0x1C6384u: goto label_1c6384;
            case 0x1C6388u: goto label_1c6388;
            case 0x1C63C8u: goto label_1c63c8;
            case 0x1C63DCu: goto label_1c63dc;
            case 0x1C63F0u: goto label_1c63f0;
            case 0x1C63F4u: goto label_1c63f4;
            case 0x1C6438u: goto label_1c6438;
            case 0x1C6448u: goto label_1c6448;
            case 0x1C6450u: goto label_1c6450;
            case 0x1C6458u: goto label_1c6458;
            case 0x1C6460u: goto label_1c6460;
            case 0x1C6478u: goto label_1c6478;
            case 0x1C6488u: goto label_1c6488;
            case 0x1C6498u: goto label_1c6498;
            case 0x1C64A0u: goto label_1c64a0;
            case 0x1C64A4u: goto label_1c64a4;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1C6404u;
    // 0x1c6404: 0x0  nop
    ctx->pc = 0x1c6404u;
    // NOP
    // 0x1c6408: 0x0  nop
    ctx->pc = 0x1c6408u;
    // NOP
    // 0x1c640c: 0x0  nop
    ctx->pc = 0x1c640cu;
    // NOP
    // 0x1c6410: 0x27bdffd0  addiu       $sp, $sp, -0x30
    ctx->pc = 0x1c6410u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967248));
    // 0x1c6414: 0x30a200ff  andi        $v0, $a1, 0xFF
    ctx->pc = 0x1c6414u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 5) & (uint64_t)(uint16_t)255);
    // 0x1c6418: 0xffbf0020  sd          $ra, 0x20($sp)
    ctx->pc = 0x1c6418u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 32), GPR_U64(ctx, 31));
    // 0x1c641c: 0x7fb10010  sq          $s1, 0x10($sp)
    ctx->pc = 0x1c641cu;
    WRITE128(ADD32(GPR_U32(ctx, 29), 16), GPR_VEC(ctx, 17));
    // 0x1c6420: 0x7fb00000  sq          $s0, 0x0($sp)
    ctx->pc = 0x1c6420u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 0), GPR_VEC(ctx, 16));
    // 0x1c6424: 0x80882d  daddu       $s1, $a0, $zero
    ctx->pc = 0x1c6424u;
    SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1c6428: 0x1440000b  bnez        $v0, . + 4 + (0xB << 2)
    ctx->pc = 0x1C6428u;
    {
        const bool branch_taken_0x1c6428 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x1C642Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1C6428u;
            // 0x1c642c: 0x802d  daddu       $s0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1c6428) {
            ctx->pc = 0x1C6458u;
            goto label_1c6458;
        }
    }
    ctx->pc = 0x1C6430u;
    // 0x1c6430: 0xc071830  jal         func_1C60C0
    ctx->pc = 0x1C6430u;
    SET_GPR_U32(ctx, 31, 0x1C6438u);
    ctx->pc = 0x1C60C0u;
    if (runtime->hasFunction(0x1C60C0u)) {
        auto targetFn = runtime->lookupFunction(0x1C60C0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1C6438u; }
        if (ctx->pc != 0x1C6438u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001C60C0_0x1c60c0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1C6438u; }
        if (ctx->pc != 0x1C6438u) { return; }
    }
    ctx->pc = 0x1C6438u;
label_1c6438:
    // 0x1c6438: 0x1040001a  beqz        $v0, . + 4 + (0x1A << 2)
    ctx->pc = 0x1C6438u;
    {
        const bool branch_taken_0x1c6438 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x1C643Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1C6438u;
            // 0x1c643c: 0x220202d  daddu       $a0, $s1, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1c6438) {
            ctx->pc = 0x1C64A4u;
            goto label_1c64a4;
        }
    }
    ctx->pc = 0x1C6440u;
    // 0x1c6440: 0xc071930  jal         func_1C64C0
    ctx->pc = 0x1C6440u;
    SET_GPR_U32(ctx, 31, 0x1C6448u);
    ctx->pc = 0x1C64C0u;
    if (runtime->hasFunction(0x1C64C0u)) {
        auto targetFn = runtime->lookupFunction(0x1C64C0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1C6448u; }
        if (ctx->pc != 0x1C6448u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001C64C0_0x1c64c0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1C6448u; }
        if (ctx->pc != 0x1C6448u) { return; }
    }
    ctx->pc = 0x1C6448u;
label_1c6448:
    // 0x1c6448: 0xc0718c4  jal         func_1C6310
    ctx->pc = 0x1C6448u;
    SET_GPR_U32(ctx, 31, 0x1C6450u);
    ctx->pc = 0x1C644Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1C6448u;
            // 0x1c644c: 0x220202d  daddu       $a0, $s1, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1C6310u;
    goto label_1c6310;
    ctx->pc = 0x1C6450u;
label_1c6450:
    // 0x1c6450: 0x10000014  b           . + 4 + (0x14 << 2)
    ctx->pc = 0x1C6450u;
    {
        const bool branch_taken_0x1c6450 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1C6454u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1C6450u;
            // 0x1c6454: 0x24100001  addiu       $s0, $zero, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1c6450) {
            ctx->pc = 0x1C64A4u;
            goto label_1c64a4;
        }
    }
    ctx->pc = 0x1C6458u;
label_1c6458:
    // 0x1c6458: 0xc072170  jal         func_1C85C0
    ctx->pc = 0x1C6458u;
    SET_GPR_U32(ctx, 31, 0x1C6460u);
    ctx->pc = 0x1C645Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1C6458u;
            // 0x1c645c: 0x26240028  addiu       $a0, $s1, 0x28 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 17), 40));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1C85C0u;
    if (runtime->hasFunction(0x1C85C0u)) {
        auto targetFn = runtime->lookupFunction(0x1C85C0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1C6460u; }
        if (ctx->pc != 0x1C6460u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001C85C0_0x1c85c0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1C6460u; }
        if (ctx->pc != 0x1C6460u) { return; }
    }
    ctx->pc = 0x1C6460u;
label_1c6460:
    // 0x1c6460: 0x304200ff  andi        $v0, $v0, 0xFF
    ctx->pc = 0x1c6460u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) & (uint64_t)(uint16_t)255);
    // 0x1c6464: 0x28410002  slti        $at, $v0, 0x2
    ctx->pc = 0x1c6464u;
    SET_GPR_U64(ctx, 1, ((int64_t)GPR_S64(ctx, 2) < (int64_t)(int32_t)2) ? 1 : 0);
    // 0x1c6468: 0x1020000e  beqz        $at, . + 4 + (0xE << 2)
    ctx->pc = 0x1C6468u;
    {
        const bool branch_taken_0x1c6468 = (GPR_U64(ctx, 1) == GPR_U64(ctx, 0));
        ctx->pc = 0x1C646Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1C6468u;
            // 0x1c646c: 0x220202d  daddu       $a0, $s1, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1c6468) {
            ctx->pc = 0x1C64A4u;
            goto label_1c64a4;
        }
    }
    ctx->pc = 0x1C6470u;
    // 0x1c6470: 0xc071830  jal         func_1C60C0
    ctx->pc = 0x1C6470u;
    SET_GPR_U32(ctx, 31, 0x1C6478u);
    ctx->pc = 0x1C6474u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1C6470u;
            // 0x1c6474: 0xa62001e0  sh          $zero, 0x1E0($s1) (Delay Slot)
        WRITE16(ADD32(GPR_U32(ctx, 17), 480), (uint16_t)GPR_U32(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1C60C0u;
    if (runtime->hasFunction(0x1C60C0u)) {
        auto targetFn = runtime->lookupFunction(0x1C60C0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1C6478u; }
        if (ctx->pc != 0x1C6478u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001C60C0_0x1c60c0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1C6478u; }
        if (ctx->pc != 0x1C6478u) { return; }
    }
    ctx->pc = 0x1C6478u;
label_1c6478:
    // 0x1c6478: 0x1040000a  beqz        $v0, . + 4 + (0xA << 2)
    ctx->pc = 0x1C6478u;
    {
        const bool branch_taken_0x1c6478 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x1C647Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1C6478u;
            // 0x1c647c: 0x220202d  daddu       $a0, $s1, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1c6478) {
            ctx->pc = 0x1C64A4u;
            goto label_1c64a4;
        }
    }
    ctx->pc = 0x1C6480u;
    // 0x1c6480: 0xc071930  jal         func_1C64C0
    ctx->pc = 0x1C6480u;
    SET_GPR_U32(ctx, 31, 0x1C6488u);
    ctx->pc = 0x1C64C0u;
    if (runtime->hasFunction(0x1C64C0u)) {
        auto targetFn = runtime->lookupFunction(0x1C64C0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1C6488u; }
        if (ctx->pc != 0x1C6488u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001C64C0_0x1c64c0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1C6488u; }
        if (ctx->pc != 0x1C6488u) { return; }
    }
    ctx->pc = 0x1C6488u;
label_1c6488:
    // 0x1c6488: 0x26240028  addiu       $a0, $s1, 0x28
    ctx->pc = 0x1c6488u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 17), 40));
    // 0x1c648c: 0x282d  daddu       $a1, $zero, $zero
    ctx->pc = 0x1c648cu;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1c6490: 0xc072188  jal         func_1C8620
    ctx->pc = 0x1C6490u;
    SET_GPR_U32(ctx, 31, 0x1C6498u);
    ctx->pc = 0x1C6494u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1C6490u;
            // 0x1c6494: 0x26260014  addiu       $a2, $s1, 0x14 (Delay Slot)
        SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 17), 20));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1C8620u;
    if (runtime->hasFunction(0x1C8620u)) {
        auto targetFn = runtime->lookupFunction(0x1C8620u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1C6498u; }
        if (ctx->pc != 0x1C6498u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001C8620_0x1c8620(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1C6498u; }
        if (ctx->pc != 0x1C6498u) { return; }
    }
    ctx->pc = 0x1C6498u;
label_1c6498:
    // 0x1c6498: 0xc0718c4  jal         func_1C6310
    ctx->pc = 0x1C6498u;
    SET_GPR_U32(ctx, 31, 0x1C64A0u);
    ctx->pc = 0x1C649Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1C6498u;
            // 0x1c649c: 0x220202d  daddu       $a0, $s1, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1C6310u;
    goto label_1c6310;
    ctx->pc = 0x1C64A0u;
label_1c64a0:
    // 0x1c64a0: 0x24100001  addiu       $s0, $zero, 0x1
    ctx->pc = 0x1c64a0u;
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
label_1c64a4:
    // 0x1c64a4: 0x200102d  daddu       $v0, $s0, $zero
    ctx->pc = 0x1c64a4u;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1c64a8: 0xdfbf0020  ld          $ra, 0x20($sp)
    ctx->pc = 0x1c64a8u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x1c64ac: 0x7bb10010  lq          $s1, 0x10($sp)
    ctx->pc = 0x1c64acu;
    SET_GPR_VEC(ctx, 17, READ128(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x1c64b0: 0x7bb00000  lq          $s0, 0x0($sp)
    ctx->pc = 0x1c64b0u;
    SET_GPR_VEC(ctx, 16, READ128(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1c64b4: 0x3e00008  jr          $ra
    ctx->pc = 0x1C64B4u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1C64B8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1C64B4u;
            // 0x1c64b8: 0x27bd0030  addiu       $sp, $sp, 0x30 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 48));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1C6310u: goto label_1c6310;
            case 0x1C6324u: goto label_1c6324;
            case 0x1C6360u: goto label_1c6360;
            case 0x1C6370u: goto label_1c6370;
            case 0x1C6384u: goto label_1c6384;
            case 0x1C6388u: goto label_1c6388;
            case 0x1C63C8u: goto label_1c63c8;
            case 0x1C63DCu: goto label_1c63dc;
            case 0x1C63F0u: goto label_1c63f0;
            case 0x1C63F4u: goto label_1c63f4;
            case 0x1C6438u: goto label_1c6438;
            case 0x1C6448u: goto label_1c6448;
            case 0x1C6450u: goto label_1c6450;
            case 0x1C6458u: goto label_1c6458;
            case 0x1C6460u: goto label_1c6460;
            case 0x1C6478u: goto label_1c6478;
            case 0x1C6488u: goto label_1c6488;
            case 0x1C6498u: goto label_1c6498;
            case 0x1C64A0u: goto label_1c64a0;
            case 0x1C64A4u: goto label_1c64a4;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1C64BCu;
    // 0x1c64bc: 0x0  nop
    ctx->pc = 0x1c64bcu;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
