#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00132548
// Address: 0x132548 - 0x1326f0
void sub_00132548_0x132548(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00132548_0x132548");
#endif

    switch (ctx->pc) {
        case 0x132560u: goto label_132560;
        case 0x1325b0u: goto label_1325b0;
        case 0x132600u: goto label_132600;
        case 0x132688u: goto label_132688;
        case 0x1326c8u: goto label_1326c8;
        case 0x1326d8u: goto label_1326d8;
        default: break;
    }

    ctx->pc = 0x132548u;

    // 0x132548: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x132548u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x13254c: 0x14800006  bnez        $a0, . + 4 + (0x6 << 2)
    ctx->pc = 0x13254Cu;
    {
        const bool branch_taken_0x13254c = (GPR_U64(ctx, 4) != GPR_U64(ctx, 0));
        ctx->pc = 0x132550u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x13254Cu;
            // 0x132550: 0xffbf0000  sd          $ra, 0x0($sp) (Delay Slot)
        WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 31));
        ctx->in_delay_slot = false;
        if (branch_taken_0x13254c) {
            ctx->pc = 0x132568u;
            goto label_132568;
        }
    }
    ctx->pc = 0x132554u;
    // 0x132554: 0x3c040024  lui         $a0, 0x24
    ctx->pc = 0x132554u;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)36 << 16));
    // 0x132558: 0xc04a034  jal         func_1280D0
    ctx->pc = 0x132558u;
    SET_GPR_U32(ctx, 31, 0x132560u);
    ctx->pc = 0x13255Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x132558u;
            // 0x13255c: 0x2484aff8  addiu       $a0, $a0, -0x5008 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 4294946808));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1280D0u;
    if (runtime->hasFunction(0x1280D0u)) {
        auto targetFn = runtime->lookupFunction(0x1280D0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x132560u; }
        if (ctx->pc != 0x132560u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001280D0_0x1280d0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x132560u; }
        if (ctx->pc != 0x132560u) { return; }
    }
    ctx->pc = 0x132560u;
label_132560:
    // 0x132560: 0x10000009  b           . + 4 + (0x9 << 2)
    ctx->pc = 0x132560u;
    {
        const bool branch_taken_0x132560 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x132564u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x132560u;
            // 0x132564: 0x2402ffff  addiu       $v0, $zero, -0x1 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
        ctx->in_delay_slot = false;
        if (branch_taken_0x132560) {
            ctx->pc = 0x132588u;
            goto label_132588;
        }
    }
    ctx->pc = 0x132568u;
label_132568:
    // 0x132568: 0x80820001  lb          $v0, 0x1($a0)
    ctx->pc = 0x132568u;
    SET_GPR_S32(ctx, 2, (int8_t)READ8(ADD32(GPR_U32(ctx, 4), 1)));
    // 0x13256c: 0x28420002  slti        $v0, $v0, 0x2
    ctx->pc = 0x13256cu;
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 2) < (int64_t)(int32_t)2) ? 1 : 0);
    // 0x132570: 0x54400005  bnel        $v0, $zero, . + 4 + (0x5 << 2)
    ctx->pc = 0x132570u;
    {
        const bool branch_taken_0x132570 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x132570) {
            ctx->pc = 0x132574u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x132570u;
            // 0x132574: 0x102d  daddu       $v0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
            ctx->pc = 0x132588u;
            goto label_132588;
        }
    }
    ctx->pc = 0x132578u;
    // 0x132578: 0x8c840004  lw          $a0, 0x4($a0)
    ctx->pc = 0x132578u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 4)));
    // 0x13257c: 0xdfbf0000  ld          $ra, 0x0($sp)
    ctx->pc = 0x13257cu;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x132580: 0x804b5ea  j           func_12D7A8
    ctx->pc = 0x132580u;
    ctx->pc = 0x132584u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x132580u;
            // 0x132584: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
    ctx->pc = 0x12D7A8u;
    if (runtime->hasFunction(0x12D7A8u)) {
        auto targetFn = runtime->lookupFunction(0x12D7A8u);
        targetFn(rdram, ctx, runtime); return;
    } else {
        sub_0012D7A8_0x12d7a8(rdram, ctx, runtime); return;
    }
    ctx->pc = 0x132588u;
label_132588:
    // 0x132588: 0xdfbf0000  ld          $ra, 0x0($sp)
    ctx->pc = 0x132588u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x13258c: 0x3e00008  jr          $ra
    ctx->pc = 0x13258Cu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x132590u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x13258Cu;
            // 0x132590: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x132560u: goto label_132560;
            case 0x132568u: goto label_132568;
            case 0x132588u: goto label_132588;
            case 0x1325B0u: goto label_1325b0;
            case 0x1325B8u: goto label_1325b8;
            case 0x1325D8u: goto label_1325d8;
            case 0x132600u: goto label_132600;
            case 0x132608u: goto label_132608;
            case 0x132628u: goto label_132628;
            case 0x132680u: goto label_132680;
            case 0x132688u: goto label_132688;
            case 0x1326C8u: goto label_1326c8;
            case 0x1326D0u: goto label_1326d0;
            case 0x1326D8u: goto label_1326d8;
            case 0x1326DCu: goto label_1326dc;
            default: break;
        }
        return;
    }
    ctx->pc = 0x132594u;
    // 0x132594: 0x0  nop
    ctx->pc = 0x132594u;
    // NOP
    // 0x132598: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x132598u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x13259c: 0x14800006  bnez        $a0, . + 4 + (0x6 << 2)
    ctx->pc = 0x13259Cu;
    {
        const bool branch_taken_0x13259c = (GPR_U64(ctx, 4) != GPR_U64(ctx, 0));
        ctx->pc = 0x1325A0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x13259Cu;
            // 0x1325a0: 0xffbf0000  sd          $ra, 0x0($sp) (Delay Slot)
        WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 31));
        ctx->in_delay_slot = false;
        if (branch_taken_0x13259c) {
            ctx->pc = 0x1325B8u;
            goto label_1325b8;
        }
    }
    ctx->pc = 0x1325A4u;
    // 0x1325a4: 0x3c040024  lui         $a0, 0x24
    ctx->pc = 0x1325a4u;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)36 << 16));
    // 0x1325a8: 0xc04a034  jal         func_1280D0
    ctx->pc = 0x1325A8u;
    SET_GPR_U32(ctx, 31, 0x1325B0u);
    ctx->pc = 0x1325ACu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1325A8u;
            // 0x1325ac: 0x2484b028  addiu       $a0, $a0, -0x4FD8 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 4294946856));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1280D0u;
    if (runtime->hasFunction(0x1280D0u)) {
        auto targetFn = runtime->lookupFunction(0x1280D0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1325B0u; }
        if (ctx->pc != 0x1325B0u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001280D0_0x1280d0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1325B0u; }
        if (ctx->pc != 0x1325B0u) { return; }
    }
    ctx->pc = 0x1325B0u;
label_1325b0:
    // 0x1325b0: 0x10000009  b           . + 4 + (0x9 << 2)
    ctx->pc = 0x1325B0u;
    {
        const bool branch_taken_0x1325b0 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1325B4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1325B0u;
            // 0x1325b4: 0x2402ffff  addiu       $v0, $zero, -0x1 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1325b0) {
            ctx->pc = 0x1325D8u;
            goto label_1325d8;
        }
    }
    ctx->pc = 0x1325B8u;
label_1325b8:
    // 0x1325b8: 0x80820001  lb          $v0, 0x1($a0)
    ctx->pc = 0x1325b8u;
    SET_GPR_S32(ctx, 2, (int8_t)READ8(ADD32(GPR_U32(ctx, 4), 1)));
    // 0x1325bc: 0x28420002  slti        $v0, $v0, 0x2
    ctx->pc = 0x1325bcu;
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 2) < (int64_t)(int32_t)2) ? 1 : 0);
    // 0x1325c0: 0x54400005  bnel        $v0, $zero, . + 4 + (0x5 << 2)
    ctx->pc = 0x1325C0u;
    {
        const bool branch_taken_0x1325c0 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x1325c0) {
            ctx->pc = 0x1325C4u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x1325C0u;
            // 0x1325c4: 0x102d  daddu       $v0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
            ctx->pc = 0x1325D8u;
            goto label_1325d8;
        }
    }
    ctx->pc = 0x1325C8u;
    // 0x1325c8: 0x8c840004  lw          $a0, 0x4($a0)
    ctx->pc = 0x1325c8u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 4)));
    // 0x1325cc: 0xdfbf0000  ld          $ra, 0x0($sp)
    ctx->pc = 0x1325ccu;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1325d0: 0x804b684  j           func_12DA10
    ctx->pc = 0x1325D0u;
    ctx->pc = 0x1325D4u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1325D0u;
            // 0x1325d4: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
    ctx->pc = 0x12DA10u;
    {
        auto targetFn = runtime->lookupFunction(0x12DA10u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        return;
    }
    ctx->pc = 0x1325D8u;
label_1325d8:
    // 0x1325d8: 0xdfbf0000  ld          $ra, 0x0($sp)
    ctx->pc = 0x1325d8u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1325dc: 0x3e00008  jr          $ra
    ctx->pc = 0x1325DCu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1325E0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1325DCu;
            // 0x1325e0: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x132560u: goto label_132560;
            case 0x132568u: goto label_132568;
            case 0x132588u: goto label_132588;
            case 0x1325B0u: goto label_1325b0;
            case 0x1325B8u: goto label_1325b8;
            case 0x1325D8u: goto label_1325d8;
            case 0x132600u: goto label_132600;
            case 0x132608u: goto label_132608;
            case 0x132628u: goto label_132628;
            case 0x132680u: goto label_132680;
            case 0x132688u: goto label_132688;
            case 0x1326C8u: goto label_1326c8;
            case 0x1326D0u: goto label_1326d0;
            case 0x1326D8u: goto label_1326d8;
            case 0x1326DCu: goto label_1326dc;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1325E4u;
    // 0x1325e4: 0x0  nop
    ctx->pc = 0x1325e4u;
    // NOP
    // 0x1325e8: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x1325e8u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x1325ec: 0x14800006  bnez        $a0, . + 4 + (0x6 << 2)
    ctx->pc = 0x1325ECu;
    {
        const bool branch_taken_0x1325ec = (GPR_U64(ctx, 4) != GPR_U64(ctx, 0));
        ctx->pc = 0x1325F0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1325ECu;
            // 0x1325f0: 0xffbf0000  sd          $ra, 0x0($sp) (Delay Slot)
        WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 31));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1325ec) {
            ctx->pc = 0x132608u;
            goto label_132608;
        }
    }
    ctx->pc = 0x1325F4u;
    // 0x1325f4: 0x3c040024  lui         $a0, 0x24
    ctx->pc = 0x1325f4u;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)36 << 16));
    // 0x1325f8: 0xc04a034  jal         func_1280D0
    ctx->pc = 0x1325F8u;
    SET_GPR_U32(ctx, 31, 0x132600u);
    ctx->pc = 0x1325FCu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1325F8u;
            // 0x1325fc: 0x2484b058  addiu       $a0, $a0, -0x4FA8 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 4294946904));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1280D0u;
    if (runtime->hasFunction(0x1280D0u)) {
        auto targetFn = runtime->lookupFunction(0x1280D0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x132600u; }
        if (ctx->pc != 0x132600u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001280D0_0x1280d0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x132600u; }
        if (ctx->pc != 0x132600u) { return; }
    }
    ctx->pc = 0x132600u;
label_132600:
    // 0x132600: 0x10000009  b           . + 4 + (0x9 << 2)
    ctx->pc = 0x132600u;
    {
        const bool branch_taken_0x132600 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x132604u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x132600u;
            // 0x132604: 0x2402ffff  addiu       $v0, $zero, -0x1 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
        ctx->in_delay_slot = false;
        if (branch_taken_0x132600) {
            ctx->pc = 0x132628u;
            goto label_132628;
        }
    }
    ctx->pc = 0x132608u;
label_132608:
    // 0x132608: 0x80820001  lb          $v0, 0x1($a0)
    ctx->pc = 0x132608u;
    SET_GPR_S32(ctx, 2, (int8_t)READ8(ADD32(GPR_U32(ctx, 4), 1)));
    // 0x13260c: 0x28420002  slti        $v0, $v0, 0x2
    ctx->pc = 0x13260cu;
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 2) < (int64_t)(int32_t)2) ? 1 : 0);
    // 0x132610: 0x54400005  bnel        $v0, $zero, . + 4 + (0x5 << 2)
    ctx->pc = 0x132610u;
    {
        const bool branch_taken_0x132610 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x132610) {
            ctx->pc = 0x132614u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x132610u;
            // 0x132614: 0x102d  daddu       $v0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
            ctx->pc = 0x132628u;
            goto label_132628;
        }
    }
    ctx->pc = 0x132618u;
    // 0x132618: 0x8c840004  lw          $a0, 0x4($a0)
    ctx->pc = 0x132618u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 4)));
    // 0x13261c: 0xdfbf0000  ld          $ra, 0x0($sp)
    ctx->pc = 0x13261cu;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x132620: 0x804b686  j           func_12DA18
    ctx->pc = 0x132620u;
    ctx->pc = 0x132624u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x132620u;
            // 0x132624: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
    ctx->pc = 0x12DA18u;
    if (runtime->hasFunction(0x12DA18u)) {
        auto targetFn = runtime->lookupFunction(0x12DA18u);
        targetFn(rdram, ctx, runtime); return;
    } else {
        sub_0012DA18_0x12da18(rdram, ctx, runtime); return;
    }
    ctx->pc = 0x132628u;
label_132628:
    // 0x132628: 0xdfbf0000  ld          $ra, 0x0($sp)
    ctx->pc = 0x132628u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x13262c: 0x3e00008  jr          $ra
    ctx->pc = 0x13262Cu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x132630u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x13262Cu;
            // 0x132630: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x132560u: goto label_132560;
            case 0x132568u: goto label_132568;
            case 0x132588u: goto label_132588;
            case 0x1325B0u: goto label_1325b0;
            case 0x1325B8u: goto label_1325b8;
            case 0x1325D8u: goto label_1325d8;
            case 0x132600u: goto label_132600;
            case 0x132608u: goto label_132608;
            case 0x132628u: goto label_132628;
            case 0x132680u: goto label_132680;
            case 0x132688u: goto label_132688;
            case 0x1326C8u: goto label_1326c8;
            case 0x1326D0u: goto label_1326d0;
            case 0x1326D8u: goto label_1326d8;
            case 0x1326DCu: goto label_1326dc;
            default: break;
        }
        return;
    }
    ctx->pc = 0x132634u;
    // 0x132634: 0x0  nop
    ctx->pc = 0x132634u;
    // NOP
    // 0x132638: 0x27bdffe0  addiu       $sp, $sp, -0x20
    ctx->pc = 0x132638u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967264));
    // 0x13263c: 0xffb00000  sd          $s0, 0x0($sp)
    ctx->pc = 0x13263cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x132640: 0x80802d  daddu       $s0, $a0, $zero
    ctx->pc = 0x132640u;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x132644: 0xffb10008  sd          $s1, 0x8($sp)
    ctx->pc = 0x132644u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 8), GPR_U64(ctx, 17));
    // 0x132648: 0xa0882d  daddu       $s1, $a1, $zero
    ctx->pc = 0x132648u;
    SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
    // 0x13264c: 0xffb20010  sd          $s2, 0x10($sp)
    ctx->pc = 0x13264cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 18));
    // 0x132650: 0xc0902d  daddu       $s2, $a2, $zero
    ctx->pc = 0x132650u;
    SET_GPR_U64(ctx, 18, (uint64_t)GPR_U64(ctx, 6) + (uint64_t)GPR_U64(ctx, 0));
    // 0x132654: 0x1600000a  bnez        $s0, . + 4 + (0xA << 2)
    ctx->pc = 0x132654u;
    {
        const bool branch_taken_0x132654 = (GPR_U64(ctx, 16) != GPR_U64(ctx, 0));
        ctx->pc = 0x132658u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x132654u;
            // 0x132658: 0xffbf0018  sd          $ra, 0x18($sp) (Delay Slot)
        WRITE64(ADD32(GPR_U32(ctx, 29), 24), GPR_U64(ctx, 31));
        ctx->in_delay_slot = false;
        if (branch_taken_0x132654) {
            ctx->pc = 0x132680u;
            goto label_132680;
        }
    }
    ctx->pc = 0x13265Cu;
    // 0x13265c: 0x3c040024  lui         $a0, 0x24
    ctx->pc = 0x13265cu;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)36 << 16));
    // 0x132660: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x132660u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x132664: 0xdfb10008  ld          $s1, 0x8($sp)
    ctx->pc = 0x132664u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x132668: 0x2484b088  addiu       $a0, $a0, -0x4F78
    ctx->pc = 0x132668u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 4294946952));
    // 0x13266c: 0xdfb20010  ld          $s2, 0x10($sp)
    ctx->pc = 0x13266cu;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x132670: 0xdfbf0018  ld          $ra, 0x18($sp)
    ctx->pc = 0x132670u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 24)));
    // 0x132674: 0x804a034  j           func_1280D0
    ctx->pc = 0x132674u;
    ctx->pc = 0x132678u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x132674u;
            // 0x132678: 0x27bd0020  addiu       $sp, $sp, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1280D0u;
    if (runtime->hasFunction(0x1280D0u)) {
        auto targetFn = runtime->lookupFunction(0x1280D0u);
        targetFn(rdram, ctx, runtime); return;
    } else {
        sub_001280D0_0x1280d0(rdram, ctx, runtime); return;
    }
    ctx->pc = 0x13267Cu;
    // 0x13267c: 0x0  nop
    ctx->pc = 0x13267cu;
    // NOP
label_132680:
    // 0x132680: 0xc04b654  jal         func_12D950
    ctx->pc = 0x132680u;
    SET_GPR_U32(ctx, 31, 0x132688u);
    ctx->pc = 0x132684u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x132680u;
            // 0x132684: 0x8e040004  lw          $a0, 0x4($s0) (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 4)));
        ctx->in_delay_slot = false;
    ctx->pc = 0x12D950u;
    if (runtime->hasFunction(0x12D950u)) {
        auto targetFn = runtime->lookupFunction(0x12D950u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x132688u; }
        if (ctx->pc != 0x132688u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0012D950_0x12d950(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x132688u; }
        if (ctx->pc != 0x132688u) { return; }
    }
    ctx->pc = 0x132688u;
label_132688:
    // 0x132688: 0x3c040024  lui         $a0, 0x24
    ctx->pc = 0x132688u;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)36 << 16));
    // 0x13268c: 0x2403ff80  addiu       $v1, $zero, -0x80
    ctx->pc = 0x13268cu;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967168));
    // 0x132690: 0x113840  sll         $a3, $s1, 1
    ctx->pc = 0x132690u;
    SET_GPR_S32(ctx, 7, (int32_t)SLL32(GPR_U32(ctx, 17), 1));
    // 0x132694: 0x431826  xor         $v1, $v0, $v1
    ctx->pc = 0x132694u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 2) ^ GPR_U64(ctx, 3));
    // 0x132698: 0xf03821  addu        $a3, $a3, $s0
    ctx->pc = 0x132698u;
    SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 7), GPR_U32(ctx, 16)));
    // 0x13269c: 0x3100a  movz        $v0, $zero, $v1
    ctx->pc = 0x13269cu;
    if (GPR_U64(ctx, 3) == 0) SET_GPR_VEC(ctx, 2, GPR_VEC(ctx, 0));
    // 0x1326a0: 0x220282d  daddu       $a1, $s1, $zero
    ctx->pc = 0x1326a0u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1326a4: 0x521021  addu        $v0, $v0, $s2
    ctx->pc = 0x1326a4u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 18)));
    // 0x1326a8: 0x240302d  daddu       $a2, $s2, $zero
    ctx->pc = 0x1326a8u;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 18) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1326ac: 0xa4e20042  sh          $v0, 0x42($a3)
    ctx->pc = 0x1326acu;
    WRITE16(ADD32(GPR_U32(ctx, 7), 66), (uint16_t)GPR_U32(ctx, 2));
    // 0x1326b0: 0x82020003  lb          $v0, 0x3($s0)
    ctx->pc = 0x1326b0u;
    SET_GPR_S32(ctx, 2, (int8_t)READ8(ADD32(GPR_U32(ctx, 16), 3)));
    // 0x1326b4: 0x222102a  slt         $v0, $s1, $v0
    ctx->pc = 0x1326b4u;
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 17) < (int64_t)GPR_S64(ctx, 2)) ? 1 : 0);
    // 0x1326b8: 0x10400005  beqz        $v0, . + 4 + (0x5 << 2)
    ctx->pc = 0x1326B8u;
    {
        const bool branch_taken_0x1326b8 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x1326BCu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1326B8u;
            // 0x1326bc: 0x2484b0b8  addiu       $a0, $a0, -0x4F48 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 4294947000));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1326b8) {
            ctx->pc = 0x1326D0u;
            goto label_1326d0;
        }
    }
    ctx->pc = 0x1326C0u;
    // 0x1326c0: 0xc04b204  jal         func_12C810
    ctx->pc = 0x1326C0u;
    SET_GPR_U32(ctx, 31, 0x1326C8u);
    ctx->pc = 0x1326C4u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1326C0u;
            // 0x1326c4: 0x8e04000c  lw          $a0, 0xC($s0) (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 12)));
        ctx->in_delay_slot = false;
    ctx->pc = 0x12C810u;
    if (runtime->hasFunction(0x12C810u)) {
        auto targetFn = runtime->lookupFunction(0x12C810u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1326C8u; }
        if (ctx->pc != 0x1326C8u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0012C810_0x12c810(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1326C8u; }
        if (ctx->pc != 0x1326C8u) { return; }
    }
    ctx->pc = 0x1326C8u;
label_1326c8:
    // 0x1326c8: 0x10000004  b           . + 4 + (0x4 << 2)
    ctx->pc = 0x1326C8u;
    {
        const bool branch_taken_0x1326c8 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1326CCu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1326C8u;
            // 0x1326cc: 0xdfb00000  ld          $s0, 0x0($sp) (Delay Slot)
        SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1326c8) {
            ctx->pc = 0x1326DCu;
            goto label_1326dc;
        }
    }
    ctx->pc = 0x1326D0u;
label_1326d0:
    // 0x1326d0: 0xc04a034  jal         func_1280D0
    ctx->pc = 0x1326D0u;
    SET_GPR_U32(ctx, 31, 0x1326D8u);
    ctx->pc = 0x1280D0u;
    if (runtime->hasFunction(0x1280D0u)) {
        auto targetFn = runtime->lookupFunction(0x1280D0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1326D8u; }
        if (ctx->pc != 0x1326D8u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001280D0_0x1280d0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1326D8u; }
        if (ctx->pc != 0x1326D8u) { return; }
    }
    ctx->pc = 0x1326D8u;
label_1326d8:
    // 0x1326d8: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x1326d8u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
label_1326dc:
    // 0x1326dc: 0xdfb10008  ld          $s1, 0x8($sp)
    ctx->pc = 0x1326dcu;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x1326e0: 0xdfb20010  ld          $s2, 0x10($sp)
    ctx->pc = 0x1326e0u;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x1326e4: 0xdfbf0018  ld          $ra, 0x18($sp)
    ctx->pc = 0x1326e4u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 24)));
    // 0x1326e8: 0x3e00008  jr          $ra
    ctx->pc = 0x1326E8u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1326ECu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1326E8u;
            // 0x1326ec: 0x27bd0020  addiu       $sp, $sp, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x132560u: goto label_132560;
            case 0x132568u: goto label_132568;
            case 0x132588u: goto label_132588;
            case 0x1325B0u: goto label_1325b0;
            case 0x1325B8u: goto label_1325b8;
            case 0x1325D8u: goto label_1325d8;
            case 0x132600u: goto label_132600;
            case 0x132608u: goto label_132608;
            case 0x132628u: goto label_132628;
            case 0x132680u: goto label_132680;
            case 0x132688u: goto label_132688;
            case 0x1326C8u: goto label_1326c8;
            case 0x1326D0u: goto label_1326d0;
            case 0x1326D8u: goto label_1326d8;
            case 0x1326DCu: goto label_1326dc;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1326F0u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
