#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_0011F408
// Address: 0x11f408 - 0x11f4f8
void sub_0011F408_0x11f408(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_0011F408_0x11f408");
#endif

    switch (ctx->pc) {
        case 0x11f478u: goto label_11f478;
        case 0x11f4bcu: goto label_11f4bc;
        case 0x11f4c4u: goto label_11f4c4;
        default: break;
    }

    ctx->pc = 0x11f408u;

    // 0x11f408: 0x27bdff90  addiu       $sp, $sp, -0x70
    ctx->pc = 0x11f408u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967184));
    // 0x11f40c: 0xffb50050  sd          $s5, 0x50($sp)
    ctx->pc = 0x11f40cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 80), GPR_U64(ctx, 21));
    // 0x11f410: 0xffb40040  sd          $s4, 0x40($sp)
    ctx->pc = 0x11f410u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 64), GPR_U64(ctx, 20));
    // 0x11f414: 0x80a82d  daddu       $s5, $a0, $zero
    ctx->pc = 0x11f414u;
    SET_GPR_U64(ctx, 21, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x11f418: 0xffb30030  sd          $s3, 0x30($sp)
    ctx->pc = 0x11f418u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 48), GPR_U64(ctx, 19));
    // 0x11f41c: 0xc0a02d  daddu       $s4, $a2, $zero
    ctx->pc = 0x11f41cu;
    SET_GPR_U64(ctx, 20, (uint64_t)GPR_U64(ctx, 6) + (uint64_t)GPR_U64(ctx, 0));
    // 0x11f420: 0xffbf0060  sd          $ra, 0x60($sp)
    ctx->pc = 0x11f420u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 96), GPR_U64(ctx, 31));
    // 0x11f424: 0xa0982d  daddu       $s3, $a1, $zero
    ctx->pc = 0x11f424u;
    SET_GPR_U64(ctx, 19, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
    // 0x11f428: 0xffb20020  sd          $s2, 0x20($sp)
    ctx->pc = 0x11f428u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 32), GPR_U64(ctx, 18));
    // 0x11f42c: 0xffb10010  sd          $s1, 0x10($sp)
    ctx->pc = 0x11f42cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 17));
    // 0x11f430: 0x16600004  bnez        $s3, . + 4 + (0x4 << 2)
    ctx->pc = 0x11F430u;
    {
        const bool branch_taken_0x11f430 = (GPR_U64(ctx, 19) != GPR_U64(ctx, 0));
        ctx->pc = 0x11F434u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x11F430u;
            // 0x11f434: 0xffb00000  sd          $s0, 0x0($sp) (Delay Slot)
        WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
        ctx->in_delay_slot = false;
        if (branch_taken_0x11f430) {
            ctx->pc = 0x11F444u;
            goto label_11f444;
        }
    }
    ctx->pc = 0x11F438u;
    // 0x11f438: 0x3c028000  lui         $v0, 0x8000
    ctx->pc = 0x11f438u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)32768 << 16));
    // 0x11f43c: 0x10000025  b           . + 4 + (0x25 << 2)
    ctx->pc = 0x11F43Cu;
    {
        const bool branch_taken_0x11f43c = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x11F440u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x11F43Cu;
            // 0x11f440: 0x34420016  ori         $v0, $v0, 0x16 (Delay Slot)
        SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) | (uint64_t)(uint16_t)22);
        ctx->in_delay_slot = false;
        if (branch_taken_0x11f43c) {
            ctx->pc = 0x11F4D4u;
            goto label_11f4d4;
        }
    }
    ctx->pc = 0x11F444u;
label_11f444:
    // 0x11f444: 0x3c120026  lui         $s2, 0x26
    ctx->pc = 0x11f444u;
    SET_GPR_S32(ctx, 18, (int32_t)((uint32_t)38 << 16));
    // 0x11f448: 0x8e501d00  lw          $s0, 0x1D00($s2)
    ctx->pc = 0x11f448u;
    SET_GPR_S32(ctx, 16, (int32_t)READ32(ADD32(GPR_U32(ctx, 18), 7424)));
    // 0x11f44c: 0x12000003  beqz        $s0, . + 4 + (0x3 << 2)
    ctx->pc = 0x11F44Cu;
    {
        const bool branch_taken_0x11f44c = (GPR_U64(ctx, 16) == GPR_U64(ctx, 0));
        if (branch_taken_0x11f44c) {
            ctx->pc = 0x11F45Cu;
            goto label_11f45c;
        }
    }
    ctx->pc = 0x11F454u;
    // 0x11f454: 0x8e020000  lw          $v0, 0x0($s0)
    ctx->pc = 0x11f454u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 0)));
    // 0x11f458: 0xae421d00  sw          $v0, 0x1D00($s2)
    ctx->pc = 0x11f458u;
    WRITE32(ADD32(GPR_U32(ctx, 18), 7424), GPR_U32(ctx, 2));
label_11f45c:
    // 0x11f45c: 0x16000004  bnez        $s0, . + 4 + (0x4 << 2)
    ctx->pc = 0x11F45Cu;
    {
        const bool branch_taken_0x11f45c = (GPR_U64(ctx, 16) != GPR_U64(ctx, 0));
        if (branch_taken_0x11f45c) {
            ctx->pc = 0x11F470u;
            goto label_11f470;
        }
    }
    ctx->pc = 0x11F464u;
    // 0x11f464: 0x3c028000  lui         $v0, 0x8000
    ctx->pc = 0x11f464u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)32768 << 16));
    // 0x11f468: 0x1000001a  b           . + 4 + (0x1A << 2)
    ctx->pc = 0x11F468u;
    {
        const bool branch_taken_0x11f468 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x11F46Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x11F468u;
            // 0x11f46c: 0x34428005  ori         $v0, $v0, 0x8005 (Delay Slot)
        SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) | (uint64_t)(uint16_t)32773);
        ctx->in_delay_slot = false;
        if (branch_taken_0x11f468) {
            ctx->pc = 0x11F4D4u;
            goto label_11f4d4;
        }
    }
    ctx->pc = 0x11F470u;
label_11f470:
    // 0x11f470: 0xc047a1c  jal         func_11E870
    ctx->pc = 0x11F470u;
    SET_GPR_U32(ctx, 31, 0x11F478u);
    ctx->pc = 0x11E870u;
    if (runtime->hasFunction(0x11E870u)) {
        auto targetFn = runtime->lookupFunction(0x11E870u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x11F478u; }
        if (ctx->pc != 0x11F478u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0011E870_0x11e870(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x11F478u; }
        if (ctx->pc != 0x11F478u) { return; }
    }
    ctx->pc = 0x11F478u;
label_11f478:
    // 0x11f478: 0x40882d  daddu       $s1, $v0, $zero
    ctx->pc = 0x11f478u;
    SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x11f47c: 0x6230007  bgezl       $s1, . + 4 + (0x7 << 2)
    ctx->pc = 0x11F47Cu;
    {
        const bool branch_taken_0x11f47c = (GPR_S64(ctx, 17) >= 0);
        if (branch_taken_0x11f47c) {
            ctx->pc = 0x11F480u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x11F47Cu;
            // 0x11f480: 0xae130008  sw          $s3, 0x8($s0) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 16), 8), GPR_U32(ctx, 19));
        ctx->in_delay_slot = false;
            ctx->pc = 0x11F49Cu;
            goto label_11f49c;
        }
    }
    ctx->pc = 0x11F484u;
    // 0x11f484: 0x8e431d00  lw          $v1, 0x1D00($s2)
    ctx->pc = 0x11f484u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 18), 7424)));
    // 0x11f488: 0xae501d00  sw          $s0, 0x1D00($s2)
    ctx->pc = 0x11f488u;
    WRITE32(ADD32(GPR_U32(ctx, 18), 7424), GPR_U32(ctx, 16));
    // 0x11f48c: 0xae030000  sw          $v1, 0x0($s0)
    ctx->pc = 0x11f48cu;
    WRITE32(ADD32(GPR_U32(ctx, 16), 0), GPR_U32(ctx, 3));
    // 0x11f490: 0xae000004  sw          $zero, 0x4($s0)
    ctx->pc = 0x11f490u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 4), GPR_U32(ctx, 0));
    // 0x11f494: 0x10000010  b           . + 4 + (0x10 << 2)
    ctx->pc = 0x11F494u;
    {
        const bool branch_taken_0x11f494 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x11F498u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x11F494u;
            // 0x11f498: 0xdfbf0060  ld          $ra, 0x60($sp) (Delay Slot)
        SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 96)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x11f494) {
            ctx->pc = 0x11F4D8u;
            goto label_11f4d8;
        }
    }
    ctx->pc = 0x11F49Cu;
label_11f49c:
    // 0x11f49c: 0x3c060012  lui         $a2, 0x12
    ctx->pc = 0x11f49cu;
    SET_GPR_S32(ctx, 6, (int32_t)((uint32_t)18 << 16));
    // 0x11f4a0: 0xae14000c  sw          $s4, 0xC($s0)
    ctx->pc = 0x11f4a0u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 12), GPR_U32(ctx, 20));
    // 0x11f4a4: 0x24c6f278  addiu       $a2, $a2, -0xD88
    ctx->pc = 0x11f4a4u;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 6), 4294963832));
    // 0x11f4a8: 0xae110004  sw          $s1, 0x4($s0)
    ctx->pc = 0x11f4a8u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 4), GPR_U32(ctx, 17));
    // 0x11f4ac: 0x2a0282d  daddu       $a1, $s5, $zero
    ctx->pc = 0x11f4acu;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 21) + (uint64_t)GPR_U64(ctx, 0));
    // 0x11f4b0: 0x220202d  daddu       $a0, $s1, $zero
    ctx->pc = 0x11f4b0u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
    // 0x11f4b4: 0xc047bc2  jal         func_11EF08
    ctx->pc = 0x11F4B4u;
    SET_GPR_U32(ctx, 31, 0x11F4BCu);
    ctx->pc = 0x11F4B8u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x11F4B4u;
            // 0x11f4b8: 0x200382d  daddu       $a3, $s0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 7, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x11EF08u;
    if (runtime->hasFunction(0x11EF08u)) {
        auto targetFn = runtime->lookupFunction(0x11EF08u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x11F4BCu; }
        if (ctx->pc != 0x11F4BCu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0011EF08_0x11ef08(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x11F4BCu; }
        if (ctx->pc != 0x11F4BCu) { return; }
    }
    ctx->pc = 0x11F4BCu;
label_11f4bc:
    // 0x11f4bc: 0xc047ab2  jal         func_11EAC8
    ctx->pc = 0x11F4BCu;
    SET_GPR_U32(ctx, 31, 0x11F4C4u);
    ctx->pc = 0x11F4C0u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x11F4BCu;
            // 0x11f4c0: 0x220202d  daddu       $a0, $s1, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x11EAC8u;
    if (runtime->hasFunction(0x11EAC8u)) {
        auto targetFn = runtime->lookupFunction(0x11EAC8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x11F4C4u; }
        if (ctx->pc != 0x11F4C4u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0011EAC8_0x11eac8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x11F4C4u; }
        if (ctx->pc != 0x11F4C4u) { return; }
    }
    ctx->pc = 0x11F4C4u;
label_11f4c4:
    // 0x11f4c4: 0x101100  sll         $v0, $s0, 4
    ctx->pc = 0x11f4c4u;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 16), 4));
    // 0x11f4c8: 0x322300fe  andi        $v1, $s1, 0xFE
    ctx->pc = 0x11f4c8u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 17) & (uint64_t)(uint16_t)254);
    // 0x11f4cc: 0x431025  or          $v0, $v0, $v1
    ctx->pc = 0x11f4ccu;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) | GPR_U64(ctx, 3));
    // 0x11f4d0: 0x34420001  ori         $v0, $v0, 0x1
    ctx->pc = 0x11f4d0u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) | (uint64_t)(uint16_t)1);
label_11f4d4:
    // 0x11f4d4: 0xdfbf0060  ld          $ra, 0x60($sp)
    ctx->pc = 0x11f4d4u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 96)));
label_11f4d8:
    // 0x11f4d8: 0xdfb50050  ld          $s5, 0x50($sp)
    ctx->pc = 0x11f4d8u;
    SET_GPR_U64(ctx, 21, READ64(ADD32(GPR_U32(ctx, 29), 80)));
    // 0x11f4dc: 0xdfb40040  ld          $s4, 0x40($sp)
    ctx->pc = 0x11f4dcu;
    SET_GPR_U64(ctx, 20, READ64(ADD32(GPR_U32(ctx, 29), 64)));
    // 0x11f4e0: 0xdfb30030  ld          $s3, 0x30($sp)
    ctx->pc = 0x11f4e0u;
    SET_GPR_U64(ctx, 19, READ64(ADD32(GPR_U32(ctx, 29), 48)));
    // 0x11f4e4: 0xdfb20020  ld          $s2, 0x20($sp)
    ctx->pc = 0x11f4e4u;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x11f4e8: 0xdfb10010  ld          $s1, 0x10($sp)
    ctx->pc = 0x11f4e8u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x11f4ec: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x11f4ecu;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x11f4f0: 0x3e00008  jr          $ra
    ctx->pc = 0x11F4F0u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x11F4F4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x11F4F0u;
            // 0x11f4f4: 0x27bd0070  addiu       $sp, $sp, 0x70 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 112));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x11F444u: goto label_11f444;
            case 0x11F45Cu: goto label_11f45c;
            case 0x11F470u: goto label_11f470;
            case 0x11F478u: goto label_11f478;
            case 0x11F49Cu: goto label_11f49c;
            case 0x11F4BCu: goto label_11f4bc;
            case 0x11F4C4u: goto label_11f4c4;
            case 0x11F4D4u: goto label_11f4d4;
            case 0x11F4D8u: goto label_11f4d8;
            default: break;
        }
        return;
    }
    ctx->pc = 0x11F4F8u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
