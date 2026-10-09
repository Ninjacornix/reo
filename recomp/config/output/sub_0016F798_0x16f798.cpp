#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_0016F798
// Address: 0x16f798 - 0x16f930
void sub_0016F798_0x16f798(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_0016F798_0x16f798");
#endif

    switch (ctx->pc) {
        case 0x16f7bcu: goto label_16f7bc;
        case 0x16f7d0u: goto label_16f7d0;
        case 0x16f7e0u: goto label_16f7e0;
        case 0x16f7e8u: goto label_16f7e8;
        case 0x16f830u: goto label_16f830;
        case 0x16f840u: goto label_16f840;
        case 0x16f870u: goto label_16f870;
        case 0x16f880u: goto label_16f880;
        case 0x16f88cu: goto label_16f88c;
        case 0x16f89cu: goto label_16f89c;
        case 0x16f8acu: goto label_16f8ac;
        case 0x16f8bcu: goto label_16f8bc;
        case 0x16f8ccu: goto label_16f8cc;
        case 0x16f8dcu: goto label_16f8dc;
        case 0x16f8f0u: goto label_16f8f0;
        case 0x16f900u: goto label_16f900;
        case 0x16f910u: goto label_16f910;
        default: break;
    }

    ctx->pc = 0x16f798u;

    // 0x16f798: 0x27bdffe0  addiu       $sp, $sp, -0x20
    ctx->pc = 0x16f798u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967264));
    // 0x16f79c: 0x24050005  addiu       $a1, $zero, 0x5
    ctx->pc = 0x16f79cu;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 5));
    // 0x16f7a0: 0xffb10008  sd          $s1, 0x8($sp)
    ctx->pc = 0x16f7a0u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 8), GPR_U64(ctx, 17));
    // 0x16f7a4: 0x80882d  daddu       $s1, $a0, $zero
    ctx->pc = 0x16f7a4u;
    SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x16f7a8: 0xffb20010  sd          $s2, 0x10($sp)
    ctx->pc = 0x16f7a8u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 18));
    // 0x16f7ac: 0xffb00000  sd          $s0, 0x0($sp)
    ctx->pc = 0x16f7acu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x16f7b0: 0xffbf0018  sd          $ra, 0x18($sp)
    ctx->pc = 0x16f7b0u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 24), GPR_U64(ctx, 31));
    // 0x16f7b4: 0xc05d58a  jal         func_175628
    ctx->pc = 0x16F7B4u;
    SET_GPR_U32(ctx, 31, 0x16F7BCu);
    ctx->pc = 0x16F7B8u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x16F7B4u;
            // 0x16f7b8: 0x26321f00  addiu       $s2, $s1, 0x1F00 (Delay Slot)
        SET_GPR_S32(ctx, 18, (int32_t)ADD32(GPR_U32(ctx, 17), 7936));
        ctx->in_delay_slot = false;
    ctx->pc = 0x175628u;
    if (runtime->hasFunction(0x175628u)) {
        auto targetFn = runtime->lookupFunction(0x175628u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x16F7BCu; }
        if (ctx->pc != 0x16F7BCu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00175628_0x175628(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x16F7BCu; }
        if (ctx->pc != 0x16F7BCu) { return; }
    }
    ctx->pc = 0x16F7BCu;
label_16f7bc:
    // 0x16f7bc: 0x240282d  daddu       $a1, $s2, $zero
    ctx->pc = 0x16f7bcu;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 18) + (uint64_t)GPR_U64(ctx, 0));
    // 0x16f7c0: 0x10400055  beqz        $v0, . + 4 + (0x55 << 2)
    ctx->pc = 0x16F7C0u;
    {
        const bool branch_taken_0x16f7c0 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x16F7C4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x16F7C0u;
            // 0x16f7c4: 0x220202d  daddu       $a0, $s1, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x16f7c0) {
            ctx->pc = 0x16F918u;
            goto label_16f918;
        }
    }
    ctx->pc = 0x16F7C8u;
    // 0x16f7c8: 0xc05be4c  jal         func_16F930
    ctx->pc = 0x16F7C8u;
    SET_GPR_U32(ctx, 31, 0x16F7D0u);
    ctx->pc = 0x16F7CCu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x16F7C8u;
            // 0x16f7cc: 0xae321b30  sw          $s2, 0x1B30($s1) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 17), 6960), GPR_U32(ctx, 18));
        ctx->in_delay_slot = false;
    ctx->pc = 0x16F930u;
    if (runtime->hasFunction(0x16F930u)) {
        auto targetFn = runtime->lookupFunction(0x16F930u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x16F7D0u; }
        if (ctx->pc != 0x16F7D0u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0016F930_0x16f930(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x16F7D0u; }
        if (ctx->pc != 0x16F7D0u) { return; }
    }
    ctx->pc = 0x16F7D0u;
label_16f7d0:
    // 0x16f7d0: 0x14400051  bnez        $v0, . + 4 + (0x51 << 2)
    ctx->pc = 0x16F7D0u;
    {
        const bool branch_taken_0x16f7d0 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x16F7D4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x16F7D0u;
            // 0x16f7d4: 0x220202d  daddu       $a0, $s1, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x16f7d0) {
            ctx->pc = 0x16F918u;
            goto label_16f918;
        }
    }
    ctx->pc = 0x16F7D8u;
    // 0x16f7d8: 0xc05c57c  jal         func_1715F0
    ctx->pc = 0x16F7D8u;
    SET_GPR_U32(ctx, 31, 0x16F7E0u);
    ctx->pc = 0x1715F0u;
    if (runtime->hasFunction(0x1715F0u)) {
        auto targetFn = runtime->lookupFunction(0x1715F0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x16F7E0u; }
        if (ctx->pc != 0x16F7E0u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001715F0_0x1715f0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x16F7E0u; }
        if (ctx->pc != 0x16F7E0u) { return; }
    }
    ctx->pc = 0x16F7E0u;
label_16f7e0:
    // 0x16f7e0: 0xc056d28  jal         func_15B4A0
    ctx->pc = 0x16F7E0u;
    SET_GPR_U32(ctx, 31, 0x16F7E8u);
    ctx->pc = 0x15B4A0u;
    if (runtime->hasFunction(0x15B4A0u)) {
        auto targetFn = runtime->lookupFunction(0x15B4A0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x16F7E8u; }
        if (ctx->pc != 0x16F7E8u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0015B4A0_0x15b4a0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x16F7E8u; }
        if (ctx->pc != 0x16F7E8u) { return; }
    }
    ctx->pc = 0x16F7E8u;
label_16f7e8:
    // 0x16f7e8: 0x40802d  daddu       $s0, $v0, $zero
    ctx->pc = 0x16f7e8u;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x16f7ec: 0x3c050017  lui         $a1, 0x17
    ctx->pc = 0x16f7ecu;
    SET_GPR_S32(ctx, 5, (int32_t)((uint32_t)23 << 16));
    // 0x16f7f0: 0x24a5fcf8  addiu       $a1, $a1, -0x308
    ctx->pc = 0x16f7f0u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 4294966520));
    // 0x16f7f4: 0x200202d  daddu       $a0, $s0, $zero
    ctx->pc = 0x16f7f4u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x16f7f8: 0x1600000b  bnez        $s0, . + 4 + (0xB << 2)
    ctx->pc = 0x16F7F8u;
    {
        const bool branch_taken_0x16f7f8 = (GPR_U64(ctx, 16) != GPR_U64(ctx, 0));
        ctx->pc = 0x16F7FCu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x16F7F8u;
            // 0x16f7fc: 0x220302d  daddu       $a2, $s1, $zero (Delay Slot)
        SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x16f7f8) {
            ctx->pc = 0x16F828u;
            goto label_16f828;
        }
    }
    ctx->pc = 0x16F800u;
    // 0x16f800: 0x220202d  daddu       $a0, $s1, $zero
    ctx->pc = 0x16f800u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
    // 0x16f804: 0xdfb10008  ld          $s1, 0x8($sp)
    ctx->pc = 0x16f804u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x16f808: 0x3c05ff00  lui         $a1, 0xFF00
    ctx->pc = 0x16f808u;
    SET_GPR_S32(ctx, 5, (int32_t)((uint32_t)65280 << 16));
    // 0x16f80c: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x16f80cu;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x16f810: 0xdfb20010  ld          $s2, 0x10($sp)
    ctx->pc = 0x16f810u;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x16f814: 0x34a50f0a  ori         $a1, $a1, 0xF0A
    ctx->pc = 0x16f814u;
    SET_GPR_U64(ctx, 5, GPR_U64(ctx, 5) | (uint64_t)(uint16_t)3850);
    // 0x16f818: 0xdfbf0018  ld          $ra, 0x18($sp)
    ctx->pc = 0x16f818u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 24)));
    // 0x16f81c: 0x805a704  j           func_169C10
    ctx->pc = 0x16F81Cu;
    ctx->pc = 0x16F820u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x16F81Cu;
            // 0x16f820: 0x27bd0020  addiu       $sp, $sp, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
        ctx->in_delay_slot = false;
    ctx->pc = 0x169C10u;
    if (runtime->hasFunction(0x169C10u)) {
        auto targetFn = runtime->lookupFunction(0x169C10u);
        targetFn(rdram, ctx, runtime); return;
    } else {
        sub_00169C10_0x169c10(rdram, ctx, runtime); return;
    }
    ctx->pc = 0x16F824u;
    // 0x16f824: 0x0  nop
    ctx->pc = 0x16f824u;
    // NOP
label_16f828:
    // 0x16f828: 0xc056392  jal         func_158E48
    ctx->pc = 0x16F828u;
    SET_GPR_U32(ctx, 31, 0x16F830u);
    ctx->pc = 0x158E48u;
    if (runtime->hasFunction(0x158E48u)) {
        auto targetFn = runtime->lookupFunction(0x158E48u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x16F830u; }
        if (ctx->pc != 0x16F830u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00158E48_0x158e48(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x16F830u; }
        if (ctx->pc != 0x16F830u) { return; }
    }
    ctx->pc = 0x16F830u;
label_16f830:
    // 0x16f830: 0x1040000d  beqz        $v0, . + 4 + (0xD << 2)
    ctx->pc = 0x16F830u;
    {
        const bool branch_taken_0x16f830 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x16F834u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x16F830u;
            // 0x16f834: 0x282d  daddu       $a1, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x16f830) {
            ctx->pc = 0x16F868u;
            goto label_16f868;
        }
    }
    ctx->pc = 0x16F838u;
    // 0x16f838: 0xc05bfaa  jal         func_16FEA8
    ctx->pc = 0x16F838u;
    SET_GPR_U32(ctx, 31, 0x16F840u);
    ctx->pc = 0x16F83Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x16F838u;
            // 0x16f83c: 0x200202d  daddu       $a0, $s0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x16FEA8u;
    if (runtime->hasFunction(0x16FEA8u)) {
        auto targetFn = runtime->lookupFunction(0x16FEA8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x16F840u; }
        if (ctx->pc != 0x16F840u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0016FEA8_0x16fea8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x16F840u; }
        if (ctx->pc != 0x16F840u) { return; }
    }
    ctx->pc = 0x16F840u;
label_16f840:
    // 0x16f840: 0x220202d  daddu       $a0, $s1, $zero
    ctx->pc = 0x16f840u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
    // 0x16f844: 0x3c05ff00  lui         $a1, 0xFF00
    ctx->pc = 0x16f844u;
    SET_GPR_S32(ctx, 5, (int32_t)((uint32_t)65280 << 16));
    // 0x16f848: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x16f848u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x16f84c: 0xdfb10008  ld          $s1, 0x8($sp)
    ctx->pc = 0x16f84cu;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x16f850: 0x34a50f0b  ori         $a1, $a1, 0xF0B
    ctx->pc = 0x16f850u;
    SET_GPR_U64(ctx, 5, GPR_U64(ctx, 5) | (uint64_t)(uint16_t)3851);
    // 0x16f854: 0xdfb20010  ld          $s2, 0x10($sp)
    ctx->pc = 0x16f854u;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x16f858: 0xdfbf0018  ld          $ra, 0x18($sp)
    ctx->pc = 0x16f858u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 24)));
    // 0x16f85c: 0x805a704  j           func_169C10
    ctx->pc = 0x16F85Cu;
    ctx->pc = 0x16F860u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x16F85Cu;
            // 0x16f860: 0x27bd0020  addiu       $sp, $sp, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
        ctx->in_delay_slot = false;
    ctx->pc = 0x169C10u;
    if (runtime->hasFunction(0x169C10u)) {
        auto targetFn = runtime->lookupFunction(0x169C10u);
        targetFn(rdram, ctx, runtime); return;
    } else {
        sub_00169C10_0x169c10(rdram, ctx, runtime); return;
    }
    ctx->pc = 0x16F864u;
    // 0x16f864: 0x0  nop
    ctx->pc = 0x16f864u;
    // NOP
label_16f868:
    // 0x16f868: 0xc05d58a  jal         func_175628
    ctx->pc = 0x16F868u;
    SET_GPR_U32(ctx, 31, 0x16F870u);
    ctx->pc = 0x16F86Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x16F868u;
            // 0x16f86c: 0x220202d  daddu       $a0, $s1, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x175628u;
    if (runtime->hasFunction(0x175628u)) {
        auto targetFn = runtime->lookupFunction(0x175628u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x16F870u; }
        if (ctx->pc != 0x16F870u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00175628_0x175628(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x16F870u; }
        if (ctx->pc != 0x16F870u) { return; }
    }
    ctx->pc = 0x16F870u;
label_16f870:
    // 0x16f870: 0x200202d  daddu       $a0, $s0, $zero
    ctx->pc = 0x16f870u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x16f874: 0x40302d  daddu       $a2, $v0, $zero
    ctx->pc = 0x16f874u;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x16f878: 0xc056daa  jal         func_15B6A8
    ctx->pc = 0x16F878u;
    SET_GPR_U32(ctx, 31, 0x16F880u);
    ctx->pc = 0x16F87Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x16F878u;
            // 0x16f87c: 0x24050001  addiu       $a1, $zero, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
        ctx->in_delay_slot = false;
    ctx->pc = 0x15B6A8u;
    if (runtime->hasFunction(0x15B6A8u)) {
        auto targetFn = runtime->lookupFunction(0x15B6A8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x16F880u; }
        if (ctx->pc != 0x16F880u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0015B6A8_0x15b6a8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x16F880u; }
        if (ctx->pc != 0x16F880u) { return; }
    }
    ctx->pc = 0x16F880u;
label_16f880:
    // 0x16f880: 0x220202d  daddu       $a0, $s1, $zero
    ctx->pc = 0x16f880u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
    // 0x16f884: 0xc05d58a  jal         func_175628
    ctx->pc = 0x16F884u;
    SET_GPR_U32(ctx, 31, 0x16F88Cu);
    ctx->pc = 0x16F888u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x16F884u;
            // 0x16f888: 0x24050001  addiu       $a1, $zero, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
        ctx->in_delay_slot = false;
    ctx->pc = 0x175628u;
    if (runtime->hasFunction(0x175628u)) {
        auto targetFn = runtime->lookupFunction(0x175628u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x16F88Cu; }
        if (ctx->pc != 0x16F88Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00175628_0x175628(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x16F88Cu; }
        if (ctx->pc != 0x16F88Cu) { return; }
    }
    ctx->pc = 0x16F88Cu;
label_16f88c:
    // 0x16f88c: 0x200202d  daddu       $a0, $s0, $zero
    ctx->pc = 0x16f88cu;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x16f890: 0x24050002  addiu       $a1, $zero, 0x2
    ctx->pc = 0x16f890u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 2));
    // 0x16f894: 0xc056daa  jal         func_15B6A8
    ctx->pc = 0x16F894u;
    SET_GPR_U32(ctx, 31, 0x16F89Cu);
    ctx->pc = 0x16F898u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x16F894u;
            // 0x16f898: 0x40302d  daddu       $a2, $v0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x15B6A8u;
    if (runtime->hasFunction(0x15B6A8u)) {
        auto targetFn = runtime->lookupFunction(0x15B6A8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x16F89Cu; }
        if (ctx->pc != 0x16F89Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0015B6A8_0x15b6a8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x16F89Cu; }
        if (ctx->pc != 0x16F89Cu) { return; }
    }
    ctx->pc = 0x16F89Cu;
label_16f89c:
    // 0x16f89c: 0x200202d  daddu       $a0, $s0, $zero
    ctx->pc = 0x16f89cu;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x16f8a0: 0x24050003  addiu       $a1, $zero, 0x3
    ctx->pc = 0x16f8a0u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 3));
    // 0x16f8a4: 0xc056daa  jal         func_15B6A8
    ctx->pc = 0x16F8A4u;
    SET_GPR_U32(ctx, 31, 0x16F8ACu);
    ctx->pc = 0x16F8A8u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x16F8A4u;
            // 0x16f8a8: 0x302d  daddu       $a2, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x15B6A8u;
    if (runtime->hasFunction(0x15B6A8u)) {
        auto targetFn = runtime->lookupFunction(0x15B6A8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x16F8ACu; }
        if (ctx->pc != 0x16F8ACu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0015B6A8_0x15b6a8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x16F8ACu; }
        if (ctx->pc != 0x16F8ACu) { return; }
    }
    ctx->pc = 0x16F8ACu;
label_16f8ac:
    // 0x16f8ac: 0x200202d  daddu       $a0, $s0, $zero
    ctx->pc = 0x16f8acu;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x16f8b0: 0x24050004  addiu       $a1, $zero, 0x4
    ctx->pc = 0x16f8b0u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 4));
    // 0x16f8b4: 0xc056daa  jal         func_15B6A8
    ctx->pc = 0x16F8B4u;
    SET_GPR_U32(ctx, 31, 0x16F8BCu);
    ctx->pc = 0x16F8B8u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x16F8B4u;
            // 0x16f8b8: 0x302d  daddu       $a2, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x15B6A8u;
    if (runtime->hasFunction(0x15B6A8u)) {
        auto targetFn = runtime->lookupFunction(0x15B6A8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x16F8BCu; }
        if (ctx->pc != 0x16F8BCu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0015B6A8_0x15b6a8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x16F8BCu; }
        if (ctx->pc != 0x16F8BCu) { return; }
    }
    ctx->pc = 0x16F8BCu;
label_16f8bc:
    // 0x16f8bc: 0x200202d  daddu       $a0, $s0, $zero
    ctx->pc = 0x16f8bcu;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x16f8c0: 0x24050005  addiu       $a1, $zero, 0x5
    ctx->pc = 0x16f8c0u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 5));
    // 0x16f8c4: 0xc056daa  jal         func_15B6A8
    ctx->pc = 0x16F8C4u;
    SET_GPR_U32(ctx, 31, 0x16F8CCu);
    ctx->pc = 0x16F8C8u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x16F8C4u;
            // 0x16f8c8: 0x302d  daddu       $a2, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x15B6A8u;
    if (runtime->hasFunction(0x15B6A8u)) {
        auto targetFn = runtime->lookupFunction(0x15B6A8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x16F8CCu; }
        if (ctx->pc != 0x16F8CCu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0015B6A8_0x15b6a8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x16F8CCu; }
        if (ctx->pc != 0x16F8CCu) { return; }
    }
    ctx->pc = 0x16F8CCu;
label_16f8cc:
    // 0x16f8cc: 0x200202d  daddu       $a0, $s0, $zero
    ctx->pc = 0x16f8ccu;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x16f8d0: 0x8e260038  lw          $a2, 0x38($s1)
    ctx->pc = 0x16f8d0u;
    SET_GPR_S32(ctx, 6, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 56)));
    // 0x16f8d4: 0xc056daa  jal         func_15B6A8
    ctx->pc = 0x16F8D4u;
    SET_GPR_U32(ctx, 31, 0x16F8DCu);
    ctx->pc = 0x16F8D8u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x16F8D4u;
            // 0x16f8d8: 0x24050006  addiu       $a1, $zero, 0x6 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 6));
        ctx->in_delay_slot = false;
    ctx->pc = 0x15B6A8u;
    if (runtime->hasFunction(0x15B6A8u)) {
        auto targetFn = runtime->lookupFunction(0x15B6A8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x16F8DCu; }
        if (ctx->pc != 0x16F8DCu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0015B6A8_0x15b6a8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x16F8DCu; }
        if (ctx->pc != 0x16F8DCu) { return; }
    }
    ctx->pc = 0x16F8DCu;
label_16f8dc:
    // 0x16f8dc: 0x200202d  daddu       $a0, $s0, $zero
    ctx->pc = 0x16f8dcu;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x16f8e0: 0x3c067fff  lui         $a2, 0x7FFF
    ctx->pc = 0x16f8e0u;
    SET_GPR_S32(ctx, 6, (int32_t)((uint32_t)32767 << 16));
    // 0x16f8e4: 0x24050007  addiu       $a1, $zero, 0x7
    ctx->pc = 0x16f8e4u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 7));
    // 0x16f8e8: 0xc056daa  jal         func_15B6A8
    ctx->pc = 0x16F8E8u;
    SET_GPR_U32(ctx, 31, 0x16F8F0u);
    ctx->pc = 0x16F8ECu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x16F8E8u;
            // 0x16f8ec: 0x34c6ffff  ori         $a2, $a2, 0xFFFF (Delay Slot)
        SET_GPR_U64(ctx, 6, GPR_U64(ctx, 6) | (uint64_t)(uint16_t)65535);
        ctx->in_delay_slot = false;
    ctx->pc = 0x15B6A8u;
    if (runtime->hasFunction(0x15B6A8u)) {
        auto targetFn = runtime->lookupFunction(0x15B6A8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x16F8F0u; }
        if (ctx->pc != 0x16F8F0u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0015B6A8_0x15b6a8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x16F8F0u; }
        if (ctx->pc != 0x16F8F0u) { return; }
    }
    ctx->pc = 0x16F8F0u;
label_16f8f0:
    // 0x16f8f0: 0x200202d  daddu       $a0, $s0, $zero
    ctx->pc = 0x16f8f0u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x16f8f4: 0x24050008  addiu       $a1, $zero, 0x8
    ctx->pc = 0x16f8f4u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 8));
    // 0x16f8f8: 0xc056daa  jal         func_15B6A8
    ctx->pc = 0x16F8F8u;
    SET_GPR_U32(ctx, 31, 0x16F900u);
    ctx->pc = 0x16F8FCu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x16F8F8u;
            // 0x16f8fc: 0x302d  daddu       $a2, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x15B6A8u;
    if (runtime->hasFunction(0x15B6A8u)) {
        auto targetFn = runtime->lookupFunction(0x15B6A8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x16F900u; }
        if (ctx->pc != 0x16F900u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0015B6A8_0x15b6a8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x16F900u; }
        if (ctx->pc != 0x16F900u) { return; }
    }
    ctx->pc = 0x16F900u;
label_16f900:
    // 0x16f900: 0x200202d  daddu       $a0, $s0, $zero
    ctx->pc = 0x16f900u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x16f904: 0x24050009  addiu       $a1, $zero, 0x9
    ctx->pc = 0x16f904u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 9));
    // 0x16f908: 0xc056daa  jal         func_15B6A8
    ctx->pc = 0x16F908u;
    SET_GPR_U32(ctx, 31, 0x16F910u);
    ctx->pc = 0x16F90Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x16F908u;
            // 0x16f90c: 0x302d  daddu       $a2, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x15B6A8u;
    if (runtime->hasFunction(0x15B6A8u)) {
        auto targetFn = runtime->lookupFunction(0x15B6A8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x16F910u; }
        if (ctx->pc != 0x16F910u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0015B6A8_0x15b6a8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x16F910u; }
        if (ctx->pc != 0x16F910u) { return; }
    }
    ctx->pc = 0x16F910u;
label_16f910:
    // 0x16f910: 0xae500000  sw          $s0, 0x0($s2)
    ctx->pc = 0x16f910u;
    WRITE32(ADD32(GPR_U32(ctx, 18), 0), GPR_U32(ctx, 16));
    // 0x16f914: 0x102d  daddu       $v0, $zero, $zero
    ctx->pc = 0x16f914u;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
label_16f918:
    // 0x16f918: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x16f918u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x16f91c: 0xdfb10008  ld          $s1, 0x8($sp)
    ctx->pc = 0x16f91cu;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x16f920: 0xdfb20010  ld          $s2, 0x10($sp)
    ctx->pc = 0x16f920u;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x16f924: 0xdfbf0018  ld          $ra, 0x18($sp)
    ctx->pc = 0x16f924u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 24)));
    // 0x16f928: 0x3e00008  jr          $ra
    ctx->pc = 0x16F928u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x16F92Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x16F928u;
            // 0x16f92c: 0x27bd0020  addiu       $sp, $sp, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x16F7BCu: goto label_16f7bc;
            case 0x16F7D0u: goto label_16f7d0;
            case 0x16F7E0u: goto label_16f7e0;
            case 0x16F7E8u: goto label_16f7e8;
            case 0x16F828u: goto label_16f828;
            case 0x16F830u: goto label_16f830;
            case 0x16F840u: goto label_16f840;
            case 0x16F868u: goto label_16f868;
            case 0x16F870u: goto label_16f870;
            case 0x16F880u: goto label_16f880;
            case 0x16F88Cu: goto label_16f88c;
            case 0x16F89Cu: goto label_16f89c;
            case 0x16F8ACu: goto label_16f8ac;
            case 0x16F8BCu: goto label_16f8bc;
            case 0x16F8CCu: goto label_16f8cc;
            case 0x16F8DCu: goto label_16f8dc;
            case 0x16F8F0u: goto label_16f8f0;
            case 0x16F900u: goto label_16f900;
            case 0x16F910u: goto label_16f910;
            case 0x16F918u: goto label_16f918;
            default: break;
        }
        return;
    }
    ctx->pc = 0x16F930u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
