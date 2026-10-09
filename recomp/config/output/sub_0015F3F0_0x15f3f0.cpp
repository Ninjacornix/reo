#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_0015F3F0
// Address: 0x15f3f0 - 0x15f5b0
void sub_0015F3F0_0x15f3f0(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_0015F3F0_0x15f3f0");
#endif

    switch (ctx->pc) {
        case 0x15f414u: goto label_15f414;
        case 0x15f428u: goto label_15f428;
        case 0x15f448u: goto label_15f448;
        case 0x15f470u: goto label_15f470;
        case 0x15f488u: goto label_15f488;
        case 0x15f498u: goto label_15f498;
        case 0x15f4a4u: goto label_15f4a4;
        case 0x15f4b4u: goto label_15f4b4;
        case 0x15f4e0u: goto label_15f4e0;
        case 0x15f4ecu: goto label_15f4ec;
        case 0x15f534u: goto label_15f534;
        case 0x15f568u: goto label_15f568;
        case 0x15f57cu: goto label_15f57c;
        case 0x15f58cu: goto label_15f58c;
        default: break;
    }

    ctx->pc = 0x15f3f0u;

    // 0x15f3f0: 0x27bdffc0  addiu       $sp, $sp, -0x40
    ctx->pc = 0x15f3f0u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967232));
    // 0x15f3f4: 0xffb00010  sd          $s0, 0x10($sp)
    ctx->pc = 0x15f3f4u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 16));
    // 0x15f3f8: 0x80802d  daddu       $s0, $a0, $zero
    ctx->pc = 0x15f3f8u;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x15f3fc: 0xffb20020  sd          $s2, 0x20($sp)
    ctx->pc = 0x15f3fcu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 32), GPR_U64(ctx, 18));
    // 0x15f400: 0xffb10018  sd          $s1, 0x18($sp)
    ctx->pc = 0x15f400u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 24), GPR_U64(ctx, 17));
    // 0x15f404: 0xffb30028  sd          $s3, 0x28($sp)
    ctx->pc = 0x15f404u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 40), GPR_U64(ctx, 19));
    // 0x15f408: 0xffbf0030  sd          $ra, 0x30($sp)
    ctx->pc = 0x15f408u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 48), GPR_U64(ctx, 31));
    // 0x15f40c: 0xc057ff0  jal         func_15FFC0
    ctx->pc = 0x15F40Cu;
    SET_GPR_U32(ctx, 31, 0x15F414u);
    ctx->pc = 0x15F410u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x15F40Cu;
            // 0x15f410: 0xa0902d  daddu       $s2, $a1, $zero (Delay Slot)
        SET_GPR_U64(ctx, 18, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x15FFC0u;
    if (runtime->hasFunction(0x15FFC0u)) {
        auto targetFn = runtime->lookupFunction(0x15FFC0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x15F414u; }
        if (ctx->pc != 0x15F414u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0015FFC0_0x15ffc0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x15F414u; }
        if (ctx->pc != 0x15F414u) { return; }
    }
    ctx->pc = 0x15F414u;
label_15f414:
    // 0x15f414: 0x54400006  bnel        $v0, $zero, . + 4 + (0x6 << 2)
    ctx->pc = 0x15F414u;
    {
        const bool branch_taken_0x15f414 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x15f414) {
            ctx->pc = 0x15F418u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x15F414u;
            // 0x15f418: 0x82020072  lb          $v0, 0x72($s0) (Delay Slot)
        SET_GPR_S32(ctx, 2, (int8_t)READ8(ADD32(GPR_U32(ctx, 16), 114)));
        ctx->in_delay_slot = false;
            ctx->pc = 0x15F430u;
            goto label_15f430;
        }
    }
    ctx->pc = 0x15F41Cu;
    // 0x15f41c: 0x3c040024  lui         $a0, 0x24
    ctx->pc = 0x15f41cu;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)36 << 16));
    // 0x15f420: 0xc058dd4  jal         func_163750
    ctx->pc = 0x15F420u;
    SET_GPR_U32(ctx, 31, 0x15F428u);
    ctx->pc = 0x15F424u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x15F420u;
            // 0x15f424: 0x2484f1c8  addiu       $a0, $a0, -0xE38 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 4294963656));
        ctx->in_delay_slot = false;
    ctx->pc = 0x163750u;
    if (runtime->hasFunction(0x163750u)) {
        auto targetFn = runtime->lookupFunction(0x163750u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x15F428u; }
        if (ctx->pc != 0x15F428u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00163750_0x163750(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x15F428u; }
        if (ctx->pc != 0x15F428u) { return; }
    }
    ctx->pc = 0x15F428u;
label_15f428:
    // 0x15f428: 0x10000032  b           . + 4 + (0x32 << 2)
    ctx->pc = 0x15F428u;
    {
        const bool branch_taken_0x15f428 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x15F42Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x15F428u;
            // 0x15f42c: 0xdfb00010  ld          $s0, 0x10($sp) (Delay Slot)
        SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 16)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x15f428) {
            ctx->pc = 0x15F4F4u;
            goto label_15f4f4;
        }
    }
    ctx->pc = 0x15F430u;
label_15f430:
    // 0x15f430: 0x14400003  bnez        $v0, . + 4 + (0x3 << 2)
    ctx->pc = 0x15F430u;
    {
        const bool branch_taken_0x15f430 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x15F434u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x15F430u;
            // 0x15f434: 0x8e130040  lw          $s3, 0x40($s0) (Delay Slot)
        SET_GPR_S32(ctx, 19, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 64)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x15f430) {
            ctx->pc = 0x15F440u;
            goto label_15f440;
        }
    }
    ctx->pc = 0x15F438u;
    // 0x15f438: 0x5240002e  beql        $s2, $zero, . + 4 + (0x2E << 2)
    ctx->pc = 0x15F438u;
    {
        const bool branch_taken_0x15f438 = (GPR_U64(ctx, 18) == GPR_U64(ctx, 0));
        if (branch_taken_0x15f438) {
            ctx->pc = 0x15F43Cu;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x15F438u;
            // 0x15f43c: 0xdfb00010  ld          $s0, 0x10($sp) (Delay Slot)
        SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 16)));
        ctx->in_delay_slot = false;
            ctx->pc = 0x15F4F4u;
            goto label_15f4f4;
        }
    }
    ctx->pc = 0x15F440u;
label_15f440:
    // 0x15f440: 0xc057a5e  jal         func_15E978
    ctx->pc = 0x15F440u;
    SET_GPR_U32(ctx, 31, 0x15F448u);
    ctx->pc = 0x15E978u;
    if (runtime->hasFunction(0x15E978u)) {
        auto targetFn = runtime->lookupFunction(0x15E978u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x15F448u; }
        if (ctx->pc != 0x15F448u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0015E978_0x15e978(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x15F448u; }
        if (ctx->pc != 0x15F448u) { return; }
    }
    ctx->pc = 0x15F448u;
label_15f448:
    // 0x15f448: 0x40182d  daddu       $v1, $v0, $zero
    ctx->pc = 0x15f448u;
    SET_GPR_U64(ctx, 3, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x15f44c: 0x24020001  addiu       $v0, $zero, 0x1
    ctx->pc = 0x15f44cu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x15f450: 0x14620012  bne         $v1, $v0, . + 4 + (0x12 << 2)
    ctx->pc = 0x15F450u;
    {
        const bool branch_taken_0x15f450 = (GPR_U64(ctx, 3) != GPR_U64(ctx, 2));
        ctx->pc = 0x15F454u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x15F450u;
            // 0x15f454: 0x260202d  daddu       $a0, $s3, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 19) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x15f450) {
            ctx->pc = 0x15F49Cu;
            goto label_15f49c;
        }
    }
    ctx->pc = 0x15F458u;
    // 0x15f458: 0x8e11000c  lw          $s1, 0xC($s0)
    ctx->pc = 0x15f458u;
    SET_GPR_S32(ctx, 17, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 12)));
    // 0x15f45c: 0x1623000f  bne         $s1, $v1, . + 4 + (0xF << 2)
    ctx->pc = 0x15F45Cu;
    {
        const bool branch_taken_0x15f45c = (GPR_U64(ctx, 17) != GPR_U64(ctx, 3));
        if (branch_taken_0x15f45c) {
            ctx->pc = 0x15F49Cu;
            goto label_15f49c;
        }
    }
    ctx->pc = 0x15F464u;
    // 0x15f464: 0x24050006  addiu       $a1, $zero, 0x6
    ctx->pc = 0x15f464u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 6));
    // 0x15f468: 0xc05d562  jal         func_175588
    ctx->pc = 0x15F468u;
    SET_GPR_U32(ctx, 31, 0x15F470u);
    ctx->pc = 0x15F46Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x15F468u;
            // 0x15f46c: 0x3a0302d  daddu       $a2, $sp, $zero (Delay Slot)
        SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 29) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x175588u;
    if (runtime->hasFunction(0x175588u)) {
        auto targetFn = runtime->lookupFunction(0x175588u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x15F470u; }
        if (ctx->pc != 0x15F470u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00175588_0x175588(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x15F470u; }
        if (ctx->pc != 0x15F470u) { return; }
    }
    ctx->pc = 0x15F470u;
label_15f470:
    // 0x15f470: 0x14400007  bnez        $v0, . + 4 + (0x7 << 2)
    ctx->pc = 0x15F470u;
    {
        const bool branch_taken_0x15f470 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x15F474u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x15F470u;
            // 0x15f474: 0x8fa20000  lw          $v0, 0x0($sp) (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 0)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x15f470) {
            ctx->pc = 0x15F490u;
            goto label_15f490;
        }
    }
    ctx->pc = 0x15F478u;
    // 0x15f478: 0x54510008  bnel        $v0, $s1, . + 4 + (0x8 << 2)
    ctx->pc = 0x15F478u;
    {
        const bool branch_taken_0x15f478 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 17));
        if (branch_taken_0x15f478) {
            ctx->pc = 0x15F47Cu;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x15F478u;
            // 0x15f47c: 0x260202d  daddu       $a0, $s3, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 19) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
            ctx->pc = 0x15F49Cu;
            goto label_15f49c;
        }
    }
    ctx->pc = 0x15F480u;
    // 0x15f480: 0xc0590ec  jal         func_1643B0
    ctx->pc = 0x15F480u;
    SET_GPR_U32(ctx, 31, 0x15F488u);
    ctx->pc = 0x15F484u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x15F480u;
            // 0x15f484: 0x200202d  daddu       $a0, $s0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1643B0u;
    if (runtime->hasFunction(0x1643B0u)) {
        auto targetFn = runtime->lookupFunction(0x1643B0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x15F488u; }
        if (ctx->pc != 0x15F488u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001643B0_0x1643b0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x15F488u; }
        if (ctx->pc != 0x15F488u) { return; }
    }
    ctx->pc = 0x15F488u;
label_15f488:
    // 0x15f488: 0x10000004  b           . + 4 + (0x4 << 2)
    ctx->pc = 0x15F488u;
    {
        const bool branch_taken_0x15f488 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x15F48Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x15F488u;
            // 0x15f48c: 0x260202d  daddu       $a0, $s3, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 19) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x15f488) {
            ctx->pc = 0x15F49Cu;
            goto label_15f49c;
        }
    }
    ctx->pc = 0x15F490u;
label_15f490:
    // 0x15f490: 0xc0590ec  jal         func_1643B0
    ctx->pc = 0x15F490u;
    SET_GPR_U32(ctx, 31, 0x15F498u);
    ctx->pc = 0x15F494u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x15F490u;
            // 0x15f494: 0x200202d  daddu       $a0, $s0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1643B0u;
    if (runtime->hasFunction(0x1643B0u)) {
        auto targetFn = runtime->lookupFunction(0x1643B0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x15F498u; }
        if (ctx->pc != 0x15F498u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001643B0_0x1643b0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x15F498u; }
        if (ctx->pc != 0x15F498u) { return; }
    }
    ctx->pc = 0x15F498u;
label_15f498:
    // 0x15f498: 0x260202d  daddu       $a0, $s3, $zero
    ctx->pc = 0x15f498u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 19) + (uint64_t)GPR_U64(ctx, 0));
label_15f49c:
    // 0x15f49c: 0xc05c832  jal         func_1720C8
    ctx->pc = 0x15F49Cu;
    SET_GPR_U32(ctx, 31, 0x15F4A4u);
    ctx->pc = 0x15F4A0u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x15F49Cu;
            // 0x15f4a0: 0x240282d  daddu       $a1, $s2, $zero (Delay Slot)
        SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 18) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1720C8u;
    if (runtime->hasFunction(0x1720C8u)) {
        auto targetFn = runtime->lookupFunction(0x1720C8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x15F4A4u; }
        if (ctx->pc != 0x15F4A4u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001720C8_0x1720c8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x15F4A4u; }
        if (ctx->pc != 0x15F4A4u) { return; }
    }
    ctx->pc = 0x15F4A4u;
label_15f4a4:
    // 0x15f4a4: 0x5040000f  beql        $v0, $zero, . + 4 + (0xF << 2)
    ctx->pc = 0x15F4A4u;
    {
        const bool branch_taken_0x15f4a4 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        if (branch_taken_0x15f4a4) {
            ctx->pc = 0x15F4A8u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x15F4A4u;
            // 0x15f4a8: 0x260401ec  addiu       $a0, $s0, 0x1EC (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 16), 492));
        ctx->in_delay_slot = false;
            ctx->pc = 0x15F4E4u;
            goto label_15f4e4;
        }
    }
    ctx->pc = 0x15F4ACu;
    // 0x15f4ac: 0xc057abc  jal         func_15EAF0
    ctx->pc = 0x15F4ACu;
    SET_GPR_U32(ctx, 31, 0x15F4B4u);
    ctx->pc = 0x15F4B0u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x15F4ACu;
            // 0x15f4b0: 0x2404feca  addiu       $a0, $zero, -0x136 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 4294966986));
        ctx->in_delay_slot = false;
    ctx->pc = 0x15EAF0u;
    if (runtime->hasFunction(0x15EAF0u)) {
        auto targetFn = runtime->lookupFunction(0x15EAF0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x15F4B4u; }
        if (ctx->pc != 0x15F4B4u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0015EAF0_0x15eaf0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x15F4B4u; }
        if (ctx->pc != 0x15F4B4u) { return; }
    }
    ctx->pc = 0x15F4B4u;
label_15f4b4:
    // 0x15f4b4: 0x3c030024  lui         $v1, 0x24
    ctx->pc = 0x15f4b4u;
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)36 << 16));
    // 0x15f4b8: 0x24020001  addiu       $v0, $zero, 0x1
    ctx->pc = 0x15f4b8u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x15f4bc: 0x16420004  bne         $s2, $v0, . + 4 + (0x4 << 2)
    ctx->pc = 0x15F4BCu;
    {
        const bool branch_taken_0x15f4bc = (GPR_U64(ctx, 18) != GPR_U64(ctx, 2));
        ctx->pc = 0x15F4C0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x15F4BCu;
            // 0x15f4c0: 0x2464f1f0  addiu       $a0, $v1, -0xE10 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 3), 4294963696));
        ctx->in_delay_slot = false;
        if (branch_taken_0x15f4bc) {
            ctx->pc = 0x15F4D0u;
            goto label_15f4d0;
        }
    }
    ctx->pc = 0x15F4C4u;
    // 0x15f4c4: 0x3c020024  lui         $v0, 0x24
    ctx->pc = 0x15f4c4u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)36 << 16));
    // 0x15f4c8: 0x10000003  b           . + 4 + (0x3 << 2)
    ctx->pc = 0x15F4C8u;
    {
        const bool branch_taken_0x15f4c8 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x15F4CCu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x15F4C8u;
            // 0x15f4cc: 0x2445f218  addiu       $a1, $v0, -0xDE8 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 2), 4294963736));
        ctx->in_delay_slot = false;
        if (branch_taken_0x15f4c8) {
            ctx->pc = 0x15F4D8u;
            goto label_15f4d8;
        }
    }
    ctx->pc = 0x15F4D0u;
label_15f4d0:
    // 0x15f4d0: 0x3c020024  lui         $v0, 0x24
    ctx->pc = 0x15f4d0u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)36 << 16));
    // 0x15f4d4: 0x2445f220  addiu       $a1, $v0, -0xDE0
    ctx->pc = 0x15f4d4u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 2), 4294963744));
label_15f4d8:
    // 0x15f4d8: 0xc058dd4  jal         func_163750
    ctx->pc = 0x15F4D8u;
    SET_GPR_U32(ctx, 31, 0x15F4E0u);
    ctx->pc = 0x163750u;
    if (runtime->hasFunction(0x163750u)) {
        auto targetFn = runtime->lookupFunction(0x163750u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x15F4E0u; }
        if (ctx->pc != 0x15F4E0u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00163750_0x163750(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x15F4E0u; }
        if (ctx->pc != 0x15F4E0u) { return; }
    }
    ctx->pc = 0x15F4E0u;
label_15f4e0:
    // 0x15f4e0: 0x260401ec  addiu       $a0, $s0, 0x1EC
    ctx->pc = 0x15f4e0u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 16), 492));
label_15f4e4:
    // 0x15f4e4: 0xc058c1e  jal         func_163078
    ctx->pc = 0x15F4E4u;
    SET_GPR_U32(ctx, 31, 0x15F4ECu);
    ctx->pc = 0x15F4E8u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x15F4E4u;
            // 0x15f4e8: 0x240282d  daddu       $a1, $s2, $zero (Delay Slot)
        SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 18) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x163078u;
    if (runtime->hasFunction(0x163078u)) {
        auto targetFn = runtime->lookupFunction(0x163078u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x15F4ECu; }
        if (ctx->pc != 0x15F4ECu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00163078_0x163078(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x15F4ECu; }
        if (ctx->pc != 0x15F4ECu) { return; }
    }
    ctx->pc = 0x15F4ECu;
label_15f4ec:
    // 0x15f4ec: 0xa2120072  sb          $s2, 0x72($s0)
    ctx->pc = 0x15f4ecu;
    WRITE8(ADD32(GPR_U32(ctx, 16), 114), (uint8_t)GPR_U32(ctx, 18));
    // 0x15f4f0: 0xdfb00010  ld          $s0, 0x10($sp)
    ctx->pc = 0x15f4f0u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 16)));
label_15f4f4:
    // 0x15f4f4: 0xdfb10018  ld          $s1, 0x18($sp)
    ctx->pc = 0x15f4f4u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 24)));
    // 0x15f4f8: 0xdfb20020  ld          $s2, 0x20($sp)
    ctx->pc = 0x15f4f8u;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x15f4fc: 0xdfb30028  ld          $s3, 0x28($sp)
    ctx->pc = 0x15f4fcu;
    SET_GPR_U64(ctx, 19, READ64(ADD32(GPR_U32(ctx, 29), 40)));
    // 0x15f500: 0xdfbf0030  ld          $ra, 0x30($sp)
    ctx->pc = 0x15f500u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 48)));
    // 0x15f504: 0x3e00008  jr          $ra
    ctx->pc = 0x15F504u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x15F508u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x15F504u;
            // 0x15f508: 0x27bd0040  addiu       $sp, $sp, 0x40 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 64));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x15F414u: goto label_15f414;
            case 0x15F428u: goto label_15f428;
            case 0x15F430u: goto label_15f430;
            case 0x15F440u: goto label_15f440;
            case 0x15F448u: goto label_15f448;
            case 0x15F470u: goto label_15f470;
            case 0x15F488u: goto label_15f488;
            case 0x15F490u: goto label_15f490;
            case 0x15F498u: goto label_15f498;
            case 0x15F49Cu: goto label_15f49c;
            case 0x15F4A4u: goto label_15f4a4;
            case 0x15F4B4u: goto label_15f4b4;
            case 0x15F4D0u: goto label_15f4d0;
            case 0x15F4D8u: goto label_15f4d8;
            case 0x15F4E0u: goto label_15f4e0;
            case 0x15F4E4u: goto label_15f4e4;
            case 0x15F4ECu: goto label_15f4ec;
            case 0x15F4F4u: goto label_15f4f4;
            case 0x15F534u: goto label_15f534;
            case 0x15F560u: goto label_15f560;
            case 0x15F568u: goto label_15f568;
            case 0x15F57Cu: goto label_15f57c;
            case 0x15F58Cu: goto label_15f58c;
            default: break;
        }
        return;
    }
    ctx->pc = 0x15F50Cu;
    // 0x15f50c: 0x0  nop
    ctx->pc = 0x15f50cu;
    // NOP
    // 0x15f510: 0x27bdffe0  addiu       $sp, $sp, -0x20
    ctx->pc = 0x15f510u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967264));
    // 0x15f514: 0xffb00000  sd          $s0, 0x0($sp)
    ctx->pc = 0x15f514u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x15f518: 0x80802d  daddu       $s0, $a0, $zero
    ctx->pc = 0x15f518u;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x15f51c: 0xffb10008  sd          $s1, 0x8($sp)
    ctx->pc = 0x15f51cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 8), GPR_U64(ctx, 17));
    // 0x15f520: 0xa0882d  daddu       $s1, $a1, $zero
    ctx->pc = 0x15f520u;
    SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
    // 0x15f524: 0xffb20010  sd          $s2, 0x10($sp)
    ctx->pc = 0x15f524u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 18));
    // 0x15f528: 0xffbf0018  sd          $ra, 0x18($sp)
    ctx->pc = 0x15f528u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 24), GPR_U64(ctx, 31));
    // 0x15f52c: 0xc057ff0  jal         func_15FFC0
    ctx->pc = 0x15F52Cu;
    SET_GPR_U32(ctx, 31, 0x15F534u);
    ctx->pc = 0x15F530u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x15F52Cu;
            // 0x15f530: 0xc0902d  daddu       $s2, $a2, $zero (Delay Slot)
        SET_GPR_U64(ctx, 18, (uint64_t)GPR_U64(ctx, 6) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x15FFC0u;
    if (runtime->hasFunction(0x15FFC0u)) {
        auto targetFn = runtime->lookupFunction(0x15FFC0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x15F534u; }
        if (ctx->pc != 0x15F534u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0015FFC0_0x15ffc0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x15F534u; }
        if (ctx->pc != 0x15F534u) { return; }
    }
    ctx->pc = 0x15F534u;
label_15f534:
    // 0x15f534: 0x1440000a  bnez        $v0, . + 4 + (0xA << 2)
    ctx->pc = 0x15F534u;
    {
        const bool branch_taken_0x15f534 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x15F538u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x15F534u;
            // 0x15f538: 0x200202d  daddu       $a0, $s0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x15f534) {
            ctx->pc = 0x15F560u;
            goto label_15f560;
        }
    }
    ctx->pc = 0x15F53Cu;
    // 0x15f53c: 0x3c040024  lui         $a0, 0x24
    ctx->pc = 0x15f53cu;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)36 << 16));
    // 0x15f540: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x15f540u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x15f544: 0xdfb10008  ld          $s1, 0x8($sp)
    ctx->pc = 0x15f544u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x15f548: 0x2484f228  addiu       $a0, $a0, -0xDD8
    ctx->pc = 0x15f548u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 4294963752));
    // 0x15f54c: 0xdfb20010  ld          $s2, 0x10($sp)
    ctx->pc = 0x15f54cu;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x15f550: 0xdfbf0018  ld          $ra, 0x18($sp)
    ctx->pc = 0x15f550u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 24)));
    // 0x15f554: 0x8058dd4  j           func_163750
    ctx->pc = 0x15F554u;
    ctx->pc = 0x15F558u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x15F554u;
            // 0x15f558: 0x27bd0020  addiu       $sp, $sp, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
        ctx->in_delay_slot = false;
    ctx->pc = 0x163750u;
    if (runtime->hasFunction(0x163750u)) {
        auto targetFn = runtime->lookupFunction(0x163750u);
        targetFn(rdram, ctx, runtime); return;
    } else {
        sub_00163750_0x163750(rdram, ctx, runtime); return;
    }
    ctx->pc = 0x15F55Cu;
    // 0x15f55c: 0x0  nop
    ctx->pc = 0x15f55cu;
    // NOP
label_15f560:
    // 0x15f560: 0xc0581f6  jal         func_1607D8
    ctx->pc = 0x15F560u;
    SET_GPR_U32(ctx, 31, 0x15F568u);
    ctx->pc = 0x1607D8u;
    if (runtime->hasFunction(0x1607D8u)) {
        auto targetFn = runtime->lookupFunction(0x1607D8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x15F568u; }
        if (ctx->pc != 0x15F568u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001607D8_0x1607d8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x15F568u; }
        if (ctx->pc != 0x15F568u) { return; }
    }
    ctx->pc = 0x15F568u;
label_15f568:
    // 0x15f568: 0x40282d  daddu       $a1, $v0, $zero
    ctx->pc = 0x15f568u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x15f56c: 0x8e020000  lw          $v0, 0x0($s0)
    ctx->pc = 0x15f56cu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 0)));
    // 0x15f570: 0x8c43003c  lw          $v1, 0x3C($v0)
    ctx->pc = 0x15f570u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 60)));
    // 0x15f574: 0x60f809  jalr        $v1
    ctx->pc = 0x15F574u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 3);
        SET_GPR_U32(ctx, 31, 0x15F57Cu);
        ctx->pc = 0x15F578u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x15F574u;
            // 0x15f578: 0x200202d  daddu       $a0, $s0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (jumpTarget == 0u) {
            ctx->pc = 0x15F57Cu;
        } else {
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x15F414u: goto label_15f414;
            case 0x15F428u: goto label_15f428;
            case 0x15F430u: goto label_15f430;
            case 0x15F440u: goto label_15f440;
            case 0x15F448u: goto label_15f448;
            case 0x15F470u: goto label_15f470;
            case 0x15F488u: goto label_15f488;
            case 0x15F490u: goto label_15f490;
            case 0x15F498u: goto label_15f498;
            case 0x15F49Cu: goto label_15f49c;
            case 0x15F4A4u: goto label_15f4a4;
            case 0x15F4B4u: goto label_15f4b4;
            case 0x15F4D0u: goto label_15f4d0;
            case 0x15F4D8u: goto label_15f4d8;
            case 0x15F4E0u: goto label_15f4e0;
            case 0x15F4E4u: goto label_15f4e4;
            case 0x15F4ECu: goto label_15f4ec;
            case 0x15F4F4u: goto label_15f4f4;
            case 0x15F534u: goto label_15f534;
            case 0x15F560u: goto label_15f560;
            case 0x15F568u: goto label_15f568;
            case 0x15F57Cu: goto label_15f57c;
            case 0x15F58Cu: goto label_15f58c;
            default: break;
        }
        {
            auto targetFn = runtime->lookupFunction(jumpTarget);
            const uint32_t __entryPc = ctx->pc;
            targetFn(rdram, ctx, runtime);
            if (ctx->pc == __entryPc) { ctx->pc = 0x15F57Cu; }
            if (ctx->pc != 0x15F57Cu) { return; }
        }
        }
    }
    ctx->pc = 0x15F57Cu;
label_15f57c:
    // 0x15f57c: 0x200202d  daddu       $a0, $s0, $zero
    ctx->pc = 0x15f57cu;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x15f580: 0x220282d  daddu       $a1, $s1, $zero
    ctx->pc = 0x15f580u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
    // 0x15f584: 0xc057dc6  jal         func_15F718
    ctx->pc = 0x15F584u;
    SET_GPR_U32(ctx, 31, 0x15F58Cu);
    ctx->pc = 0x15F588u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x15F584u;
            // 0x15f588: 0x240302d  daddu       $a2, $s2, $zero (Delay Slot)
        SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 18) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x15F718u;
    if (runtime->hasFunction(0x15F718u)) {
        auto targetFn = runtime->lookupFunction(0x15F718u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x15F58Cu; }
        if (ctx->pc != 0x15F58Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0015F718_0x15f718(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x15F58Cu; }
        if (ctx->pc != 0x15F58Cu) { return; }
    }
    ctx->pc = 0x15F58Cu;
label_15f58c:
    // 0x15f58c: 0x24020001  addiu       $v0, $zero, 0x1
    ctx->pc = 0x15f58cu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x15f590: 0xae020118  sw          $v0, 0x118($s0)
    ctx->pc = 0x15f590u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 280), GPR_U32(ctx, 2));
    // 0x15f594: 0xdfb10008  ld          $s1, 0x8($sp)
    ctx->pc = 0x15f594u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x15f598: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x15f598u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x15f59c: 0xdfb20010  ld          $s2, 0x10($sp)
    ctx->pc = 0x15f59cu;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x15f5a0: 0xdfbf0018  ld          $ra, 0x18($sp)
    ctx->pc = 0x15f5a0u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 24)));
    // 0x15f5a4: 0x3e00008  jr          $ra
    ctx->pc = 0x15F5A4u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x15F5A8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x15F5A4u;
            // 0x15f5a8: 0x27bd0020  addiu       $sp, $sp, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x15F414u: goto label_15f414;
            case 0x15F428u: goto label_15f428;
            case 0x15F430u: goto label_15f430;
            case 0x15F440u: goto label_15f440;
            case 0x15F448u: goto label_15f448;
            case 0x15F470u: goto label_15f470;
            case 0x15F488u: goto label_15f488;
            case 0x15F490u: goto label_15f490;
            case 0x15F498u: goto label_15f498;
            case 0x15F49Cu: goto label_15f49c;
            case 0x15F4A4u: goto label_15f4a4;
            case 0x15F4B4u: goto label_15f4b4;
            case 0x15F4D0u: goto label_15f4d0;
            case 0x15F4D8u: goto label_15f4d8;
            case 0x15F4E0u: goto label_15f4e0;
            case 0x15F4E4u: goto label_15f4e4;
            case 0x15F4ECu: goto label_15f4ec;
            case 0x15F4F4u: goto label_15f4f4;
            case 0x15F534u: goto label_15f534;
            case 0x15F560u: goto label_15f560;
            case 0x15F568u: goto label_15f568;
            case 0x15F57Cu: goto label_15f57c;
            case 0x15F58Cu: goto label_15f58c;
            default: break;
        }
        return;
    }
    ctx->pc = 0x15F5ACu;
    // 0x15f5ac: 0x0  nop
    ctx->pc = 0x15f5acu;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
