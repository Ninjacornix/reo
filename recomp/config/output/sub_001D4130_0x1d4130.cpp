#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001D4130
// Address: 0x1d4130 - 0x1d41e8
void sub_001D4130_0x1d4130(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001D4130_0x1d4130");
#endif

    switch (ctx->pc) {
        case 0x1d4190u: goto label_1d4190;
        case 0x1d41a4u: goto label_1d41a4;
        case 0x1d41c0u: goto label_1d41c0;
        case 0x1d41ccu: goto label_1d41cc;
        default: break;
    }

    ctx->pc = 0x1d4130u;

    // 0x1d4130: 0x27bdff60  addiu       $sp, $sp, -0xA0
    ctx->pc = 0x1d4130u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967136));
    // 0x1d4134: 0x3c050032  lui         $a1, 0x32
    ctx->pc = 0x1d4134u;
    SET_GPR_S32(ctx, 5, (int32_t)((uint32_t)50 << 16));
    // 0x1d4138: 0xffbf0010  sd          $ra, 0x10($sp)
    ctx->pc = 0x1d4138u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 31));
    // 0x1d413c: 0x24a543c0  addiu       $a1, $a1, 0x43C0
    ctx->pc = 0x1d413cu;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 17344));
    // 0x1d4140: 0x10800006  beqz        $a0, . + 4 + (0x6 << 2)
    ctx->pc = 0x1D4140u;
    {
        const bool branch_taken_0x1d4140 = (GPR_U64(ctx, 4) == GPR_U64(ctx, 0));
        ctx->pc = 0x1D4144u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1D4140u;
            // 0x1d4144: 0x7fb00000  sq          $s0, 0x0($sp) (Delay Slot)
        WRITE128(ADD32(GPR_U32(ctx, 29), 0), GPR_VEC(ctx, 16));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1d4140) {
            ctx->pc = 0x1D415Cu;
            goto label_1d415c;
        }
    }
    ctx->pc = 0x1D4148u;
    // 0x1d4148: 0x3c010032  lui         $at, 0x32
    ctx->pc = 0x1d4148u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)50 << 16));
    // 0x1d414c: 0x3c020001  lui         $v0, 0x1
    ctx->pc = 0x1d414cu;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)1 << 16));
    // 0x1d4150: 0x8c23442c  lw          $v1, 0x442C($at)
    ctx->pc = 0x1d4150u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 1), 17452)));
    // 0x1d4154: 0x10000003  b           . + 4 + (0x3 << 2)
    ctx->pc = 0x1D4154u;
    {
        const bool branch_taken_0x1d4154 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1D4158u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1D4154u;
            // 0x1d4158: 0x628021  addu        $s0, $v1, $v0 (Delay Slot)
        SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 2)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1d4154) {
            ctx->pc = 0x1D4164u;
            goto label_1d4164;
        }
    }
    ctx->pc = 0x1D415Cu;
label_1d415c:
    // 0x1d415c: 0x3c010032  lui         $at, 0x32
    ctx->pc = 0x1d415cu;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)50 << 16));
    // 0x1d4160: 0x8c304438  lw          $s0, 0x4438($at)
    ctx->pc = 0x1d4160u;
    SET_GPR_S32(ctx, 16, (int32_t)READ32(ADD32(GPR_U32(ctx, 1), 17464)));
label_1d4164:
    // 0x1d4164: 0x3c010032  lui         $at, 0x32
    ctx->pc = 0x1d4164u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)50 << 16));
    // 0x1d4168: 0x802243d7  lb          $v0, 0x43D7($at)
    ctx->pc = 0x1d4168u;
    SET_GPR_S32(ctx, 2, (int8_t)READ8(ADD32(GPR_U32(ctx, 1), 17367)));
    // 0x1d416c: 0x1440000f  bnez        $v0, . + 4 + (0xF << 2)
    ctx->pc = 0x1D416Cu;
    {
        const bool branch_taken_0x1d416c = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x1d416c) {
            ctx->pc = 0x1D41ACu;
            goto label_1d41ac;
        }
    }
    ctx->pc = 0x1D4174u;
    // 0x1d4174: 0x94a7001a  lhu         $a3, 0x1A($a1)
    ctx->pc = 0x1d4174u;
    SET_GPR_U32(ctx, 7, (uint16_t)READ16(ADD32(GPR_U32(ctx, 5), 26)));
    // 0x1d4178: 0x3c060025  lui         $a2, 0x25
    ctx->pc = 0x1d4178u;
    SET_GPR_S32(ctx, 6, (int32_t)((uint32_t)37 << 16));
    // 0x1d417c: 0x27a40020  addiu       $a0, $sp, 0x20
    ctx->pc = 0x1d417cu;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
    // 0x1d4180: 0x24c667a8  addiu       $a2, $a2, 0x67A8
    ctx->pc = 0x1d4180u;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 6), 26536));
    // 0x1d4184: 0x3c050025  lui         $a1, 0x25
    ctx->pc = 0x1d4184u;
    SET_GPR_S32(ctx, 5, (int32_t)((uint32_t)37 << 16));
    // 0x1d4188: 0xc042a0c  jal         func_10A830
    ctx->pc = 0x1D4188u;
    SET_GPR_U32(ctx, 31, 0x1D4190u);
    ctx->pc = 0x1D418Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1D4188u;
            // 0x1d418c: 0x24a56798  addiu       $a1, $a1, 0x6798 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 26520));
        ctx->in_delay_slot = false;
    ctx->pc = 0x10A830u;
    if (runtime->hasFunction(0x10A830u)) {
        auto targetFn = runtime->lookupFunction(0x10A830u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D4190u; }
        if (ctx->pc != 0x1D4190u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0010A830_0x10a830(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D4190u; }
        if (ctx->pc != 0x1D4190u) { return; }
    }
    ctx->pc = 0x1D4190u;
label_1d4190:
    // 0x1d4190: 0x27a40020  addiu       $a0, $sp, 0x20
    ctx->pc = 0x1d4190u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
    // 0x1d4194: 0x200282d  daddu       $a1, $s0, $zero
    ctx->pc = 0x1d4194u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1d4198: 0x24060001  addiu       $a2, $zero, 0x1
    ctx->pc = 0x1d4198u;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x1d419c: 0xc07323c  jal         func_1CC8F0
    ctx->pc = 0x1D419Cu;
    SET_GPR_U32(ctx, 31, 0x1D41A4u);
    ctx->pc = 0x1D41A0u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1D419Cu;
            // 0x1d41a0: 0x382d  daddu       $a3, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 7, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1CC8F0u;
    if (runtime->hasFunction(0x1CC8F0u)) {
        auto targetFn = runtime->lookupFunction(0x1CC8F0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D41A4u; }
        if (ctx->pc != 0x1D41A4u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001CC8F0_0x1cc8f0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D41A4u; }
        if (ctx->pc != 0x1D41A4u) { return; }
    }
    ctx->pc = 0x1D41A4u;
label_1d41a4:
    // 0x1d41a4: 0x10000009  b           . + 4 + (0x9 << 2)
    ctx->pc = 0x1D41A4u;
    {
        const bool branch_taken_0x1d41a4 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x1d41a4) {
            ctx->pc = 0x1D41CCu;
            goto label_1d41cc;
        }
    }
    ctx->pc = 0x1D41ACu;
label_1d41ac:
    // 0x1d41ac: 0x94a6001a  lhu         $a2, 0x1A($a1)
    ctx->pc = 0x1d41acu;
    SET_GPR_U32(ctx, 6, (uint16_t)READ16(ADD32(GPR_U32(ctx, 5), 26)));
    // 0x1d41b0: 0x27a40020  addiu       $a0, $sp, 0x20
    ctx->pc = 0x1d41b0u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
    // 0x1d41b4: 0x3c050025  lui         $a1, 0x25
    ctx->pc = 0x1d41b4u;
    SET_GPR_S32(ctx, 5, (int32_t)((uint32_t)37 << 16));
    // 0x1d41b8: 0xc042a0c  jal         func_10A830
    ctx->pc = 0x1D41B8u;
    SET_GPR_U32(ctx, 31, 0x1D41C0u);
    ctx->pc = 0x1D41BCu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1D41B8u;
            // 0x1d41bc: 0x24a567b8  addiu       $a1, $a1, 0x67B8 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 26552));
        ctx->in_delay_slot = false;
    ctx->pc = 0x10A830u;
    if (runtime->hasFunction(0x10A830u)) {
        auto targetFn = runtime->lookupFunction(0x10A830u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D41C0u; }
        if (ctx->pc != 0x1D41C0u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0010A830_0x10a830(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D41C0u; }
        if (ctx->pc != 0x1D41C0u) { return; }
    }
    ctx->pc = 0x1D41C0u;
label_1d41c0:
    // 0x1d41c0: 0x27a40020  addiu       $a0, $sp, 0x20
    ctx->pc = 0x1d41c0u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
    // 0x1d41c4: 0xc06a8f8  jal         func_1AA3E0
    ctx->pc = 0x1D41C4u;
    SET_GPR_U32(ctx, 31, 0x1D41CCu);
    ctx->pc = 0x1D41C8u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1D41C4u;
            // 0x1d41c8: 0x200282d  daddu       $a1, $s0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1AA3E0u;
    if (runtime->hasFunction(0x1AA3E0u)) {
        auto targetFn = runtime->lookupFunction(0x1AA3E0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D41CCu; }
        if (ctx->pc != 0x1D41CCu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001AA3E0_0x1aa3e0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D41CCu; }
        if (ctx->pc != 0x1D41CCu) { return; }
    }
    ctx->pc = 0x1D41CCu;
label_1d41cc:
    // 0x1d41cc: 0x1c400002  bgtz        $v0, . + 4 + (0x2 << 2)
    ctx->pc = 0x1D41CCu;
    {
        const bool branch_taken_0x1d41cc = (GPR_S64(ctx, 2) > 0);
        if (branch_taken_0x1d41cc) {
            ctx->pc = 0x1D41D8u;
            goto label_1d41d8;
        }
    }
    ctx->pc = 0x1D41D4u;
    // 0x1d41d4: 0xae000000  sw          $zero, 0x0($s0)
    ctx->pc = 0x1d41d4u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 0), GPR_U32(ctx, 0));
label_1d41d8:
    // 0x1d41d8: 0xdfbf0010  ld          $ra, 0x10($sp)
    ctx->pc = 0x1d41d8u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x1d41dc: 0x7bb00000  lq          $s0, 0x0($sp)
    ctx->pc = 0x1d41dcu;
    SET_GPR_VEC(ctx, 16, READ128(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1d41e0: 0x3e00008  jr          $ra
    ctx->pc = 0x1D41E0u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1D41E4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1D41E0u;
            // 0x1d41e4: 0x27bd00a0  addiu       $sp, $sp, 0xA0 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 160));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1D415Cu: goto label_1d415c;
            case 0x1D4164u: goto label_1d4164;
            case 0x1D4190u: goto label_1d4190;
            case 0x1D41A4u: goto label_1d41a4;
            case 0x1D41ACu: goto label_1d41ac;
            case 0x1D41C0u: goto label_1d41c0;
            case 0x1D41CCu: goto label_1d41cc;
            case 0x1D41D8u: goto label_1d41d8;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1D41E8u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
