#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00179308
// Address: 0x179308 - 0x1793f8
void sub_00179308_0x179308(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00179308_0x179308");
#endif

    switch (ctx->pc) {
        case 0x17933cu: goto label_17933c;
        case 0x179380u: goto label_179380;
        case 0x1793acu: goto label_1793ac;
        default: break;
    }

    ctx->pc = 0x179308u;

    // 0x179308: 0x27bdffc0  addiu       $sp, $sp, -0x40
    ctx->pc = 0x179308u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967232));
    // 0x17930c: 0xffb00010  sd          $s0, 0x10($sp)
    ctx->pc = 0x17930cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 16));
    // 0x179310: 0x80802d  daddu       $s0, $a0, $zero
    ctx->pc = 0x179310u;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x179314: 0xffb10018  sd          $s1, 0x18($sp)
    ctx->pc = 0x179314u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 24), GPR_U64(ctx, 17));
    // 0x179318: 0xffb20020  sd          $s2, 0x20($sp)
    ctx->pc = 0x179318u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 32), GPR_U64(ctx, 18));
    // 0x17931c: 0xa0902d  daddu       $s2, $a1, $zero
    ctx->pc = 0x17931cu;
    SET_GPR_U64(ctx, 18, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
    // 0x179320: 0xffb30028  sd          $s3, 0x28($sp)
    ctx->pc = 0x179320u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 40), GPR_U64(ctx, 19));
    // 0x179324: 0x24130001  addiu       $s3, $zero, 0x1
    ctx->pc = 0x179324u;
    SET_GPR_S32(ctx, 19, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x179328: 0xffbf0030  sd          $ra, 0x30($sp)
    ctx->pc = 0x179328u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 48), GPR_U64(ctx, 31));
    // 0x17932c: 0xae400000  sw          $zero, 0x0($s2)
    ctx->pc = 0x17932cu;
    WRITE32(ADD32(GPR_U32(ctx, 18), 0), GPR_U32(ctx, 0));
    // 0x179330: 0x8e020004  lw          $v0, 0x4($s0)
    ctx->pc = 0x179330u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 4)));
    // 0x179334: 0xc05e4a2  jal         func_179288
    ctx->pc = 0x179334u;
    SET_GPR_U32(ctx, 31, 0x17933Cu);
    ctx->pc = 0x179338u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x179334u;
            // 0x179338: 0x24510020  addiu       $s1, $v0, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 2), 32));
        ctx->in_delay_slot = false;
    ctx->pc = 0x179288u;
    if (runtime->hasFunction(0x179288u)) {
        auto targetFn = runtime->lookupFunction(0x179288u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x17933Cu; }
        if (ctx->pc != 0x17933Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00179288_0x179288(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x17933Cu; }
        if (ctx->pc != 0x17933Cu) { return; }
    }
    ctx->pc = 0x17933Cu;
label_17933c:
    // 0x17933c: 0x54530004  bnel        $v0, $s3, . + 4 + (0x4 << 2)
    ctx->pc = 0x17933Cu;
    {
        const bool branch_taken_0x17933c = (GPR_U64(ctx, 2) != GPR_U64(ctx, 19));
        if (branch_taken_0x17933c) {
            ctx->pc = 0x179340u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x17933Cu;
            // 0x179340: 0x8e020008  lw          $v0, 0x8($s0) (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 8)));
        ctx->in_delay_slot = false;
            ctx->pc = 0x179350u;
            goto label_179350;
        }
    }
    ctx->pc = 0x179344u;
    // 0x179344: 0x10000025  b           . + 4 + (0x25 << 2)
    ctx->pc = 0x179344u;
    {
        const bool branch_taken_0x179344 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x179348u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x179344u;
            // 0x179348: 0x102d  daddu       $v0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x179344) {
            ctx->pc = 0x1793DCu;
            goto label_1793dc;
        }
    }
    ctx->pc = 0x17934Cu;
    // 0x17934c: 0x0  nop
    ctx->pc = 0x17934cu;
    // NOP
label_179350:
    // 0x179350: 0x2c420800  sltiu       $v0, $v0, 0x800
    ctx->pc = 0x179350u;
    SET_GPR_U64(ctx, 2, ((uint64_t)GPR_U64(ctx, 2) < (uint64_t)(int64_t)(int32_t)2048) ? 1 : 0);
    // 0x179354: 0x10400006  beqz        $v0, . + 4 + (0x6 << 2)
    ctx->pc = 0x179354u;
    {
        const bool branch_taken_0x179354 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x179358u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x179354u;
            // 0x179358: 0x3c050024  lui         $a1, 0x24 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)((uint32_t)36 << 16));
        ctx->in_delay_slot = false;
        if (branch_taken_0x179354) {
            ctx->pc = 0x179370u;
            goto label_179370;
        }
    }
    ctx->pc = 0x17935Cu;
    // 0x17935c: 0x2403ffff  addiu       $v1, $zero, -0x1
    ctx->pc = 0x17935cu;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
    // 0x179360: 0x102d  daddu       $v0, $zero, $zero
    ctx->pc = 0x179360u;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x179364: 0x1000001d  b           . + 4 + (0x1D << 2)
    ctx->pc = 0x179364u;
    {
        const bool branch_taken_0x179364 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x179368u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x179364u;
            // 0x179368: 0xae030000  sw          $v1, 0x0($s0) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 16), 0), GPR_U32(ctx, 3));
        ctx->in_delay_slot = false;
        if (branch_taken_0x179364) {
            ctx->pc = 0x1793DCu;
            goto label_1793dc;
        }
    }
    ctx->pc = 0x17936Cu;
    // 0x17936c: 0x0  nop
    ctx->pc = 0x17936cu;
    // NOP
label_179370:
    // 0x179370: 0x220202d  daddu       $a0, $s1, $zero
    ctx->pc = 0x179370u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
    // 0x179374: 0x24060018  addiu       $a2, $zero, 0x18
    ctx->pc = 0x179374u;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 0), 24));
    // 0x179378: 0xc041e86  jal         func_107A18
    ctx->pc = 0x179378u;
    SET_GPR_U32(ctx, 31, 0x179380u);
    ctx->pc = 0x17937Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x179378u;
            // 0x17937c: 0x24a50de8  addiu       $a1, $a1, 0xDE8 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 3560));
        ctx->in_delay_slot = false;
    ctx->pc = 0x107A18u;
    if (runtime->hasFunction(0x107A18u)) {
        auto targetFn = runtime->lookupFunction(0x107A18u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x179380u; }
        if (ctx->pc != 0x179380u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00107A18_0x107a18(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x179380u; }
        if (ctx->pc != 0x179380u) { return; }
    }
    ctx->pc = 0x179380u;
label_179380:
    // 0x179380: 0x200202d  daddu       $a0, $s0, $zero
    ctx->pc = 0x179380u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x179384: 0x3a0282d  daddu       $a1, $sp, $zero
    ctx->pc = 0x179384u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 29) + (uint64_t)GPR_U64(ctx, 0));
    // 0x179388: 0x10400005  beqz        $v0, . + 4 + (0x5 << 2)
    ctx->pc = 0x179388u;
    {
        const bool branch_taken_0x179388 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x17938Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x179388u;
            // 0x17938c: 0x27a60004  addiu       $a2, $sp, 0x4 (Delay Slot)
        SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 29), 4));
        ctx->in_delay_slot = false;
        if (branch_taken_0x179388) {
            ctx->pc = 0x1793A0u;
            goto label_1793a0;
        }
    }
    ctx->pc = 0x179390u;
    // 0x179390: 0x2402ffff  addiu       $v0, $zero, -0x1
    ctx->pc = 0x179390u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
    // 0x179394: 0xae020000  sw          $v0, 0x0($s0)
    ctx->pc = 0x179394u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 0), GPR_U32(ctx, 2));
    // 0x179398: 0x10000010  b           . + 4 + (0x10 << 2)
    ctx->pc = 0x179398u;
    {
        const bool branch_taken_0x179398 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x17939Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x179398u;
            // 0x17939c: 0x102d  daddu       $v0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x179398) {
            ctx->pc = 0x1793DCu;
            goto label_1793dc;
        }
    }
    ctx->pc = 0x1793A0u;
label_1793a0:
    // 0x1793a0: 0x24020002  addiu       $v0, $zero, 0x2
    ctx->pc = 0x1793a0u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 2));
    // 0x1793a4: 0xc05e5bc  jal         func_1796F0
    ctx->pc = 0x1793A4u;
    SET_GPR_U32(ctx, 31, 0x1793ACu);
    ctx->pc = 0x1793A8u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1793A4u;
            // 0x1793a8: 0xae020000  sw          $v0, 0x0($s0) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 16), 0), GPR_U32(ctx, 2));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1796F0u;
    if (runtime->hasFunction(0x1796F0u)) {
        auto targetFn = runtime->lookupFunction(0x1796F0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1793ACu; }
        if (ctx->pc != 0x1793ACu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001796F0_0x1796f0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1793ACu; }
        if (ctx->pc != 0x1793ACu) { return; }
    }
    ctx->pc = 0x1793ACu;
label_1793ac:
    // 0x1793ac: 0x1040000b  beqz        $v0, . + 4 + (0xB << 2)
    ctx->pc = 0x1793ACu;
    {
        const bool branch_taken_0x1793ac = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x1793B0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1793ACu;
            // 0x1793b0: 0x8fa30000  lw          $v1, 0x0($sp) (Delay Slot)
        SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 0)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1793ac) {
            ctx->pc = 0x1793DCu;
            goto label_1793dc;
        }
    }
    ctx->pc = 0x1793B4u;
    // 0x1793b4: 0x24020001  addiu       $v0, $zero, 0x1
    ctx->pc = 0x1793b4u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x1793b8: 0x8fa50004  lw          $a1, 0x4($sp)
    ctx->pc = 0x1793b8u;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 4)));
    // 0x1793bc: 0x32040  sll         $a0, $v1, 1
    ctx->pc = 0x1793bcu;
    SET_GPR_S32(ctx, 4, (int32_t)SLL32(GPR_U32(ctx, 3), 1));
    // 0x1793c0: 0x832021  addu        $a0, $a0, $v1
    ctx->pc = 0x1793c0u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), GPR_U32(ctx, 3)));
    // 0x1793c4: 0x420c0  sll         $a0, $a0, 3
    ctx->pc = 0x1793c4u;
    SET_GPR_S32(ctx, 4, (int32_t)SLL32(GPR_U32(ctx, 4), 3));
    // 0x1793c8: 0x832021  addu        $a0, $a0, $v1
    ctx->pc = 0x1793c8u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), GPR_U32(ctx, 3)));
    // 0x1793cc: 0x42080  sll         $a0, $a0, 2
    ctx->pc = 0x1793ccu;
    SET_GPR_S32(ctx, 4, (int32_t)SLL32(GPR_U32(ctx, 4), 2));
    // 0x1793d0: 0x852021  addu        $a0, $a0, $a1
    ctx->pc = 0x1793d0u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), GPR_U32(ctx, 5)));
    // 0x1793d4: 0xae04000c  sw          $a0, 0xC($s0)
    ctx->pc = 0x1793d4u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 12), GPR_U32(ctx, 4));
    // 0x1793d8: 0xae530000  sw          $s3, 0x0($s2)
    ctx->pc = 0x1793d8u;
    WRITE32(ADD32(GPR_U32(ctx, 18), 0), GPR_U32(ctx, 19));
label_1793dc:
    // 0x1793dc: 0xdfb00010  ld          $s0, 0x10($sp)
    ctx->pc = 0x1793dcu;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x1793e0: 0xdfb10018  ld          $s1, 0x18($sp)
    ctx->pc = 0x1793e0u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 24)));
    // 0x1793e4: 0xdfb20020  ld          $s2, 0x20($sp)
    ctx->pc = 0x1793e4u;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x1793e8: 0xdfb30028  ld          $s3, 0x28($sp)
    ctx->pc = 0x1793e8u;
    SET_GPR_U64(ctx, 19, READ64(ADD32(GPR_U32(ctx, 29), 40)));
    // 0x1793ec: 0xdfbf0030  ld          $ra, 0x30($sp)
    ctx->pc = 0x1793ecu;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 48)));
    // 0x1793f0: 0x3e00008  jr          $ra
    ctx->pc = 0x1793F0u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1793F4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1793F0u;
            // 0x1793f4: 0x27bd0040  addiu       $sp, $sp, 0x40 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 64));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x17933Cu: goto label_17933c;
            case 0x179350u: goto label_179350;
            case 0x179370u: goto label_179370;
            case 0x179380u: goto label_179380;
            case 0x1793A0u: goto label_1793a0;
            case 0x1793ACu: goto label_1793ac;
            case 0x1793DCu: goto label_1793dc;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1793F8u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
