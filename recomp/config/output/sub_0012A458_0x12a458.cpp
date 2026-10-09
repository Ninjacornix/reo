#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_0012A458
// Address: 0x12a458 - 0x12a658
void sub_0012A458_0x12a458(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_0012A458_0x12a458");
#endif

    switch (ctx->pc) {
        case 0x12a494u: goto label_12a494;
        case 0x12a4a8u: goto label_12a4a8;
        case 0x12a4b8u: goto label_12a4b8;
        case 0x12a4c8u: goto label_12a4c8;
        case 0x12a4e0u: goto label_12a4e0;
        case 0x12a4f8u: goto label_12a4f8;
        case 0x12a500u: goto label_12a500;
        case 0x12a508u: goto label_12a508;
        case 0x12a528u: goto label_12a528;
        case 0x12a538u: goto label_12a538;
        case 0x12a570u: goto label_12a570;
        case 0x12a588u: goto label_12a588;
        case 0x12a5b0u: goto label_12a5b0;
        case 0x12a5c8u: goto label_12a5c8;
        case 0x12a5e0u: goto label_12a5e0;
        case 0x12a5e8u: goto label_12a5e8;
        case 0x12a5f0u: goto label_12a5f0;
        case 0x12a600u: goto label_12a600;
        case 0x12a614u: goto label_12a614;
        case 0x12a628u: goto label_12a628;
        case 0x12a630u: goto label_12a630;
        default: break;
    }

    ctx->pc = 0x12a458u;

    // 0x12a458: 0x27bdff90  addiu       $sp, $sp, -0x70
    ctx->pc = 0x12a458u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967184));
    // 0x12a45c: 0xffb00030  sd          $s0, 0x30($sp)
    ctx->pc = 0x12a45cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 48), GPR_U64(ctx, 16));
    // 0x12a460: 0x3c100021  lui         $s0, 0x21
    ctx->pc = 0x12a460u;
    SET_GPR_S32(ctx, 16, (int32_t)((uint32_t)33 << 16));
    // 0x12a464: 0xffb10038  sd          $s1, 0x38($sp)
    ctx->pc = 0x12a464u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 56), GPR_U64(ctx, 17));
    // 0x12a468: 0x80882d  daddu       $s1, $a0, $zero
    ctx->pc = 0x12a468u;
    SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x12a46c: 0xffb20040  sd          $s2, 0x40($sp)
    ctx->pc = 0x12a46cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 64), GPR_U64(ctx, 18));
    // 0x12a470: 0xa0902d  daddu       $s2, $a1, $zero
    ctx->pc = 0x12a470u;
    SET_GPR_U64(ctx, 18, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
    // 0x12a474: 0xffb30048  sd          $s3, 0x48($sp)
    ctx->pc = 0x12a474u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 72), GPR_U64(ctx, 19));
    // 0x12a478: 0xc0982d  daddu       $s3, $a2, $zero
    ctx->pc = 0x12a478u;
    SET_GPR_U64(ctx, 19, (uint64_t)GPR_U64(ctx, 6) + (uint64_t)GPR_U64(ctx, 0));
    // 0x12a47c: 0xffb40050  sd          $s4, 0x50($sp)
    ctx->pc = 0x12a47cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 80), GPR_U64(ctx, 20));
    // 0x12a480: 0xe0a02d  daddu       $s4, $a3, $zero
    ctx->pc = 0x12a480u;
    SET_GPR_U64(ctx, 20, (uint64_t)GPR_U64(ctx, 7) + (uint64_t)GPR_U64(ctx, 0));
    // 0x12a484: 0xffb50058  sd          $s5, 0x58($sp)
    ctx->pc = 0x12a484u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 88), GPR_U64(ctx, 21));
    // 0x12a488: 0xffbf0060  sd          $ra, 0x60($sp)
    ctx->pc = 0x12a488u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 96), GPR_U64(ctx, 31));
    // 0x12a48c: 0xc04bdc8  jal         func_12F720
    ctx->pc = 0x12A48Cu;
    SET_GPR_U32(ctx, 31, 0x12A494u);
    ctx->pc = 0x12A490u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x12A48Cu;
            // 0x12a490: 0x26100408  addiu       $s0, $s0, 0x408 (Delay Slot)
        SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 16), 1032));
        ctx->in_delay_slot = false;
    ctx->pc = 0x12F720u;
    if (runtime->hasFunction(0x12F720u)) {
        auto targetFn = runtime->lookupFunction(0x12F720u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x12A494u; }
        if (ctx->pc != 0x12A494u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0012F720_0x12f720(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x12A494u; }
        if (ctx->pc != 0x12A494u) { return; }
    }
    ctx->pc = 0x12A494u;
label_12a494:
    // 0x12a494: 0x3c040021  lui         $a0, 0x21
    ctx->pc = 0x12a494u;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)33 << 16));
    // 0x12a498: 0x302d  daddu       $a2, $zero, $zero
    ctx->pc = 0x12a498u;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x12a49c: 0x24840008  addiu       $a0, $a0, 0x8
    ctx->pc = 0x12a49cu;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 8));
    // 0x12a4a0: 0xc04fe2a  jal         func_13F8A8
    ctx->pc = 0x12A4A0u;
    SET_GPR_U32(ctx, 31, 0x12A4A8u);
    ctx->pc = 0x12A4A4u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x12A4A0u;
            // 0x12a4a4: 0x24050400  addiu       $a1, $zero, 0x400 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 1024));
        ctx->in_delay_slot = false;
    ctx->pc = 0x13F8A8u;
    if (runtime->hasFunction(0x13F8A8u)) {
        auto targetFn = runtime->lookupFunction(0x13F8A8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x12A4A8u; }
        if (ctx->pc != 0x12A4A8u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0013F8A8_0x13f8a8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x12A4A8u; }
        if (ctx->pc != 0x12A4A8u) { return; }
    }
    ctx->pc = 0x12A4A8u;
label_12a4a8:
    // 0x12a4a8: 0x24050020  addiu       $a1, $zero, 0x20
    ctx->pc = 0x12a4a8u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 32));
    // 0x12a4ac: 0x200202d  daddu       $a0, $s0, $zero
    ctx->pc = 0x12a4acu;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x12a4b0: 0xc04fcd8  jal         func_13F360
    ctx->pc = 0x12A4B0u;
    SET_GPR_U32(ctx, 31, 0x12A4B8u);
    ctx->pc = 0x12A4B4u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x12A4B0u;
            // 0x12a4b4: 0x40a82d  daddu       $s5, $v0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 21, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x13F360u;
    if (runtime->hasFunction(0x13F360u)) {
        auto targetFn = runtime->lookupFunction(0x13F360u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x12A4B8u; }
        if (ctx->pc != 0x12A4B8u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0013F360_0x13f360(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x12A4B8u; }
        if (ctx->pc != 0x12A4B8u) { return; }
    }
    ctx->pc = 0x12A4B8u;
label_12a4b8:
    // 0x12a4b8: 0x26040020  addiu       $a0, $s0, 0x20
    ctx->pc = 0x12a4b8u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 16), 32));
    // 0x12a4bc: 0x24050020  addiu       $a1, $zero, 0x20
    ctx->pc = 0x12a4bcu;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 32));
    // 0x12a4c0: 0xc04fcd8  jal         func_13F360
    ctx->pc = 0x12A4C0u;
    SET_GPR_U32(ctx, 31, 0x12A4C8u);
    ctx->pc = 0x12A4C4u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x12A4C0u;
            // 0x12a4c4: 0xafa20000  sw          $v0, 0x0($sp) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 29), 0), GPR_U32(ctx, 2));
        ctx->in_delay_slot = false;
    ctx->pc = 0x13F360u;
    if (runtime->hasFunction(0x13F360u)) {
        auto targetFn = runtime->lookupFunction(0x13F360u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x12A4C8u; }
        if (ctx->pc != 0x12A4C8u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0013F360_0x13f360(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x12A4C8u; }
        if (ctx->pc != 0x12A4C8u) { return; }
    }
    ctx->pc = 0x12A4C8u;
label_12a4c8:
    // 0x12a4c8: 0x8e300014  lw          $s0, 0x14($s1)
    ctx->pc = 0x12a4c8u;
    SET_GPR_S32(ctx, 16, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 20)));
    // 0x12a4cc: 0x3a0282d  daddu       $a1, $sp, $zero
    ctx->pc = 0x12a4ccu;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 29) + (uint64_t)GPR_U64(ctx, 0));
    // 0x12a4d0: 0x24040002  addiu       $a0, $zero, 0x2
    ctx->pc = 0x12a4d0u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 2));
    // 0x12a4d4: 0x2a0302d  daddu       $a2, $s5, $zero
    ctx->pc = 0x12a4d4u;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 21) + (uint64_t)GPR_U64(ctx, 0));
    // 0x12a4d8: 0xc04bde0  jal         func_12F780
    ctx->pc = 0x12A4D8u;
    SET_GPR_U32(ctx, 31, 0x12A4E0u);
    ctx->pc = 0x12A4DCu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x12A4D8u;
            // 0x12a4dc: 0xafa20004  sw          $v0, 0x4($sp) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 29), 4), GPR_U32(ctx, 2));
        ctx->in_delay_slot = false;
    ctx->pc = 0x12F780u;
    if (runtime->hasFunction(0x12F780u)) {
        auto targetFn = runtime->lookupFunction(0x12F780u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x12A4E0u; }
        if (ctx->pc != 0x12A4E0u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0012F780_0x12f780(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x12A4E0u; }
        if (ctx->pc != 0x12A4E0u) { return; }
    }
    ctx->pc = 0x12A4E0u;
label_12a4e0:
    // 0x12a4e0: 0x240282d  daddu       $a1, $s2, $zero
    ctx->pc = 0x12a4e0u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 18) + (uint64_t)GPR_U64(ctx, 0));
    // 0x12a4e4: 0x40882d  daddu       $s1, $v0, $zero
    ctx->pc = 0x12a4e4u;
    SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x12a4e8: 0x260302d  daddu       $a2, $s3, $zero
    ctx->pc = 0x12a4e8u;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 19) + (uint64_t)GPR_U64(ctx, 0));
    // 0x12a4ec: 0x280382d  daddu       $a3, $s4, $zero
    ctx->pc = 0x12a4ecu;
    SET_GPR_U64(ctx, 7, (uint64_t)GPR_U64(ctx, 20) + (uint64_t)GPR_U64(ctx, 0));
    // 0x12a4f0: 0xc04bf38  jal         func_12FCE0
    ctx->pc = 0x12A4F0u;
    SET_GPR_U32(ctx, 31, 0x12A4F8u);
    ctx->pc = 0x12A4F4u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x12A4F0u;
            // 0x12a4f4: 0x220202d  daddu       $a0, $s1, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x12FCE0u;
    if (runtime->hasFunction(0x12FCE0u)) {
        auto targetFn = runtime->lookupFunction(0x12FCE0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x12A4F8u; }
        if (ctx->pc != 0x12A4F8u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0012FCE0_0x12fce0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x12A4F8u; }
        if (ctx->pc != 0x12A4F8u) { return; }
    }
    ctx->pc = 0x12A4F8u;
label_12a4f8:
    // 0x12a4f8: 0xc04be70  jal         func_12F9C0
    ctx->pc = 0x12A4F8u;
    SET_GPR_U32(ctx, 31, 0x12A500u);
    ctx->pc = 0x12A4FCu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x12A4F8u;
            // 0x12a4fc: 0x220202d  daddu       $a0, $s1, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x12F9C0u;
    if (runtime->hasFunction(0x12F9C0u)) {
        auto targetFn = runtime->lookupFunction(0x12F9C0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x12A500u; }
        if (ctx->pc != 0x12A500u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0012F9C0_0x12f9c0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x12A500u; }
        if (ctx->pc != 0x12A500u) { return; }
    }
    ctx->pc = 0x12A500u;
label_12a500:
    // 0x12a500: 0xc04c00e  jal         func_130038
    ctx->pc = 0x12A500u;
    SET_GPR_U32(ctx, 31, 0x12A508u);
    ctx->pc = 0x130038u;
    if (runtime->hasFunction(0x130038u)) {
        auto targetFn = runtime->lookupFunction(0x130038u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x12A508u; }
        if (ctx->pc != 0x12A508u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00130038_0x130038(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x12A508u; }
        if (ctx->pc != 0x12A508u) { return; }
    }
    ctx->pc = 0x12A508u;
label_12a508:
    // 0x12a508: 0x8ea30000  lw          $v1, 0x0($s5)
    ctx->pc = 0x12a508u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 21), 0)));
    // 0x12a50c: 0x27b30010  addiu       $s3, $sp, 0x10
    ctx->pc = 0x12a50cu;
    SET_GPR_S32(ctx, 19, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
    // 0x12a510: 0x24060400  addiu       $a2, $zero, 0x400
    ctx->pc = 0x12a510u;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 0), 1024));
    // 0x12a514: 0x2a0202d  daddu       $a0, $s5, $zero
    ctx->pc = 0x12a514u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 21) + (uint64_t)GPR_U64(ctx, 0));
    // 0x12a518: 0x8c620018  lw          $v0, 0x18($v1)
    ctx->pc = 0x12a518u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 3), 24)));
    // 0x12a51c: 0x24050001  addiu       $a1, $zero, 0x1
    ctx->pc = 0x12a51cu;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x12a520: 0x40f809  jalr        $v0
    ctx->pc = 0x12A520u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 2);
        SET_GPR_U32(ctx, 31, 0x12A528u);
        ctx->pc = 0x12A524u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x12A520u;
            // 0x12a524: 0x260382d  daddu       $a3, $s3, $zero (Delay Slot)
        SET_GPR_U64(ctx, 7, (uint64_t)GPR_U64(ctx, 19) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (jumpTarget == 0u) {
            ctx->pc = 0x12A528u;
        } else {
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x12A494u: goto label_12a494;
            case 0x12A4A8u: goto label_12a4a8;
            case 0x12A4B8u: goto label_12a4b8;
            case 0x12A4C8u: goto label_12a4c8;
            case 0x12A4E0u: goto label_12a4e0;
            case 0x12A4F8u: goto label_12a4f8;
            case 0x12A500u: goto label_12a500;
            case 0x12A508u: goto label_12a508;
            case 0x12A528u: goto label_12a528;
            case 0x12A538u: goto label_12a538;
            case 0x12A558u: goto label_12a558;
            case 0x12A570u: goto label_12a570;
            case 0x12A588u: goto label_12a588;
            case 0x12A5A8u: goto label_12a5a8;
            case 0x12A5B0u: goto label_12a5b0;
            case 0x12A5C8u: goto label_12a5c8;
            case 0x12A5E0u: goto label_12a5e0;
            case 0x12A5E8u: goto label_12a5e8;
            case 0x12A5F0u: goto label_12a5f0;
            case 0x12A600u: goto label_12a600;
            case 0x12A614u: goto label_12a614;
            case 0x12A628u: goto label_12a628;
            case 0x12A630u: goto label_12a630;
            default: break;
        }
        {
            auto targetFn = runtime->lookupFunction(jumpTarget);
            const uint32_t __entryPc = ctx->pc;
            targetFn(rdram, ctx, runtime);
            if (ctx->pc == __entryPc) { ctx->pc = 0x12A528u; }
            if (ctx->pc != 0x12A528u) { return; }
        }
        }
    }
    ctx->pc = 0x12A528u;
label_12a528:
    // 0x12a528: 0x8fa60014  lw          $a2, 0x14($sp)
    ctx->pc = 0x12a528u;
    SET_GPR_S32(ctx, 6, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 20)));
    // 0x12a52c: 0x54c0000a  bnel        $a2, $zero, . + 4 + (0xA << 2)
    ctx->pc = 0x12A52Cu;
    {
        const bool branch_taken_0x12a52c = (GPR_U64(ctx, 6) != GPR_U64(ctx, 0));
        if (branch_taken_0x12a52c) {
            ctx->pc = 0x12A530u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x12A52Cu;
            // 0x12a530: 0x8e020000  lw          $v0, 0x0($s0) (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 0)));
        ctx->in_delay_slot = false;
            ctx->pc = 0x12A558u;
            goto label_12a558;
        }
    }
    ctx->pc = 0x12A534u;
    // 0x12a534: 0x0  nop
    ctx->pc = 0x12a534u;
    // NOP
label_12a538:
    // 0x12a538: 0x0  nop
    ctx->pc = 0x12a538u;
    // NOP
    // 0x12a53c: 0x0  nop
    ctx->pc = 0x12a53cu;
    // NOP
    // 0x12a540: 0x0  nop
    ctx->pc = 0x12a540u;
    // NOP
    // 0x12a544: 0x0  nop
    ctx->pc = 0x12a544u;
    // NOP
    // 0x12a548: 0x0  nop
    ctx->pc = 0x12a548u;
    // NOP
    // 0x12a54c: 0x1000fffa  b           . + 4 + (-0x6 << 2)
    ctx->pc = 0x12A54Cu;
    {
        const bool branch_taken_0x12a54c = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x12a54c) {
            ctx->pc = 0x12A538u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_12a538;
        }
    }
    ctx->pc = 0x12A554u;
    // 0x12a554: 0x0  nop
    ctx->pc = 0x12a554u;
    // NOP
label_12a558:
    // 0x12a558: 0x27b20020  addiu       $s2, $sp, 0x20
    ctx->pc = 0x12a558u;
    SET_GPR_S32(ctx, 18, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
    // 0x12a55c: 0x200202d  daddu       $a0, $s0, $zero
    ctx->pc = 0x12a55cu;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x12a560: 0x282d  daddu       $a1, $zero, $zero
    ctx->pc = 0x12a560u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x12a564: 0x8c430018  lw          $v1, 0x18($v0)
    ctx->pc = 0x12a564u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 24)));
    // 0x12a568: 0x60f809  jalr        $v1
    ctx->pc = 0x12A568u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 3);
        SET_GPR_U32(ctx, 31, 0x12A570u);
        ctx->pc = 0x12A56Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x12A568u;
            // 0x12a56c: 0x240382d  daddu       $a3, $s2, $zero (Delay Slot)
        SET_GPR_U64(ctx, 7, (uint64_t)GPR_U64(ctx, 18) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (jumpTarget == 0u) {
            ctx->pc = 0x12A570u;
        } else {
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x12A494u: goto label_12a494;
            case 0x12A4A8u: goto label_12a4a8;
            case 0x12A4B8u: goto label_12a4b8;
            case 0x12A4C8u: goto label_12a4c8;
            case 0x12A4E0u: goto label_12a4e0;
            case 0x12A4F8u: goto label_12a4f8;
            case 0x12A500u: goto label_12a500;
            case 0x12A508u: goto label_12a508;
            case 0x12A528u: goto label_12a528;
            case 0x12A538u: goto label_12a538;
            case 0x12A558u: goto label_12a558;
            case 0x12A570u: goto label_12a570;
            case 0x12A588u: goto label_12a588;
            case 0x12A5A8u: goto label_12a5a8;
            case 0x12A5B0u: goto label_12a5b0;
            case 0x12A5C8u: goto label_12a5c8;
            case 0x12A5E0u: goto label_12a5e0;
            case 0x12A5E8u: goto label_12a5e8;
            case 0x12A5F0u: goto label_12a5f0;
            case 0x12A600u: goto label_12a600;
            case 0x12A614u: goto label_12a614;
            case 0x12A628u: goto label_12a628;
            case 0x12A630u: goto label_12a630;
            default: break;
        }
        {
            auto targetFn = runtime->lookupFunction(jumpTarget);
            const uint32_t __entryPc = ctx->pc;
            targetFn(rdram, ctx, runtime);
            if (ctx->pc == __entryPc) { ctx->pc = 0x12A570u; }
            if (ctx->pc != 0x12A570u) { return; }
        }
        }
    }
    ctx->pc = 0x12A570u;
label_12a570:
    // 0x12a570: 0x8fa20024  lw          $v0, 0x24($sp)
    ctx->pc = 0x12a570u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 36)));
    // 0x12a574: 0x8fa60014  lw          $a2, 0x14($sp)
    ctx->pc = 0x12a574u;
    SET_GPR_S32(ctx, 6, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 20)));
    // 0x12a578: 0x46102a  slt         $v0, $v0, $a2
    ctx->pc = 0x12a578u;
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 2) < (int64_t)GPR_S64(ctx, 6)) ? 1 : 0);
    // 0x12a57c: 0x1040000a  beqz        $v0, . + 4 + (0xA << 2)
    ctx->pc = 0x12A57Cu;
    {
        const bool branch_taken_0x12a57c = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x12A580u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x12A57Cu;
            // 0x12a580: 0x8fa40020  lw          $a0, 0x20($sp) (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 32)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x12a57c) {
            ctx->pc = 0x12A5A8u;
            goto label_12a5a8;
        }
    }
    ctx->pc = 0x12A584u;
    // 0x12a584: 0x0  nop
    ctx->pc = 0x12a584u;
    // NOP
label_12a588:
    // 0x12a588: 0x0  nop
    ctx->pc = 0x12a588u;
    // NOP
    // 0x12a58c: 0x0  nop
    ctx->pc = 0x12a58cu;
    // NOP
    // 0x12a590: 0x0  nop
    ctx->pc = 0x12a590u;
    // NOP
    // 0x12a594: 0x0  nop
    ctx->pc = 0x12a594u;
    // NOP
    // 0x12a598: 0x0  nop
    ctx->pc = 0x12a598u;
    // NOP
    // 0x12a59c: 0x1000fffa  b           . + 4 + (-0x6 << 2)
    ctx->pc = 0x12A59Cu;
    {
        const bool branch_taken_0x12a59c = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x12a59c) {
            ctx->pc = 0x12A588u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_12a588;
        }
    }
    ctx->pc = 0x12A5A4u;
    // 0x12a5a4: 0x0  nop
    ctx->pc = 0x12a5a4u;
    // NOP
label_12a5a8:
    // 0x12a5a8: 0xc041eac  jal         func_107AB0
    ctx->pc = 0x12A5A8u;
    SET_GPR_U32(ctx, 31, 0x12A5B0u);
    ctx->pc = 0x12A5ACu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x12A5A8u;
            // 0x12a5ac: 0x8fa50010  lw          $a1, 0x10($sp) (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 16)));
        ctx->in_delay_slot = false;
    ctx->pc = 0x107AB0u;
    if (runtime->hasFunction(0x107AB0u)) {
        auto targetFn = runtime->lookupFunction(0x107AB0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x12A5B0u; }
        if (ctx->pc != 0x12A5B0u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00107AB0_0x107ab0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x12A5B0u; }
        if (ctx->pc != 0x12A5B0u) { return; }
    }
    ctx->pc = 0x12A5B0u;
label_12a5b0:
    // 0x12a5b0: 0x8ea30000  lw          $v1, 0x0($s5)
    ctx->pc = 0x12a5b0u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 21), 0)));
    // 0x12a5b4: 0x260302d  daddu       $a2, $s3, $zero
    ctx->pc = 0x12a5b4u;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 19) + (uint64_t)GPR_U64(ctx, 0));
    // 0x12a5b8: 0x2a0202d  daddu       $a0, $s5, $zero
    ctx->pc = 0x12a5b8u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 21) + (uint64_t)GPR_U64(ctx, 0));
    // 0x12a5bc: 0x8c620020  lw          $v0, 0x20($v1)
    ctx->pc = 0x12a5bcu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 3), 32)));
    // 0x12a5c0: 0x40f809  jalr        $v0
    ctx->pc = 0x12A5C0u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 2);
        SET_GPR_U32(ctx, 31, 0x12A5C8u);
        ctx->pc = 0x12A5C4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x12A5C0u;
            // 0x12a5c4: 0x282d  daddu       $a1, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (jumpTarget == 0u) {
            ctx->pc = 0x12A5C8u;
        } else {
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x12A494u: goto label_12a494;
            case 0x12A4A8u: goto label_12a4a8;
            case 0x12A4B8u: goto label_12a4b8;
            case 0x12A4C8u: goto label_12a4c8;
            case 0x12A4E0u: goto label_12a4e0;
            case 0x12A4F8u: goto label_12a4f8;
            case 0x12A500u: goto label_12a500;
            case 0x12A508u: goto label_12a508;
            case 0x12A528u: goto label_12a528;
            case 0x12A538u: goto label_12a538;
            case 0x12A558u: goto label_12a558;
            case 0x12A570u: goto label_12a570;
            case 0x12A588u: goto label_12a588;
            case 0x12A5A8u: goto label_12a5a8;
            case 0x12A5B0u: goto label_12a5b0;
            case 0x12A5C8u: goto label_12a5c8;
            case 0x12A5E0u: goto label_12a5e0;
            case 0x12A5E8u: goto label_12a5e8;
            case 0x12A5F0u: goto label_12a5f0;
            case 0x12A600u: goto label_12a600;
            case 0x12A614u: goto label_12a614;
            case 0x12A628u: goto label_12a628;
            case 0x12A630u: goto label_12a630;
            default: break;
        }
        {
            auto targetFn = runtime->lookupFunction(jumpTarget);
            const uint32_t __entryPc = ctx->pc;
            targetFn(rdram, ctx, runtime);
            if (ctx->pc == __entryPc) { ctx->pc = 0x12A5C8u; }
            if (ctx->pc != 0x12A5C8u) { return; }
        }
        }
    }
    ctx->pc = 0x12A5C8u;
label_12a5c8:
    // 0x12a5c8: 0x8e030000  lw          $v1, 0x0($s0)
    ctx->pc = 0x12a5c8u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 0)));
    // 0x12a5cc: 0x240302d  daddu       $a2, $s2, $zero
    ctx->pc = 0x12a5ccu;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 18) + (uint64_t)GPR_U64(ctx, 0));
    // 0x12a5d0: 0x24050001  addiu       $a1, $zero, 0x1
    ctx->pc = 0x12a5d0u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x12a5d4: 0x8c620020  lw          $v0, 0x20($v1)
    ctx->pc = 0x12a5d4u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 3), 32)));
    // 0x12a5d8: 0x40f809  jalr        $v0
    ctx->pc = 0x12A5D8u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 2);
        SET_GPR_U32(ctx, 31, 0x12A5E0u);
        ctx->pc = 0x12A5DCu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x12A5D8u;
            // 0x12a5dc: 0x200202d  daddu       $a0, $s0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (jumpTarget == 0u) {
            ctx->pc = 0x12A5E0u;
        } else {
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x12A494u: goto label_12a494;
            case 0x12A4A8u: goto label_12a4a8;
            case 0x12A4B8u: goto label_12a4b8;
            case 0x12A4C8u: goto label_12a4c8;
            case 0x12A4E0u: goto label_12a4e0;
            case 0x12A4F8u: goto label_12a4f8;
            case 0x12A500u: goto label_12a500;
            case 0x12A508u: goto label_12a508;
            case 0x12A528u: goto label_12a528;
            case 0x12A538u: goto label_12a538;
            case 0x12A558u: goto label_12a558;
            case 0x12A570u: goto label_12a570;
            case 0x12A588u: goto label_12a588;
            case 0x12A5A8u: goto label_12a5a8;
            case 0x12A5B0u: goto label_12a5b0;
            case 0x12A5C8u: goto label_12a5c8;
            case 0x12A5E0u: goto label_12a5e0;
            case 0x12A5E8u: goto label_12a5e8;
            case 0x12A5F0u: goto label_12a5f0;
            case 0x12A600u: goto label_12a600;
            case 0x12A614u: goto label_12a614;
            case 0x12A628u: goto label_12a628;
            case 0x12A630u: goto label_12a630;
            default: break;
        }
        {
            auto targetFn = runtime->lookupFunction(jumpTarget);
            const uint32_t __entryPc = ctx->pc;
            targetFn(rdram, ctx, runtime);
            if (ctx->pc == __entryPc) { ctx->pc = 0x12A5E0u; }
            if (ctx->pc != 0x12A5E0u) { return; }
        }
        }
    }
    ctx->pc = 0x12A5E0u;
label_12a5e0:
    // 0x12a5e0: 0xc04beba  jal         func_12FAE8
    ctx->pc = 0x12A5E0u;
    SET_GPR_U32(ctx, 31, 0x12A5E8u);
    ctx->pc = 0x12A5E4u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x12A5E0u;
            // 0x12a5e4: 0x220202d  daddu       $a0, $s1, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x12FAE8u;
    if (runtime->hasFunction(0x12FAE8u)) {
        auto targetFn = runtime->lookupFunction(0x12FAE8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x12A5E8u; }
        if (ctx->pc != 0x12A5E8u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0012FAE8_0x12fae8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x12A5E8u; }
        if (ctx->pc != 0x12A5E8u) { return; }
    }
    ctx->pc = 0x12A5E8u;
label_12a5e8:
    // 0x12a5e8: 0xc04be54  jal         func_12F950
    ctx->pc = 0x12A5E8u;
    SET_GPR_U32(ctx, 31, 0x12A5F0u);
    ctx->pc = 0x12A5ECu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x12A5E8u;
            // 0x12a5ec: 0x220202d  daddu       $a0, $s1, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x12F950u;
    if (runtime->hasFunction(0x12F950u)) {
        auto targetFn = runtime->lookupFunction(0x12F950u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x12A5F0u; }
        if (ctx->pc != 0x12A5F0u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0012F950_0x12f950(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x12A5F0u; }
        if (ctx->pc != 0x12A5F0u) { return; }
    }
    ctx->pc = 0x12A5F0u;
label_12a5f0:
    // 0x12a5f0: 0x8ea30000  lw          $v1, 0x0($s5)
    ctx->pc = 0x12a5f0u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 21), 0)));
    // 0x12a5f4: 0x8c62000c  lw          $v0, 0xC($v1)
    ctx->pc = 0x12a5f4u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 3), 12)));
    // 0x12a5f8: 0x40f809  jalr        $v0
    ctx->pc = 0x12A5F8u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 2);
        SET_GPR_U32(ctx, 31, 0x12A600u);
        ctx->pc = 0x12A5FCu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x12A5F8u;
            // 0x12a5fc: 0x2a0202d  daddu       $a0, $s5, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 21) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (jumpTarget == 0u) {
            ctx->pc = 0x12A600u;
        } else {
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x12A494u: goto label_12a494;
            case 0x12A4A8u: goto label_12a4a8;
            case 0x12A4B8u: goto label_12a4b8;
            case 0x12A4C8u: goto label_12a4c8;
            case 0x12A4E0u: goto label_12a4e0;
            case 0x12A4F8u: goto label_12a4f8;
            case 0x12A500u: goto label_12a500;
            case 0x12A508u: goto label_12a508;
            case 0x12A528u: goto label_12a528;
            case 0x12A538u: goto label_12a538;
            case 0x12A558u: goto label_12a558;
            case 0x12A570u: goto label_12a570;
            case 0x12A588u: goto label_12a588;
            case 0x12A5A8u: goto label_12a5a8;
            case 0x12A5B0u: goto label_12a5b0;
            case 0x12A5C8u: goto label_12a5c8;
            case 0x12A5E0u: goto label_12a5e0;
            case 0x12A5E8u: goto label_12a5e8;
            case 0x12A5F0u: goto label_12a5f0;
            case 0x12A600u: goto label_12a600;
            case 0x12A614u: goto label_12a614;
            case 0x12A628u: goto label_12a628;
            case 0x12A630u: goto label_12a630;
            default: break;
        }
        {
            auto targetFn = runtime->lookupFunction(jumpTarget);
            const uint32_t __entryPc = ctx->pc;
            targetFn(rdram, ctx, runtime);
            if (ctx->pc == __entryPc) { ctx->pc = 0x12A600u; }
            if (ctx->pc != 0x12A600u) { return; }
        }
        }
    }
    ctx->pc = 0x12A600u;
label_12a600:
    // 0x12a600: 0x8fa40004  lw          $a0, 0x4($sp)
    ctx->pc = 0x12a600u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 4)));
    // 0x12a604: 0x8c830000  lw          $v1, 0x0($a0)
    ctx->pc = 0x12a604u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 0)));
    // 0x12a608: 0x8c62000c  lw          $v0, 0xC($v1)
    ctx->pc = 0x12a608u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 3), 12)));
    // 0x12a60c: 0x40f809  jalr        $v0
    ctx->pc = 0x12A60Cu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 2);
        SET_GPR_U32(ctx, 31, 0x12A614u);
        if (jumpTarget == 0u) {
            ctx->pc = 0x12A614u;
        } else {
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x12A494u: goto label_12a494;
            case 0x12A4A8u: goto label_12a4a8;
            case 0x12A4B8u: goto label_12a4b8;
            case 0x12A4C8u: goto label_12a4c8;
            case 0x12A4E0u: goto label_12a4e0;
            case 0x12A4F8u: goto label_12a4f8;
            case 0x12A500u: goto label_12a500;
            case 0x12A508u: goto label_12a508;
            case 0x12A528u: goto label_12a528;
            case 0x12A538u: goto label_12a538;
            case 0x12A558u: goto label_12a558;
            case 0x12A570u: goto label_12a570;
            case 0x12A588u: goto label_12a588;
            case 0x12A5A8u: goto label_12a5a8;
            case 0x12A5B0u: goto label_12a5b0;
            case 0x12A5C8u: goto label_12a5c8;
            case 0x12A5E0u: goto label_12a5e0;
            case 0x12A5E8u: goto label_12a5e8;
            case 0x12A5F0u: goto label_12a5f0;
            case 0x12A600u: goto label_12a600;
            case 0x12A614u: goto label_12a614;
            case 0x12A628u: goto label_12a628;
            case 0x12A630u: goto label_12a630;
            default: break;
        }
        {
            auto targetFn = runtime->lookupFunction(jumpTarget);
            const uint32_t __entryPc = ctx->pc;
            targetFn(rdram, ctx, runtime);
            if (ctx->pc == __entryPc) { ctx->pc = 0x12A614u; }
            if (ctx->pc != 0x12A614u) { return; }
        }
        }
    }
    ctx->pc = 0x12A614u;
label_12a614:
    // 0x12a614: 0x8fa40000  lw          $a0, 0x0($sp)
    ctx->pc = 0x12a614u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x12a618: 0x8c830000  lw          $v1, 0x0($a0)
    ctx->pc = 0x12a618u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 0)));
    // 0x12a61c: 0x8c62000c  lw          $v0, 0xC($v1)
    ctx->pc = 0x12a61cu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 3), 12)));
    // 0x12a620: 0x40f809  jalr        $v0
    ctx->pc = 0x12A620u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 2);
        SET_GPR_U32(ctx, 31, 0x12A628u);
        if (jumpTarget == 0u) {
            ctx->pc = 0x12A628u;
        } else {
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x12A494u: goto label_12a494;
            case 0x12A4A8u: goto label_12a4a8;
            case 0x12A4B8u: goto label_12a4b8;
            case 0x12A4C8u: goto label_12a4c8;
            case 0x12A4E0u: goto label_12a4e0;
            case 0x12A4F8u: goto label_12a4f8;
            case 0x12A500u: goto label_12a500;
            case 0x12A508u: goto label_12a508;
            case 0x12A528u: goto label_12a528;
            case 0x12A538u: goto label_12a538;
            case 0x12A558u: goto label_12a558;
            case 0x12A570u: goto label_12a570;
            case 0x12A588u: goto label_12a588;
            case 0x12A5A8u: goto label_12a5a8;
            case 0x12A5B0u: goto label_12a5b0;
            case 0x12A5C8u: goto label_12a5c8;
            case 0x12A5E0u: goto label_12a5e0;
            case 0x12A5E8u: goto label_12a5e8;
            case 0x12A5F0u: goto label_12a5f0;
            case 0x12A600u: goto label_12a600;
            case 0x12A614u: goto label_12a614;
            case 0x12A628u: goto label_12a628;
            case 0x12A630u: goto label_12a630;
            default: break;
        }
        {
            auto targetFn = runtime->lookupFunction(jumpTarget);
            const uint32_t __entryPc = ctx->pc;
            targetFn(rdram, ctx, runtime);
            if (ctx->pc == __entryPc) { ctx->pc = 0x12A628u; }
            if (ctx->pc != 0x12A628u) { return; }
        }
        }
    }
    ctx->pc = 0x12A628u;
label_12a628:
    // 0x12a628: 0xc04bdd4  jal         func_12F750
    ctx->pc = 0x12A628u;
    SET_GPR_U32(ctx, 31, 0x12A630u);
    ctx->pc = 0x12F750u;
    if (runtime->hasFunction(0x12F750u)) {
        auto targetFn = runtime->lookupFunction(0x12F750u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x12A630u; }
        if (ctx->pc != 0x12A630u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0012F750_0x12f750(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x12A630u; }
        if (ctx->pc != 0x12A630u) { return; }
    }
    ctx->pc = 0x12A630u;
label_12a630:
    // 0x12a630: 0xdfb00030  ld          $s0, 0x30($sp)
    ctx->pc = 0x12a630u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 48)));
    // 0x12a634: 0xdfb10038  ld          $s1, 0x38($sp)
    ctx->pc = 0x12a634u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 56)));
    // 0x12a638: 0xdfb20040  ld          $s2, 0x40($sp)
    ctx->pc = 0x12a638u;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 29), 64)));
    // 0x12a63c: 0xdfb30048  ld          $s3, 0x48($sp)
    ctx->pc = 0x12a63cu;
    SET_GPR_U64(ctx, 19, READ64(ADD32(GPR_U32(ctx, 29), 72)));
    // 0x12a640: 0xdfb40050  ld          $s4, 0x50($sp)
    ctx->pc = 0x12a640u;
    SET_GPR_U64(ctx, 20, READ64(ADD32(GPR_U32(ctx, 29), 80)));
    // 0x12a644: 0xdfb50058  ld          $s5, 0x58($sp)
    ctx->pc = 0x12a644u;
    SET_GPR_U64(ctx, 21, READ64(ADD32(GPR_U32(ctx, 29), 88)));
    // 0x12a648: 0xdfbf0060  ld          $ra, 0x60($sp)
    ctx->pc = 0x12a648u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 96)));
    // 0x12a64c: 0x3e00008  jr          $ra
    ctx->pc = 0x12A64Cu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x12A650u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x12A64Cu;
            // 0x12a650: 0x27bd0070  addiu       $sp, $sp, 0x70 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 112));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x12A494u: goto label_12a494;
            case 0x12A4A8u: goto label_12a4a8;
            case 0x12A4B8u: goto label_12a4b8;
            case 0x12A4C8u: goto label_12a4c8;
            case 0x12A4E0u: goto label_12a4e0;
            case 0x12A4F8u: goto label_12a4f8;
            case 0x12A500u: goto label_12a500;
            case 0x12A508u: goto label_12a508;
            case 0x12A528u: goto label_12a528;
            case 0x12A538u: goto label_12a538;
            case 0x12A558u: goto label_12a558;
            case 0x12A570u: goto label_12a570;
            case 0x12A588u: goto label_12a588;
            case 0x12A5A8u: goto label_12a5a8;
            case 0x12A5B0u: goto label_12a5b0;
            case 0x12A5C8u: goto label_12a5c8;
            case 0x12A5E0u: goto label_12a5e0;
            case 0x12A5E8u: goto label_12a5e8;
            case 0x12A5F0u: goto label_12a5f0;
            case 0x12A600u: goto label_12a600;
            case 0x12A614u: goto label_12a614;
            case 0x12A628u: goto label_12a628;
            case 0x12A630u: goto label_12a630;
            default: break;
        }
        return;
    }
    ctx->pc = 0x12A654u;
    // 0x12a654: 0x0  nop
    ctx->pc = 0x12a654u;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
