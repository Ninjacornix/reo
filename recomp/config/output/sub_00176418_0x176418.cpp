#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00176418
// Address: 0x176418 - 0x176670
void sub_00176418_0x176418(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00176418_0x176418");
#endif

    switch (ctx->pc) {
        case 0x176444u: goto label_176444;
        case 0x176450u: goto label_176450;
        case 0x176480u: goto label_176480;
        case 0x17648cu: goto label_17648c;
        case 0x1764ccu: goto label_1764cc;
        case 0x17651cu: goto label_17651c;
        case 0x176568u: goto label_176568;
        case 0x1765a8u: goto label_1765a8;
        case 0x1765e4u: goto label_1765e4;
        case 0x1765f0u: goto label_1765f0;
        default: break;
    }

    ctx->pc = 0x176418u;

    // 0x176418: 0x27bdffc0  addiu       $sp, $sp, -0x40
    ctx->pc = 0x176418u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967232));
    // 0x17641c: 0xffb10018  sd          $s1, 0x18($sp)
    ctx->pc = 0x17641cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 24), GPR_U64(ctx, 17));
    // 0x176420: 0x80882d  daddu       $s1, $a0, $zero
    ctx->pc = 0x176420u;
    SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x176424: 0x3a0202d  daddu       $a0, $sp, $zero
    ctx->pc = 0x176424u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 29) + (uint64_t)GPR_U64(ctx, 0));
    // 0x176428: 0xffb00010  sd          $s0, 0x10($sp)
    ctx->pc = 0x176428u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 16));
    // 0x17642c: 0xffb20020  sd          $s2, 0x20($sp)
    ctx->pc = 0x17642cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 32), GPR_U64(ctx, 18));
    // 0x176430: 0xa0902d  daddu       $s2, $a1, $zero
    ctx->pc = 0x176430u;
    SET_GPR_U64(ctx, 18, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
    // 0x176434: 0xffb30028  sd          $s3, 0x28($sp)
    ctx->pc = 0x176434u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 40), GPR_U64(ctx, 19));
    // 0x176438: 0xffbf0030  sd          $ra, 0x30($sp)
    ctx->pc = 0x176438u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 48), GPR_U64(ctx, 31));
    // 0x17643c: 0xc05a7b2  jal         func_169EC8
    ctx->pc = 0x17643Cu;
    SET_GPR_U32(ctx, 31, 0x176444u);
    ctx->pc = 0x176440u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x17643Cu;
            // 0x176440: 0xc0982d  daddu       $s3, $a2, $zero (Delay Slot)
        SET_GPR_U64(ctx, 19, (uint64_t)GPR_U64(ctx, 6) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x169EC8u;
    if (runtime->hasFunction(0x169EC8u)) {
        auto targetFn = runtime->lookupFunction(0x169EC8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x176444u; }
        if (ctx->pc != 0x176444u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00169EC8_0x169ec8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x176444u; }
        if (ctx->pc != 0x176444u) { return; }
    }
    ctx->pc = 0x176444u;
label_176444:
    // 0x176444: 0x220202d  daddu       $a0, $s1, $zero
    ctx->pc = 0x176444u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
    // 0x176448: 0xc05d58a  jal         func_175628
    ctx->pc = 0x176448u;
    SET_GPR_U32(ctx, 31, 0x176450u);
    ctx->pc = 0x17644Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x176448u;
            // 0x17644c: 0x2405000f  addiu       $a1, $zero, 0xF (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 15));
        ctx->in_delay_slot = false;
    ctx->pc = 0x175628u;
    if (runtime->hasFunction(0x175628u)) {
        auto targetFn = runtime->lookupFunction(0x175628u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x176450u; }
        if (ctx->pc != 0x176450u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00175628_0x175628(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x176450u; }
        if (ctx->pc != 0x176450u) { return; }
    }
    ctx->pc = 0x176450u;
label_176450:
    // 0x176450: 0x220202d  daddu       $a0, $s1, $zero
    ctx->pc = 0x176450u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
    // 0x176454: 0x21080  sll         $v0, $v0, 2
    ctx->pc = 0x176454u;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 2), 2));
    // 0x176458: 0x26300cc0  addiu       $s0, $s1, 0xCC0
    ctx->pc = 0x176458u;
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 17), 3264));
    // 0x17645c: 0x2028021  addu        $s0, $s0, $v0
    ctx->pc = 0x17645cu;
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 16), GPR_U32(ctx, 2)));
    // 0x176460: 0x240282d  daddu       $a1, $s2, $zero
    ctx->pc = 0x176460u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 18) + (uint64_t)GPR_U64(ctx, 0));
    // 0x176464: 0x8e020000  lw          $v0, 0x0($s0)
    ctx->pc = 0x176464u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 0)));
    // 0x176468: 0x14400003  bnez        $v0, . + 4 + (0x3 << 2)
    ctx->pc = 0x176468u;
    {
        const bool branch_taken_0x176468 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x17646Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x176468u;
            // 0x17646c: 0x260302d  daddu       $a2, $s3, $zero (Delay Slot)
        SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 19) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x176468) {
            ctx->pc = 0x176478u;
            goto label_176478;
        }
    }
    ctx->pc = 0x176470u;
    // 0x176470: 0x3c020017  lui         $v0, 0x17
    ctx->pc = 0x176470u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)23 << 16));
    // 0x176474: 0x244264b0  addiu       $v0, $v0, 0x64B0
    ctx->pc = 0x176474u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 25776));
label_176478:
    // 0x176478: 0x40f809  jalr        $v0
    ctx->pc = 0x176478u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 2);
        SET_GPR_U32(ctx, 31, 0x176480u);
        if (jumpTarget == 0u) {
            ctx->pc = 0x176480u;
        } else {
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x176444u: goto label_176444;
            case 0x176450u: goto label_176450;
            case 0x176478u: goto label_176478;
            case 0x176480u: goto label_176480;
            case 0x17648Cu: goto label_17648c;
            case 0x1764CCu: goto label_1764cc;
            case 0x1764E4u: goto label_1764e4;
            case 0x17651Cu: goto label_17651c;
            case 0x17653Cu: goto label_17653c;
            case 0x176568u: goto label_176568;
            case 0x1765A8u: goto label_1765a8;
            case 0x1765D8u: goto label_1765d8;
            case 0x1765E4u: goto label_1765e4;
            case 0x1765F0u: goto label_1765f0;
            case 0x176628u: goto label_176628;
            case 0x17662Cu: goto label_17662c;
            case 0x176630u: goto label_176630;
            case 0x17664Cu: goto label_17664c;
            case 0x176650u: goto label_176650;
            default: break;
        }
        {
            auto targetFn = runtime->lookupFunction(jumpTarget);
            const uint32_t __entryPc = ctx->pc;
            targetFn(rdram, ctx, runtime);
            if (ctx->pc == __entryPc) { ctx->pc = 0x176480u; }
            if (ctx->pc != 0x176480u) { return; }
        }
        }
    }
    ctx->pc = 0x176480u;
label_176480:
    // 0x176480: 0x3a0202d  daddu       $a0, $sp, $zero
    ctx->pc = 0x176480u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 29) + (uint64_t)GPR_U64(ctx, 0));
    // 0x176484: 0xc05a7b8  jal         func_169EE0
    ctx->pc = 0x176484u;
    SET_GPR_U32(ctx, 31, 0x17648Cu);
    ctx->pc = 0x176488u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x176484u;
            // 0x176488: 0x40802d  daddu       $s0, $v0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x169EE0u;
    if (runtime->hasFunction(0x169EE0u)) {
        auto targetFn = runtime->lookupFunction(0x169EE0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x17648Cu; }
        if (ctx->pc != 0x17648Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00169EE0_0x169ee0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x17648Cu; }
        if (ctx->pc != 0x17648Cu) { return; }
    }
    ctx->pc = 0x17648Cu;
label_17648c:
    // 0x17648c: 0x200102d  daddu       $v0, $s0, $zero
    ctx->pc = 0x17648cu;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x176490: 0xdfb10018  ld          $s1, 0x18($sp)
    ctx->pc = 0x176490u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 24)));
    // 0x176494: 0xdfb00010  ld          $s0, 0x10($sp)
    ctx->pc = 0x176494u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x176498: 0xdfb20020  ld          $s2, 0x20($sp)
    ctx->pc = 0x176498u;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x17649c: 0xdfb30028  ld          $s3, 0x28($sp)
    ctx->pc = 0x17649cu;
    SET_GPR_U64(ctx, 19, READ64(ADD32(GPR_U32(ctx, 29), 40)));
    // 0x1764a0: 0xdfbf0030  ld          $ra, 0x30($sp)
    ctx->pc = 0x1764a0u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 48)));
    // 0x1764a4: 0x3e00008  jr          $ra
    ctx->pc = 0x1764A4u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1764A8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1764A4u;
            // 0x1764a8: 0x27bd0040  addiu       $sp, $sp, 0x40 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 64));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x176444u: goto label_176444;
            case 0x176450u: goto label_176450;
            case 0x176478u: goto label_176478;
            case 0x176480u: goto label_176480;
            case 0x17648Cu: goto label_17648c;
            case 0x1764CCu: goto label_1764cc;
            case 0x1764E4u: goto label_1764e4;
            case 0x17651Cu: goto label_17651c;
            case 0x17653Cu: goto label_17653c;
            case 0x176568u: goto label_176568;
            case 0x1765A8u: goto label_1765a8;
            case 0x1765D8u: goto label_1765d8;
            case 0x1765E4u: goto label_1765e4;
            case 0x1765F0u: goto label_1765f0;
            case 0x176628u: goto label_176628;
            case 0x17662Cu: goto label_17662c;
            case 0x176630u: goto label_176630;
            case 0x17664Cu: goto label_17664c;
            case 0x176650u: goto label_176650;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1764ACu;
    // 0x1764ac: 0x0  nop
    ctx->pc = 0x1764acu;
    // NOP
    // 0x1764b0: 0x27bdffe0  addiu       $sp, $sp, -0x20
    ctx->pc = 0x1764b0u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967264));
    // 0x1764b4: 0xffb00000  sd          $s0, 0x0($sp)
    ctx->pc = 0x1764b4u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x1764b8: 0xa0802d  daddu       $s0, $a1, $zero
    ctx->pc = 0x1764b8u;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1764bc: 0xffb10008  sd          $s1, 0x8($sp)
    ctx->pc = 0x1764bcu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 8), GPR_U64(ctx, 17));
    // 0x1764c0: 0xffbf0010  sd          $ra, 0x10($sp)
    ctx->pc = 0x1764c0u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 31));
    // 0x1764c4: 0xc05d99c  jal         func_176670
    ctx->pc = 0x1764C4u;
    SET_GPR_U32(ctx, 31, 0x1764CCu);
    ctx->pc = 0x1764C8u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1764C4u;
            // 0x1764c8: 0xc0882d  daddu       $s1, $a2, $zero (Delay Slot)
        SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 6) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x176670u;
    if (runtime->hasFunction(0x176670u)) {
        auto targetFn = runtime->lookupFunction(0x176670u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1764CCu; }
        if (ctx->pc != 0x1764CCu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00176670_0x176670(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1764CCu; }
        if (ctx->pc != 0x1764CCu) { return; }
    }
    ctx->pc = 0x1764CCu;
label_1764cc:
    // 0x1764cc: 0x10400005  beqz        $v0, . + 4 + (0x5 << 2)
    ctx->pc = 0x1764CCu;
    {
        const bool branch_taken_0x1764cc = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x1764D0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1764CCu;
            // 0x1764d0: 0x24030001  addiu       $v1, $zero, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1764cc) {
            ctx->pc = 0x1764E4u;
            goto label_1764e4;
        }
    }
    ctx->pc = 0x1764D4u;
    // 0x1764d4: 0x2402fffe  addiu       $v0, $zero, -0x2
    ctx->pc = 0x1764d4u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967294));
    // 0x1764d8: 0xae020000  sw          $v0, 0x0($s0)
    ctx->pc = 0x1764d8u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 0), GPR_U32(ctx, 2));
    // 0x1764dc: 0x102d  daddu       $v0, $zero, $zero
    ctx->pc = 0x1764dcu;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1764e0: 0xae230000  sw          $v1, 0x0($s1)
    ctx->pc = 0x1764e0u;
    WRITE32(ADD32(GPR_U32(ctx, 17), 0), GPR_U32(ctx, 3));
label_1764e4:
    // 0x1764e4: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x1764e4u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1764e8: 0xdfb10008  ld          $s1, 0x8($sp)
    ctx->pc = 0x1764e8u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x1764ec: 0xdfbf0010  ld          $ra, 0x10($sp)
    ctx->pc = 0x1764ecu;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x1764f0: 0x3e00008  jr          $ra
    ctx->pc = 0x1764F0u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1764F4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1764F0u;
            // 0x1764f4: 0x27bd0020  addiu       $sp, $sp, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x176444u: goto label_176444;
            case 0x176450u: goto label_176450;
            case 0x176478u: goto label_176478;
            case 0x176480u: goto label_176480;
            case 0x17648Cu: goto label_17648c;
            case 0x1764CCu: goto label_1764cc;
            case 0x1764E4u: goto label_1764e4;
            case 0x17651Cu: goto label_17651c;
            case 0x17653Cu: goto label_17653c;
            case 0x176568u: goto label_176568;
            case 0x1765A8u: goto label_1765a8;
            case 0x1765D8u: goto label_1765d8;
            case 0x1765E4u: goto label_1765e4;
            case 0x1765F0u: goto label_1765f0;
            case 0x176628u: goto label_176628;
            case 0x17662Cu: goto label_17662c;
            case 0x176630u: goto label_176630;
            case 0x17664Cu: goto label_17664c;
            case 0x176650u: goto label_176650;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1764F8u;
    // 0x1764f8: 0x27bdffe0  addiu       $sp, $sp, -0x20
    ctx->pc = 0x1764f8u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967264));
    // 0x1764fc: 0xffb00000  sd          $s0, 0x0($sp)
    ctx->pc = 0x1764fcu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x176500: 0x80802d  daddu       $s0, $a0, $zero
    ctx->pc = 0x176500u;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x176504: 0xffb10008  sd          $s1, 0x8($sp)
    ctx->pc = 0x176504u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 8), GPR_U64(ctx, 17));
    // 0x176508: 0xa0882d  daddu       $s1, $a1, $zero
    ctx->pc = 0x176508u;
    SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
    // 0x17650c: 0xffb20010  sd          $s2, 0x10($sp)
    ctx->pc = 0x17650cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 18));
    // 0x176510: 0xffbf0018  sd          $ra, 0x18($sp)
    ctx->pc = 0x176510u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 24), GPR_U64(ctx, 31));
    // 0x176514: 0xc05d99c  jal         func_176670
    ctx->pc = 0x176514u;
    SET_GPR_U32(ctx, 31, 0x17651Cu);
    ctx->pc = 0x176518u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x176514u;
            // 0x176518: 0xc0902d  daddu       $s2, $a2, $zero (Delay Slot)
        SET_GPR_U64(ctx, 18, (uint64_t)GPR_U64(ctx, 6) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x176670u;
    if (runtime->hasFunction(0x176670u)) {
        auto targetFn = runtime->lookupFunction(0x176670u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x17651Cu; }
        if (ctx->pc != 0x17651Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00176670_0x176670(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x17651Cu; }
        if (ctx->pc != 0x17651Cu) { return; }
    }
    ctx->pc = 0x17651Cu;
label_17651c:
    // 0x17651c: 0x10400007  beqz        $v0, . + 4 + (0x7 << 2)
    ctx->pc = 0x17651Cu;
    {
        const bool branch_taken_0x17651c = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x176520u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x17651Cu;
            // 0x176520: 0x26100cc0  addiu       $s0, $s0, 0xCC0 (Delay Slot)
        SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 16), 3264));
        ctx->in_delay_slot = false;
        if (branch_taken_0x17651c) {
            ctx->pc = 0x17653Cu;
            goto label_17653c;
        }
    }
    ctx->pc = 0x176524u;
    // 0x176524: 0x8e030264  lw          $v1, 0x264($s0)
    ctx->pc = 0x176524u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 612)));
    // 0x176528: 0x3c040023  lui         $a0, 0x23
    ctx->pc = 0x176528u;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)35 << 16));
    // 0x17652c: 0x102d  daddu       $v0, $zero, $zero
    ctx->pc = 0x17652cu;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x176530: 0xae230000  sw          $v1, 0x0($s1)
    ctx->pc = 0x176530u;
    WRITE32(ADD32(GPR_U32(ctx, 17), 0), GPR_U32(ctx, 3));
    // 0x176534: 0x8c83f140  lw          $v1, -0xEC0($a0)
    ctx->pc = 0x176534u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 4294963520)));
    // 0x176538: 0xae430000  sw          $v1, 0x0($s2)
    ctx->pc = 0x176538u;
    WRITE32(ADD32(GPR_U32(ctx, 18), 0), GPR_U32(ctx, 3));
label_17653c:
    // 0x17653c: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x17653cu;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x176540: 0xdfb10008  ld          $s1, 0x8($sp)
    ctx->pc = 0x176540u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x176544: 0xdfb20010  ld          $s2, 0x10($sp)
    ctx->pc = 0x176544u;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x176548: 0xdfbf0018  ld          $ra, 0x18($sp)
    ctx->pc = 0x176548u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 24)));
    // 0x17654c: 0x3e00008  jr          $ra
    ctx->pc = 0x17654Cu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x176550u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x17654Cu;
            // 0x176550: 0x27bd0020  addiu       $sp, $sp, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x176444u: goto label_176444;
            case 0x176450u: goto label_176450;
            case 0x176478u: goto label_176478;
            case 0x176480u: goto label_176480;
            case 0x17648Cu: goto label_17648c;
            case 0x1764CCu: goto label_1764cc;
            case 0x1764E4u: goto label_1764e4;
            case 0x17651Cu: goto label_17651c;
            case 0x17653Cu: goto label_17653c;
            case 0x176568u: goto label_176568;
            case 0x1765A8u: goto label_1765a8;
            case 0x1765D8u: goto label_1765d8;
            case 0x1765E4u: goto label_1765e4;
            case 0x1765F0u: goto label_1765f0;
            case 0x176628u: goto label_176628;
            case 0x17662Cu: goto label_17662c;
            case 0x176630u: goto label_176630;
            case 0x17664Cu: goto label_17664c;
            case 0x176650u: goto label_176650;
            default: break;
        }
        return;
    }
    ctx->pc = 0x176554u;
    // 0x176554: 0x0  nop
    ctx->pc = 0x176554u;
    // NOP
    // 0x176558: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x176558u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x17655c: 0xffbf0000  sd          $ra, 0x0($sp)
    ctx->pc = 0x17655cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 31));
    // 0x176560: 0xc05d99c  jal         func_176670
    ctx->pc = 0x176560u;
    SET_GPR_U32(ctx, 31, 0x176568u);
    ctx->pc = 0x176670u;
    if (runtime->hasFunction(0x176670u)) {
        auto targetFn = runtime->lookupFunction(0x176670u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x176568u; }
        if (ctx->pc != 0x176568u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00176670_0x176670(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x176568u; }
        if (ctx->pc != 0x176568u) { return; }
    }
    ctx->pc = 0x176568u;
label_176568:
    // 0x176568: 0xdfbf0000  ld          $ra, 0x0($sp)
    ctx->pc = 0x176568u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x17656c: 0x102d  daddu       $v0, $zero, $zero
    ctx->pc = 0x17656cu;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x176570: 0x3e00008  jr          $ra
    ctx->pc = 0x176570u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x176574u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x176570u;
            // 0x176574: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x176444u: goto label_176444;
            case 0x176450u: goto label_176450;
            case 0x176478u: goto label_176478;
            case 0x176480u: goto label_176480;
            case 0x17648Cu: goto label_17648c;
            case 0x1764CCu: goto label_1764cc;
            case 0x1764E4u: goto label_1764e4;
            case 0x17651Cu: goto label_17651c;
            case 0x17653Cu: goto label_17653c;
            case 0x176568u: goto label_176568;
            case 0x1765A8u: goto label_1765a8;
            case 0x1765D8u: goto label_1765d8;
            case 0x1765E4u: goto label_1765e4;
            case 0x1765F0u: goto label_1765f0;
            case 0x176628u: goto label_176628;
            case 0x17662Cu: goto label_17662c;
            case 0x176630u: goto label_176630;
            case 0x17664Cu: goto label_17664c;
            case 0x176650u: goto label_176650;
            default: break;
        }
        return;
    }
    ctx->pc = 0x176578u;
    // 0x176578: 0x27bdffc0  addiu       $sp, $sp, -0x40
    ctx->pc = 0x176578u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967232));
    // 0x17657c: 0xffb10018  sd          $s1, 0x18($sp)
    ctx->pc = 0x17657cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 24), GPR_U64(ctx, 17));
    // 0x176580: 0x80882d  daddu       $s1, $a0, $zero
    ctx->pc = 0x176580u;
    SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x176584: 0xffb00010  sd          $s0, 0x10($sp)
    ctx->pc = 0x176584u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 16));
    // 0x176588: 0x26300cc0  addiu       $s0, $s1, 0xCC0
    ctx->pc = 0x176588u;
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 17), 3264));
    // 0x17658c: 0xffb30028  sd          $s3, 0x28($sp)
    ctx->pc = 0x17658cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 40), GPR_U64(ctx, 19));
    // 0x176590: 0xa0982d  daddu       $s3, $a1, $zero
    ctx->pc = 0x176590u;
    SET_GPR_U64(ctx, 19, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
    // 0x176594: 0xffb40030  sd          $s4, 0x30($sp)
    ctx->pc = 0x176594u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 48), GPR_U64(ctx, 20));
    // 0x176598: 0xffb20020  sd          $s2, 0x20($sp)
    ctx->pc = 0x176598u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 32), GPR_U64(ctx, 18));
    // 0x17659c: 0xffbf0038  sd          $ra, 0x38($sp)
    ctx->pc = 0x17659cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 56), GPR_U64(ctx, 31));
    // 0x1765a0: 0xc05d99c  jal         func_176670
    ctx->pc = 0x1765A0u;
    SET_GPR_U32(ctx, 31, 0x1765A8u);
    ctx->pc = 0x1765A4u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1765A0u;
            // 0x1765a4: 0xc0a02d  daddu       $s4, $a2, $zero (Delay Slot)
        SET_GPR_U64(ctx, 20, (uint64_t)GPR_U64(ctx, 6) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x176670u;
    if (runtime->hasFunction(0x176670u)) {
        auto targetFn = runtime->lookupFunction(0x176670u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1765A8u; }
        if (ctx->pc != 0x1765A8u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00176670_0x176670(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1765A8u; }
        if (ctx->pc != 0x1765A8u) { return; }
    }
    ctx->pc = 0x1765A8u;
label_1765a8:
    // 0x1765a8: 0x50400029  beql        $v0, $zero, . + 4 + (0x29 << 2)
    ctx->pc = 0x1765A8u;
    {
        const bool branch_taken_0x1765a8 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        if (branch_taken_0x1765a8) {
            ctx->pc = 0x1765ACu;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x1765A8u;
            // 0x1765ac: 0xdfb00010  ld          $s0, 0x10($sp) (Delay Slot)
        SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 16)));
        ctx->in_delay_slot = false;
            ctx->pc = 0x176650u;
            goto label_176650;
        }
    }
    ctx->pc = 0x1765B0u;
    // 0x1765b0: 0x8e020290  lw          $v0, 0x290($s0)
    ctx->pc = 0x1765b0u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 656)));
    // 0x1765b4: 0x14400008  bnez        $v0, . + 4 + (0x8 << 2)
    ctx->pc = 0x1765B4u;
    {
        const bool branch_taken_0x1765b4 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x1765B8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1765B4u;
            // 0x1765b8: 0x220202d  daddu       $a0, $s1, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1765b4) {
            ctx->pc = 0x1765D8u;
            goto label_1765d8;
        }
    }
    ctx->pc = 0x1765BCu;
    // 0x1765bc: 0x2403fffe  addiu       $v1, $zero, -0x2
    ctx->pc = 0x1765bcu;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967294));
    // 0x1765c0: 0x24040001  addiu       $a0, $zero, 0x1
    ctx->pc = 0x1765c0u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x1765c4: 0xae630000  sw          $v1, 0x0($s3)
    ctx->pc = 0x1765c4u;
    WRITE32(ADD32(GPR_U32(ctx, 19), 0), GPR_U32(ctx, 3));
    // 0x1765c8: 0x102d  daddu       $v0, $zero, $zero
    ctx->pc = 0x1765c8u;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1765cc: 0x1000001f  b           . + 4 + (0x1F << 2)
    ctx->pc = 0x1765CCu;
    {
        const bool branch_taken_0x1765cc = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1765D0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1765CCu;
            // 0x1765d0: 0xae840000  sw          $a0, 0x0($s4) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 20), 0), GPR_U32(ctx, 4));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1765cc) {
            ctx->pc = 0x17664Cu;
            goto label_17664c;
        }
    }
    ctx->pc = 0x1765D4u;
    // 0x1765d4: 0x0  nop
    ctx->pc = 0x1765d4u;
    // NOP
label_1765d8:
    // 0x1765d8: 0x3a0282d  daddu       $a1, $sp, $zero
    ctx->pc = 0x1765d8u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 29) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1765dc: 0x40f809  jalr        $v0
    ctx->pc = 0x1765DCu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 2);
        SET_GPR_U32(ctx, 31, 0x1765E4u);
        ctx->pc = 0x1765E0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1765DCu;
            // 0x1765e0: 0x27a60004  addiu       $a2, $sp, 0x4 (Delay Slot)
        SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 29), 4));
        ctx->in_delay_slot = false;
        if (jumpTarget == 0u) {
            ctx->pc = 0x1765E4u;
        } else {
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x176444u: goto label_176444;
            case 0x176450u: goto label_176450;
            case 0x176478u: goto label_176478;
            case 0x176480u: goto label_176480;
            case 0x17648Cu: goto label_17648c;
            case 0x1764CCu: goto label_1764cc;
            case 0x1764E4u: goto label_1764e4;
            case 0x17651Cu: goto label_17651c;
            case 0x17653Cu: goto label_17653c;
            case 0x176568u: goto label_176568;
            case 0x1765A8u: goto label_1765a8;
            case 0x1765D8u: goto label_1765d8;
            case 0x1765E4u: goto label_1765e4;
            case 0x1765F0u: goto label_1765f0;
            case 0x176628u: goto label_176628;
            case 0x17662Cu: goto label_17662c;
            case 0x176630u: goto label_176630;
            case 0x17664Cu: goto label_17664c;
            case 0x176650u: goto label_176650;
            default: break;
        }
        {
            auto targetFn = runtime->lookupFunction(jumpTarget);
            const uint32_t __entryPc = ctx->pc;
            targetFn(rdram, ctx, runtime);
            if (ctx->pc == __entryPc) { ctx->pc = 0x1765E4u; }
            if (ctx->pc != 0x1765E4u) { return; }
        }
        }
    }
    ctx->pc = 0x1765E4u;
label_1765e4:
    // 0x1765e4: 0x220202d  daddu       $a0, $s1, $zero
    ctx->pc = 0x1765e4u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1765e8: 0xc05d7b0  jal         func_175EC0
    ctx->pc = 0x1765E8u;
    SET_GPR_U32(ctx, 31, 0x1765F0u);
    ctx->pc = 0x1765ECu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1765E8u;
            // 0x1765ec: 0x40902d  daddu       $s2, $v0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 18, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x175EC0u;
    if (runtime->hasFunction(0x175EC0u)) {
        auto targetFn = runtime->lookupFunction(0x175EC0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1765F0u; }
        if (ctx->pc != 0x1765F0u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00175EC0_0x175ec0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1765F0u; }
        if (ctx->pc != 0x1765F0u) { return; }
    }
    ctx->pc = 0x1765F0u;
label_1765f0:
    // 0x1765f0: 0x1040000d  beqz        $v0, . + 4 + (0xD << 2)
    ctx->pc = 0x1765F0u;
    {
        const bool branch_taken_0x1765f0 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x1765F4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1765F0u;
            // 0x1765f4: 0x2403fffb  addiu       $v1, $zero, -0x5 (Delay Slot)
        SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967291));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1765f0) {
            ctx->pc = 0x176628u;
            goto label_176628;
        }
    }
    ctx->pc = 0x1765F8u;
    // 0x1765f8: 0x8e020294  lw          $v0, 0x294($s0)
    ctx->pc = 0x1765f8u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 660)));
    // 0x1765fc: 0x5043000b  beql        $v0, $v1, . + 4 + (0xB << 2)
    ctx->pc = 0x1765FCu;
    {
        const bool branch_taken_0x1765fc = (GPR_U64(ctx, 2) == GPR_U64(ctx, 3));
        if (branch_taken_0x1765fc) {
            ctx->pc = 0x176600u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x1765FCu;
            // 0x176600: 0x8fa40000  lw          $a0, 0x0($sp) (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 0)));
        ctx->in_delay_slot = false;
            ctx->pc = 0x17662Cu;
            goto label_17662c;
        }
    }
    ctx->pc = 0x176604u;
    // 0x176604: 0x8e030294  lw          $v1, 0x294($s0)
    ctx->pc = 0x176604u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 660)));
    // 0x176608: 0x8fa40000  lw          $a0, 0x0($sp)
    ctx->pc = 0x176608u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x17660c: 0x8e020298  lw          $v0, 0x298($s0)
    ctx->pc = 0x17660cu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 664)));
    // 0x176610: 0x831823  subu        $v1, $a0, $v1
    ctx->pc = 0x176610u;
    SET_GPR_S32(ctx, 3, (int32_t)SUB32(GPR_U32(ctx, 4), GPR_U32(ctx, 3)));
    // 0x176614: 0x431021  addu        $v0, $v0, $v1
    ctx->pc = 0x176614u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 3)));
    // 0x176618: 0xae020298  sw          $v0, 0x298($s0)
    ctx->pc = 0x176618u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 664), GPR_U32(ctx, 2));
    // 0x17661c: 0x10000004  b           . + 4 + (0x4 << 2)
    ctx->pc = 0x17661Cu;
    {
        const bool branch_taken_0x17661c = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x176620u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x17661Cu;
            // 0x176620: 0x8fa30004  lw          $v1, 0x4($sp) (Delay Slot)
        SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 4)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x17661c) {
            ctx->pc = 0x176630u;
            goto label_176630;
        }
    }
    ctx->pc = 0x176624u;
    // 0x176624: 0x0  nop
    ctx->pc = 0x176624u;
    // NOP
label_176628:
    // 0x176628: 0x8fa40000  lw          $a0, 0x0($sp)
    ctx->pc = 0x176628u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 0)));
label_17662c:
    // 0x17662c: 0x8fa30004  lw          $v1, 0x4($sp)
    ctx->pc = 0x17662cu;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 4)));
label_176630:
    // 0x176630: 0x240102d  daddu       $v0, $s2, $zero
    ctx->pc = 0x176630u;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 18) + (uint64_t)GPR_U64(ctx, 0));
    // 0x176634: 0xae040294  sw          $a0, 0x294($s0)
    ctx->pc = 0x176634u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 660), GPR_U32(ctx, 4));
    // 0x176638: 0xae03029c  sw          $v1, 0x29C($s0)
    ctx->pc = 0x176638u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 668), GPR_U32(ctx, 3));
    // 0x17663c: 0x8e040298  lw          $a0, 0x298($s0)
    ctx->pc = 0x17663cu;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 664)));
    // 0x176640: 0xae640000  sw          $a0, 0x0($s3)
    ctx->pc = 0x176640u;
    WRITE32(ADD32(GPR_U32(ctx, 19), 0), GPR_U32(ctx, 4));
    // 0x176644: 0x8e03029c  lw          $v1, 0x29C($s0)
    ctx->pc = 0x176644u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 668)));
    // 0x176648: 0xae830000  sw          $v1, 0x0($s4)
    ctx->pc = 0x176648u;
    WRITE32(ADD32(GPR_U32(ctx, 20), 0), GPR_U32(ctx, 3));
label_17664c:
    // 0x17664c: 0xdfb00010  ld          $s0, 0x10($sp)
    ctx->pc = 0x17664cu;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 16)));
label_176650:
    // 0x176650: 0xdfb10018  ld          $s1, 0x18($sp)
    ctx->pc = 0x176650u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 24)));
    // 0x176654: 0xdfb20020  ld          $s2, 0x20($sp)
    ctx->pc = 0x176654u;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x176658: 0xdfb30028  ld          $s3, 0x28($sp)
    ctx->pc = 0x176658u;
    SET_GPR_U64(ctx, 19, READ64(ADD32(GPR_U32(ctx, 29), 40)));
    // 0x17665c: 0xdfb40030  ld          $s4, 0x30($sp)
    ctx->pc = 0x17665cu;
    SET_GPR_U64(ctx, 20, READ64(ADD32(GPR_U32(ctx, 29), 48)));
    // 0x176660: 0xdfbf0038  ld          $ra, 0x38($sp)
    ctx->pc = 0x176660u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 56)));
    // 0x176664: 0x3e00008  jr          $ra
    ctx->pc = 0x176664u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x176668u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x176664u;
            // 0x176668: 0x27bd0040  addiu       $sp, $sp, 0x40 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 64));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x176444u: goto label_176444;
            case 0x176450u: goto label_176450;
            case 0x176478u: goto label_176478;
            case 0x176480u: goto label_176480;
            case 0x17648Cu: goto label_17648c;
            case 0x1764CCu: goto label_1764cc;
            case 0x1764E4u: goto label_1764e4;
            case 0x17651Cu: goto label_17651c;
            case 0x17653Cu: goto label_17653c;
            case 0x176568u: goto label_176568;
            case 0x1765A8u: goto label_1765a8;
            case 0x1765D8u: goto label_1765d8;
            case 0x1765E4u: goto label_1765e4;
            case 0x1765F0u: goto label_1765f0;
            case 0x176628u: goto label_176628;
            case 0x17662Cu: goto label_17662c;
            case 0x176630u: goto label_176630;
            case 0x17664Cu: goto label_17664c;
            case 0x176650u: goto label_176650;
            default: break;
        }
        return;
    }
    ctx->pc = 0x17666Cu;
    // 0x17666c: 0x0  nop
    ctx->pc = 0x17666cu;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
