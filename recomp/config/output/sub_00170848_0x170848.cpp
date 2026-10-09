#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00170848
// Address: 0x170848 - 0x17097c
void sub_00170848_0x170848(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00170848_0x170848");
#endif

    switch (ctx->pc) {
        case 0x170888u: goto label_170888;
        case 0x1708a8u: goto label_1708a8;
        case 0x1708c8u: goto label_1708c8;
        case 0x1708f0u: goto label_1708f0;
        case 0x170928u: goto label_170928;
        case 0x170940u: goto label_170940;
        case 0x17094cu: goto label_17094c;
        default: break;
    }

    ctx->pc = 0x170848u;

    // 0x170848: 0x27bdffa0  addiu       $sp, $sp, -0x60
    ctx->pc = 0x170848u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967200));
    // 0x17084c: 0xffb40030  sd          $s4, 0x30($sp)
    ctx->pc = 0x17084cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 48), GPR_U64(ctx, 20));
    // 0x170850: 0x80a02d  daddu       $s4, $a0, $zero
    ctx->pc = 0x170850u;
    SET_GPR_U64(ctx, 20, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x170854: 0x3a0202d  daddu       $a0, $sp, $zero
    ctx->pc = 0x170854u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 29) + (uint64_t)GPR_U64(ctx, 0));
    // 0x170858: 0xffb00010  sd          $s0, 0x10($sp)
    ctx->pc = 0x170858u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 16));
    // 0x17085c: 0xffb20020  sd          $s2, 0x20($sp)
    ctx->pc = 0x17085cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 32), GPR_U64(ctx, 18));
    // 0x170860: 0x902d  daddu       $s2, $zero, $zero
    ctx->pc = 0x170860u;
    SET_GPR_U64(ctx, 18, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x170864: 0xffb30028  sd          $s3, 0x28($sp)
    ctx->pc = 0x170864u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 40), GPR_U64(ctx, 19));
    // 0x170868: 0x982d  daddu       $s3, $zero, $zero
    ctx->pc = 0x170868u;
    SET_GPR_U64(ctx, 19, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x17086c: 0xffb50038  sd          $s5, 0x38($sp)
    ctx->pc = 0x17086cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 56), GPR_U64(ctx, 21));
    // 0x170870: 0xffb10018  sd          $s1, 0x18($sp)
    ctx->pc = 0x170870u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 24), GPR_U64(ctx, 17));
    // 0x170874: 0xffb60040  sd          $s6, 0x40($sp)
    ctx->pc = 0x170874u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 64), GPR_U64(ctx, 22));
    // 0x170878: 0xffb70048  sd          $s7, 0x48($sp)
    ctx->pc = 0x170878u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 72), GPR_U64(ctx, 23));
    // 0x17087c: 0xffbf0050  sd          $ra, 0x50($sp)
    ctx->pc = 0x17087cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 80), GPR_U64(ctx, 31));
    // 0x170880: 0xc05a7b2  jal         func_169EC8
    ctx->pc = 0x170880u;
    SET_GPR_U32(ctx, 31, 0x170888u);
    ctx->pc = 0x170884u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x170880u;
            // 0x170884: 0xa82d  daddu       $s5, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 21, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x169EC8u;
    if (runtime->hasFunction(0x169EC8u)) {
        auto targetFn = runtime->lookupFunction(0x169EC8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x170888u; }
        if (ctx->pc != 0x170888u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00169EC8_0x169ec8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x170888u; }
        if (ctx->pc != 0x170888u) { return; }
    }
    ctx->pc = 0x170888u;
label_170888:
    // 0x170888: 0x8e821b30  lw          $v0, 0x1B30($s4)
    ctx->pc = 0x170888u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 20), 6960)));
    // 0x17088c: 0x8c430138  lw          $v1, 0x138($v0)
    ctx->pc = 0x17088cu;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 312)));
    // 0x170890: 0x1860001b  blez        $v1, . + 4 + (0x1B << 2)
    ctx->pc = 0x170890u;
    {
        const bool branch_taken_0x170890 = (GPR_S64(ctx, 3) <= 0);
        ctx->pc = 0x170894u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x170890u;
            // 0x170894: 0x2450013c  addiu       $s0, $v0, 0x13C (Delay Slot)
        SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 2), 316));
        ctx->in_delay_slot = false;
        if (branch_taken_0x170890) {
            ctx->pc = 0x170900u;
            goto label_170900;
        }
    }
    ctx->pc = 0x170898u;
    // 0x170898: 0x60882d  daddu       $s1, $v1, $zero
    ctx->pc = 0x170898u;
    SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 3) + (uint64_t)GPR_U64(ctx, 0));
    // 0x17089c: 0x24170002  addiu       $s7, $zero, 0x2
    ctx->pc = 0x17089cu;
    SET_GPR_S32(ctx, 23, (int32_t)ADD32(GPR_U32(ctx, 0), 2));
    // 0x1708a0: 0x24160004  addiu       $s6, $zero, 0x4
    ctx->pc = 0x1708a0u;
    SET_GPR_S32(ctx, 22, (int32_t)ADD32(GPR_U32(ctx, 0), 4));
    // 0x1708a4: 0x0  nop
    ctx->pc = 0x1708a4u;
    // NOP
label_1708a8:
    // 0x1708a8: 0x8e020000  lw          $v0, 0x0($s0)
    ctx->pc = 0x1708a8u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 0)));
    // 0x1708ac: 0x10570004  beq         $v0, $s7, . + 4 + (0x4 << 2)
    ctx->pc = 0x1708ACu;
    {
        const bool branch_taken_0x1708ac = (GPR_U64(ctx, 2) == GPR_U64(ctx, 23));
        ctx->pc = 0x1708B0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1708ACu;
            // 0x1708b0: 0x260202d  daddu       $a0, $s3, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 19) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1708ac) {
            ctx->pc = 0x1708C0u;
            goto label_1708c0;
        }
    }
    ctx->pc = 0x1708B4u;
    // 0x1708b4: 0x54560010  bnel        $v0, $s6, . + 4 + (0x10 << 2)
    ctx->pc = 0x1708B4u;
    {
        const bool branch_taken_0x1708b4 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 22));
        if (branch_taken_0x1708b4) {
            ctx->pc = 0x1708B8u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x1708B4u;
            // 0x1708b8: 0x2631ffff  addiu       $s1, $s1, -0x1 (Delay Slot)
        SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 17), 4294967295));
        ctx->in_delay_slot = false;
            ctx->pc = 0x1708F8u;
            goto label_1708f8;
        }
    }
    ctx->pc = 0x1708BCu;
    // 0x1708bc: 0x260202d  daddu       $a0, $s3, $zero
    ctx->pc = 0x1708bcu;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 19) + (uint64_t)GPR_U64(ctx, 0));
label_1708c0:
    // 0x1708c0: 0xc05c260  jal         func_170980
    ctx->pc = 0x1708C0u;
    SET_GPR_U32(ctx, 31, 0x1708C8u);
    ctx->pc = 0x1708C4u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1708C0u;
            // 0x1708c4: 0x200282d  daddu       $a1, $s0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x170980u;
    if (runtime->hasFunction(0x170980u)) {
        auto targetFn = runtime->lookupFunction(0x170980u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1708C8u; }
        if (ctx->pc != 0x1708C8u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00170980_0x170980(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1708C8u; }
        if (ctx->pc != 0x1708C8u) { return; }
    }
    ctx->pc = 0x1708C8u;
label_1708c8:
    // 0x1708c8: 0x240202d  daddu       $a0, $s2, $zero
    ctx->pc = 0x1708c8u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 18) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1708cc: 0x26b50001  addiu       $s5, $s5, 0x1
    ctx->pc = 0x1708ccu;
    SET_GPR_S32(ctx, 21, (int32_t)ADD32(GPR_U32(ctx, 21), 1));
    // 0x1708d0: 0x10400005  beqz        $v0, . + 4 + (0x5 << 2)
    ctx->pc = 0x1708D0u;
    {
        const bool branch_taken_0x1708d0 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x1708D4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1708D0u;
            // 0x1708d4: 0x200282d  daddu       $a1, $s0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1708d0) {
            ctx->pc = 0x1708E8u;
            goto label_1708e8;
        }
    }
    ctx->pc = 0x1708D8u;
    // 0x1708d8: 0x260902d  daddu       $s2, $s3, $zero
    ctx->pc = 0x1708d8u;
    SET_GPR_U64(ctx, 18, (uint64_t)GPR_U64(ctx, 19) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1708dc: 0x10000005  b           . + 4 + (0x5 << 2)
    ctx->pc = 0x1708DCu;
    {
        const bool branch_taken_0x1708dc = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1708E0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1708DCu;
            // 0x1708e0: 0x200982d  daddu       $s3, $s0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 19, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1708dc) {
            ctx->pc = 0x1708F4u;
            goto label_1708f4;
        }
    }
    ctx->pc = 0x1708E4u;
    // 0x1708e4: 0x0  nop
    ctx->pc = 0x1708e4u;
    // NOP
label_1708e8:
    // 0x1708e8: 0xc05c260  jal         func_170980
    ctx->pc = 0x1708E8u;
    SET_GPR_U32(ctx, 31, 0x1708F0u);
    ctx->pc = 0x170980u;
    if (runtime->hasFunction(0x170980u)) {
        auto targetFn = runtime->lookupFunction(0x170980u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1708F0u; }
        if (ctx->pc != 0x1708F0u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00170980_0x170980(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1708F0u; }
        if (ctx->pc != 0x1708F0u) { return; }
    }
    ctx->pc = 0x1708F0u;
label_1708f0:
    // 0x1708f0: 0x202900b  movn        $s2, $s0, $v0
    ctx->pc = 0x1708f0u;
    if (GPR_U64(ctx, 2) != 0) SET_GPR_VEC(ctx, 18, GPR_VEC(ctx, 16));
label_1708f4:
    // 0x1708f4: 0x2631ffff  addiu       $s1, $s1, -0x1
    ctx->pc = 0x1708f4u;
    SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 17), 4294967295));
label_1708f8:
    // 0x1708f8: 0x1620ffeb  bnez        $s1, . + 4 + (-0x15 << 2)
    ctx->pc = 0x1708F8u;
    {
        const bool branch_taken_0x1708f8 = (GPR_U64(ctx, 17) != GPR_U64(ctx, 0));
        ctx->pc = 0x1708FCu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1708F8u;
            // 0x1708fc: 0x26100080  addiu       $s0, $s0, 0x80 (Delay Slot)
        SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 16), 128));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1708f8) {
            ctx->pc = 0x1708A8u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_1708a8;
        }
    }
    ctx->pc = 0x170900u;
label_170900:
    // 0x170900: 0x8e830048  lw          $v1, 0x48($s4)
    ctx->pc = 0x170900u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 20), 72)));
    // 0x170904: 0x24020004  addiu       $v0, $zero, 0x4
    ctx->pc = 0x170904u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4));
    // 0x170908: 0x1462000e  bne         $v1, $v0, . + 4 + (0xE << 2)
    ctx->pc = 0x170908u;
    {
        const bool branch_taken_0x170908 = (GPR_U64(ctx, 3) != GPR_U64(ctx, 2));
        ctx->pc = 0x17090Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x170908u;
            // 0x17090c: 0x802d  daddu       $s0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x170908) {
            ctx->pc = 0x170944u;
            goto label_170944;
        }
    }
    ctx->pc = 0x170910u;
    // 0x170910: 0x2aa20002  slti        $v0, $s5, 0x2
    ctx->pc = 0x170910u;
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 21) < (int64_t)(int32_t)2) ? 1 : 0);
    // 0x170914: 0x1440000b  bnez        $v0, . + 4 + (0xB << 2)
    ctx->pc = 0x170914u;
    {
        const bool branch_taken_0x170914 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x170914) {
            ctx->pc = 0x170944u;
            goto label_170944;
        }
    }
    ctx->pc = 0x17091Cu;
    // 0x17091c: 0x280202d  daddu       $a0, $s4, $zero
    ctx->pc = 0x17091cu;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 20) + (uint64_t)GPR_U64(ctx, 0));
    // 0x170920: 0xc05d58a  jal         func_175628
    ctx->pc = 0x170920u;
    SET_GPR_U32(ctx, 31, 0x170928u);
    ctx->pc = 0x170924u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x170920u;
            // 0x170924: 0x2405000f  addiu       $a1, $zero, 0xF (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 15));
        ctx->in_delay_slot = false;
    ctx->pc = 0x175628u;
    if (runtime->hasFunction(0x175628u)) {
        auto targetFn = runtime->lookupFunction(0x175628u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x170928u; }
        if (ctx->pc != 0x170928u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00175628_0x175628(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x170928u; }
        if (ctx->pc != 0x170928u) { return; }
    }
    ctx->pc = 0x170928u;
label_170928:
    // 0x170928: 0x10400006  beqz        $v0, . + 4 + (0x6 << 2)
    ctx->pc = 0x170928u;
    {
        const bool branch_taken_0x170928 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x17092Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x170928u;
            // 0x17092c: 0x24100001  addiu       $s0, $zero, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
        ctx->in_delay_slot = false;
        if (branch_taken_0x170928) {
            ctx->pc = 0x170944u;
            goto label_170944;
        }
    }
    ctx->pc = 0x170930u;
    // 0x170930: 0x8e460010  lw          $a2, 0x10($s2)
    ctx->pc = 0x170930u;
    SET_GPR_S32(ctx, 6, (int32_t)READ32(ADD32(GPR_U32(ctx, 18), 16)));
    // 0x170934: 0x280202d  daddu       $a0, $s4, $zero
    ctx->pc = 0x170934u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 20) + (uint64_t)GPR_U64(ctx, 0));
    // 0x170938: 0xc05dbda  jal         func_176F68
    ctx->pc = 0x170938u;
    SET_GPR_U32(ctx, 31, 0x170940u);
    ctx->pc = 0x17093Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x170938u;
            // 0x17093c: 0x8e45000c  lw          $a1, 0xC($s2) (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 18), 12)));
        ctx->in_delay_slot = false;
    ctx->pc = 0x176F68u;
    if (runtime->hasFunction(0x176F68u)) {
        auto targetFn = runtime->lookupFunction(0x176F68u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x170940u; }
        if (ctx->pc != 0x170940u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00176F68_0x176f68(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x170940u; }
        if (ctx->pc != 0x170940u) { return; }
    }
    ctx->pc = 0x170940u;
label_170940:
    // 0x170940: 0x2802b  sltu        $s0, $zero, $v0
    ctx->pc = 0x170940u;
    SET_GPR_U64(ctx, 16, ((uint64_t)GPR_U64(ctx, 0) < (uint64_t)GPR_U64(ctx, 2)) ? 1 : 0);
label_170944:
    // 0x170944: 0xc05a7b8  jal         func_169EE0
    ctx->pc = 0x170944u;
    SET_GPR_U32(ctx, 31, 0x17094Cu);
    ctx->pc = 0x170948u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x170944u;
            // 0x170948: 0x3a0202d  daddu       $a0, $sp, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 29) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x169EE0u;
    if (runtime->hasFunction(0x169EE0u)) {
        auto targetFn = runtime->lookupFunction(0x169EE0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x17094Cu; }
        if (ctx->pc != 0x17094Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00169EE0_0x169ee0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x17094Cu; }
        if (ctx->pc != 0x17094Cu) { return; }
    }
    ctx->pc = 0x17094Cu;
label_17094c:
    // 0x17094c: 0x200102d  daddu       $v0, $s0, $zero
    ctx->pc = 0x17094cu;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x170950: 0xdfb10018  ld          $s1, 0x18($sp)
    ctx->pc = 0x170950u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 24)));
    // 0x170954: 0xdfb00010  ld          $s0, 0x10($sp)
    ctx->pc = 0x170954u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x170958: 0xdfb20020  ld          $s2, 0x20($sp)
    ctx->pc = 0x170958u;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x17095c: 0xdfb30028  ld          $s3, 0x28($sp)
    ctx->pc = 0x17095cu;
    SET_GPR_U64(ctx, 19, READ64(ADD32(GPR_U32(ctx, 29), 40)));
    // 0x170960: 0xdfb40030  ld          $s4, 0x30($sp)
    ctx->pc = 0x170960u;
    SET_GPR_U64(ctx, 20, READ64(ADD32(GPR_U32(ctx, 29), 48)));
    // 0x170964: 0xdfb50038  ld          $s5, 0x38($sp)
    ctx->pc = 0x170964u;
    SET_GPR_U64(ctx, 21, READ64(ADD32(GPR_U32(ctx, 29), 56)));
    // 0x170968: 0xdfb60040  ld          $s6, 0x40($sp)
    ctx->pc = 0x170968u;
    SET_GPR_U64(ctx, 22, READ64(ADD32(GPR_U32(ctx, 29), 64)));
    // 0x17096c: 0xdfb70048  ld          $s7, 0x48($sp)
    ctx->pc = 0x17096cu;
    SET_GPR_U64(ctx, 23, READ64(ADD32(GPR_U32(ctx, 29), 72)));
    // 0x170970: 0xdfbf0050  ld          $ra, 0x50($sp)
    ctx->pc = 0x170970u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 80)));
    // 0x170974: 0x3e00008  jr          $ra
    ctx->pc = 0x170974u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x170978u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x170974u;
            // 0x170978: 0x27bd0060  addiu       $sp, $sp, 0x60 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 96));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x170888u: goto label_170888;
            case 0x1708A8u: goto label_1708a8;
            case 0x1708C0u: goto label_1708c0;
            case 0x1708C8u: goto label_1708c8;
            case 0x1708E8u: goto label_1708e8;
            case 0x1708F0u: goto label_1708f0;
            case 0x1708F4u: goto label_1708f4;
            case 0x1708F8u: goto label_1708f8;
            case 0x170900u: goto label_170900;
            case 0x170928u: goto label_170928;
            case 0x170940u: goto label_170940;
            case 0x170944u: goto label_170944;
            case 0x17094Cu: goto label_17094c;
            default: break;
        }
        return;
    }
    ctx->pc = 0x17097Cu;
    ctx->pc = GPR_U32(ctx, 31); return;
}
