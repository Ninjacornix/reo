#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001886B8
// Address: 0x1886b8 - 0x188840
void sub_001886B8_0x1886b8(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001886B8_0x1886b8");
#endif

    switch (ctx->pc) {
        case 0x188710u: goto label_188710;
        case 0x188740u: goto label_188740;
        case 0x1887acu: goto label_1887ac;
        case 0x1887b8u: goto label_1887b8;
        case 0x1887c8u: goto label_1887c8;
        case 0x1887dcu: goto label_1887dc;
        case 0x188800u: goto label_188800;
        default: break;
    }

    ctx->pc = 0x1886b8u;

    // 0x1886b8: 0x27bdffa0  addiu       $sp, $sp, -0x60
    ctx->pc = 0x1886b8u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967200));
    // 0x1886bc: 0x3c020029  lui         $v0, 0x29
    ctx->pc = 0x1886bcu;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)41 << 16));
    // 0x1886c0: 0xffb40030  sd          $s4, 0x30($sp)
    ctx->pc = 0x1886c0u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 48), GPR_U64(ctx, 20));
    // 0x1886c4: 0x80a02d  daddu       $s4, $a0, $zero
    ctx->pc = 0x1886c4u;
    SET_GPR_U64(ctx, 20, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1886c8: 0xffbe0050  sd          $fp, 0x50($sp)
    ctx->pc = 0x1886c8u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 80), GPR_U64(ctx, 30));
    // 0x1886cc: 0x14f0c0  sll         $fp, $s4, 3
    ctx->pc = 0x1886ccu;
    SET_GPR_S32(ctx, 30, (int32_t)SLL32(GPR_U32(ctx, 20), 3));
    // 0x1886d0: 0xffb30028  sd          $s3, 0x28($sp)
    ctx->pc = 0x1886d0u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 40), GPR_U64(ctx, 19));
    // 0x1886d4: 0x2453b8c8  addiu       $s3, $v0, -0x4738
    ctx->pc = 0x1886d4u;
    SET_GPR_S32(ctx, 19, (int32_t)ADD32(GPR_U32(ctx, 2), 4294949064));
    // 0x1886d8: 0x3d41023  subu        $v0, $fp, $s4
    ctx->pc = 0x1886d8u;
    SET_GPR_S32(ctx, 2, (int32_t)SUB32(GPR_U32(ctx, 30), GPR_U32(ctx, 20)));
    // 0x1886dc: 0xffb10018  sd          $s1, 0x18($sp)
    ctx->pc = 0x1886dcu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 24), GPR_U64(ctx, 17));
    // 0x1886e0: 0xffb50038  sd          $s5, 0x38($sp)
    ctx->pc = 0x1886e0u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 56), GPR_U64(ctx, 21));
    // 0x1886e4: 0x26630004  addiu       $v1, $s3, 0x4
    ctx->pc = 0x1886e4u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 19), 4));
    // 0x1886e8: 0xffb70048  sd          $s7, 0x48($sp)
    ctx->pc = 0x1886e8u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 72), GPR_U64(ctx, 23));
    // 0x1886ec: 0xa0b82d  daddu       $s7, $a1, $zero
    ctx->pc = 0x1886ecu;
    SET_GPR_U64(ctx, 23, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1886f0: 0xffb00010  sd          $s0, 0x10($sp)
    ctx->pc = 0x1886f0u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 16));
    // 0x1886f4: 0x28880  sll         $s1, $v0, 2
    ctx->pc = 0x1886f4u;
    SET_GPR_S32(ctx, 17, (int32_t)SLL32(GPR_U32(ctx, 2), 2));
    // 0x1886f8: 0xffb20020  sd          $s2, 0x20($sp)
    ctx->pc = 0x1886f8u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 32), GPR_U64(ctx, 18));
    // 0x1886fc: 0x223a821  addu        $s5, $s1, $v1
    ctx->pc = 0x1886fcu;
    SET_GPR_S32(ctx, 21, (int32_t)ADD32(GPR_U32(ctx, 17), GPR_U32(ctx, 3)));
    // 0x188700: 0xffb60040  sd          $s6, 0x40($sp)
    ctx->pc = 0x188700u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 64), GPR_U64(ctx, 22));
    // 0x188704: 0xffbf0058  sd          $ra, 0x58($sp)
    ctx->pc = 0x188704u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 88), GPR_U64(ctx, 31));
    // 0x188708: 0xc0623b6  jal         func_188ED8
    ctx->pc = 0x188708u;
    SET_GPR_U32(ctx, 31, 0x188710u);
    ctx->pc = 0x18870Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x188708u;
            // 0x18870c: 0x8ea40000  lw          $a0, 0x0($s5) (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 21), 0)));
        ctx->in_delay_slot = false;
    ctx->pc = 0x188ED8u;
    if (runtime->hasFunction(0x188ED8u)) {
        auto targetFn = runtime->lookupFunction(0x188ED8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x188710u; }
        if (ctx->pc != 0x188710u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00188ED8_0x188ed8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x188710u; }
        if (ctx->pc != 0x188710u) { return; }
    }
    ctx->pc = 0x188710u;
label_188710:
    // 0x188710: 0x24030003  addiu       $v1, $zero, 0x3
    ctx->pc = 0x188710u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 3));
    // 0x188714: 0x14430004  bne         $v0, $v1, . + 4 + (0x4 << 2)
    ctx->pc = 0x188714u;
    {
        const bool branch_taken_0x188714 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 3));
        ctx->pc = 0x188718u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x188714u;
            // 0x188718: 0x3c160029  lui         $s6, 0x29 (Delay Slot)
        SET_GPR_S32(ctx, 22, (int32_t)((uint32_t)41 << 16));
        ctx->in_delay_slot = false;
        if (branch_taken_0x188714) {
            ctx->pc = 0x188728u;
            goto label_188728;
        }
    }
    ctx->pc = 0x18871Cu;
    // 0x18871c: 0x1000003a  b           . + 4 + (0x3A << 2)
    ctx->pc = 0x18871Cu;
    {
        const bool branch_taken_0x18871c = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x188720u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x18871Cu;
            // 0x188720: 0x102d  daddu       $v0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x18871c) {
            ctx->pc = 0x188808u;
            goto label_188808;
        }
    }
    ctx->pc = 0x188724u;
    // 0x188724: 0x0  nop
    ctx->pc = 0x188724u;
    // NOP
label_188728:
    // 0x188728: 0x282d  daddu       $a1, $zero, $zero
    ctx->pc = 0x188728u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x18872c: 0x26d0b900  addiu       $s0, $s6, -0x4700
    ctx->pc = 0x18872cu;
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 22), 4294949120));
    // 0x188730: 0x24062080  addiu       $a2, $zero, 0x2080
    ctx->pc = 0x188730u;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 0), 8320));
    // 0x188734: 0x200202d  daddu       $a0, $s0, $zero
    ctx->pc = 0x188734u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x188738: 0xc041f1a  jal         func_107C68
    ctx->pc = 0x188738u;
    SET_GPR_U32(ctx, 31, 0x188740u);
    ctx->pc = 0x18873Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x188738u;
            // 0x18873c: 0x24122080  addiu       $s2, $zero, 0x2080 (Delay Slot)
        SET_GPR_S32(ctx, 18, (int32_t)ADD32(GPR_U32(ctx, 0), 8320));
        ctx->in_delay_slot = false;
    ctx->pc = 0x107C68u;
    if (runtime->hasFunction(0x107C68u)) {
        auto targetFn = runtime->lookupFunction(0x107C68u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x188740u; }
        if (ctx->pc != 0x188740u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00107C68_0x107c68(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x188740u; }
        if (ctx->pc != 0x188740u) { return; }
    }
    ctx->pc = 0x188740u;
label_188740:
    // 0x188740: 0xae000000  sw          $zero, 0x0($s0)
    ctx->pc = 0x188740u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 0), GPR_U32(ctx, 0));
    // 0x188744: 0x2712021  addu        $a0, $s3, $s1
    ctx->pc = 0x188744u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 19), GPR_U32(ctx, 17)));
    // 0x188748: 0x3c110029  lui         $s1, 0x29
    ctx->pc = 0x188748u;
    SET_GPR_S32(ctx, 17, (int32_t)((uint32_t)41 << 16));
    // 0x18874c: 0x80102d  daddu       $v0, $a0, $zero
    ctx->pc = 0x18874cu;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x188750: 0x2631d980  addiu       $s1, $s1, -0x2680
    ctx->pc = 0x188750u;
    SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 17), 4294957440));
    // 0x188754: 0x40182d  daddu       $v1, $v0, $zero
    ctx->pc = 0x188754u;
    SET_GPR_U64(ctx, 3, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x188758: 0x8c470008  lw          $a3, 0x8($v0)
    ctx->pc = 0x188758u;
    SET_GPR_S32(ctx, 7, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 8)));
    // 0x18875c: 0x8c68000c  lw          $t0, 0xC($v1)
    ctx->pc = 0x18875cu;
    SET_GPR_S32(ctx, 8, (int32_t)READ32(ADD32(GPR_U32(ctx, 3), 12)));
    // 0x188760: 0x282d  daddu       $a1, $zero, $zero
    ctx->pc = 0x188760u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x188764: 0x8c830010  lw          $v1, 0x10($a0)
    ctx->pc = 0x188764u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 16)));
    // 0x188768: 0x220202d  daddu       $a0, $s1, $zero
    ctx->pc = 0x188768u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
    // 0x18876c: 0x24060100  addiu       $a2, $zero, 0x100
    ctx->pc = 0x18876cu;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 0), 256));
    // 0x188770: 0x24020001  addiu       $v0, $zero, 0x1
    ctx->pc = 0x188770u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x188774: 0xafb20000  sw          $s2, 0x0($sp)
    ctx->pc = 0x188774u;
    WRITE32(ADD32(GPR_U32(ctx, 29), 0), GPR_U32(ctx, 18));
    // 0x188778: 0x2a0902d  daddu       $s2, $s5, $zero
    ctx->pc = 0x188778u;
    SET_GPR_U64(ctx, 18, (uint64_t)GPR_U64(ctx, 21) + (uint64_t)GPR_U64(ctx, 0));
    // 0x18877c: 0xae170020  sw          $s7, 0x20($s0)
    ctx->pc = 0x18877cu;
    WRITE32(ADD32(GPR_U32(ctx, 16), 32), GPR_U32(ctx, 23));
    // 0x188780: 0x3c170018  lui         $s7, 0x18
    ctx->pc = 0x188780u;
    SET_GPR_S32(ctx, 23, (int32_t)((uint32_t)24 << 16));
    // 0x188784: 0xae070008  sw          $a3, 0x8($s0)
    ctx->pc = 0x188784u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 8), GPR_U32(ctx, 7));
    // 0x188788: 0x3c130023  lui         $s3, 0x23
    ctx->pc = 0x188788u;
    SET_GPR_S32(ctx, 19, (int32_t)((uint32_t)35 << 16));
    // 0x18878c: 0xae08000c  sw          $t0, 0xC($s0)
    ctx->pc = 0x18878cu;
    WRITE32(ADD32(GPR_U32(ctx, 16), 12), GPR_U32(ctx, 8));
    // 0x188790: 0x24150001  addiu       $s5, $zero, 0x1
    ctx->pc = 0x188790u;
    SET_GPR_S32(ctx, 21, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x188794: 0xae030010  sw          $v1, 0x10($s0)
    ctx->pc = 0x188794u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 16), GPR_U32(ctx, 3));
    // 0x188798: 0xae020004  sw          $v0, 0x4($s0)
    ctx->pc = 0x188798u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 4), GPR_U32(ctx, 2));
    // 0x18879c: 0xae000014  sw          $zero, 0x14($s0)
    ctx->pc = 0x18879cu;
    WRITE32(ADD32(GPR_U32(ctx, 16), 20), GPR_U32(ctx, 0));
    // 0x1887a0: 0xae000018  sw          $zero, 0x18($s0)
    ctx->pc = 0x1887a0u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 24), GPR_U32(ctx, 0));
    // 0x1887a4: 0xc041f1a  jal         func_107C68
    ctx->pc = 0x1887A4u;
    SET_GPR_U32(ctx, 31, 0x1887ACu);
    ctx->pc = 0x1887A8u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1887A4u;
            // 0x1887a8: 0xae00001c  sw          $zero, 0x1C($s0) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 16), 28), GPR_U32(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x107C68u;
    if (runtime->hasFunction(0x107C68u)) {
        auto targetFn = runtime->lookupFunction(0x107C68u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1887ACu; }
        if (ctx->pc != 0x1887ACu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00107C68_0x107c68(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1887ACu; }
        if (ctx->pc != 0x1887ACu) { return; }
    }
    ctx->pc = 0x1887ACu;
label_1887ac:
    // 0x1887ac: 0x220202d  daddu       $a0, $s1, $zero
    ctx->pc = 0x1887acu;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1887b0: 0xc0453c6  jal         func_114F18
    ctx->pc = 0x1887B0u;
    SET_GPR_U32(ctx, 31, 0x1887B8u);
    ctx->pc = 0x1887B4u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1887B0u;
            // 0x1887b4: 0x248500ff  addiu       $a1, $a0, 0xFF (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 4), 255));
        ctx->in_delay_slot = false;
    ctx->pc = 0x114F18u;
    if (runtime->hasFunction(0x114F18u)) {
        auto targetFn = runtime->lookupFunction(0x114F18u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1887B8u; }
        if (ctx->pc != 0x1887B8u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00114F18_0x114f18(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1887B8u; }
        if (ctx->pc != 0x1887B8u) { return; }
    }
    ctx->pc = 0x1887B8u;
label_1887b8:
    // 0x1887b8: 0x24020009  addiu       $v0, $zero, 0x9
    ctx->pc = 0x1887b8u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 9));
    // 0x1887bc: 0xae62fd24  sw          $v0, -0x2DC($s3)
    ctx->pc = 0x1887bcu;
    WRITE32(ADD32(GPR_U32(ctx, 19), 4294966564), GPR_U32(ctx, 2));
    // 0x1887c0: 0x8e440000  lw          $a0, 0x0($s2)
    ctx->pc = 0x1887c0u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 18), 0)));
    // 0x1887c4: 0x0  nop
    ctx->pc = 0x1887c4u;
    // NOP
label_1887c8:
    // 0x1887c8: 0x3a0302d  daddu       $a2, $sp, $zero
    ctx->pc = 0x1887c8u;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 29) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1887cc: 0x8e65fd24  lw          $a1, -0x2DC($s3)
    ctx->pc = 0x1887ccu;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 19), 4294966564)));
    // 0x1887d0: 0x26c7b900  addiu       $a3, $s6, -0x4700
    ctx->pc = 0x1887d0u;
    SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 22), 4294949120));
    // 0x1887d4: 0xc062560  jal         func_189580
    ctx->pc = 0x1887D4u;
    SET_GPR_U32(ctx, 31, 0x1887DCu);
    ctx->pc = 0x1887D8u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1887D4u;
            // 0x1887d8: 0x26e87808  addiu       $t0, $s7, 0x7808 (Delay Slot)
        SET_GPR_S32(ctx, 8, (int32_t)ADD32(GPR_U32(ctx, 23), 30728));
        ctx->in_delay_slot = false;
    ctx->pc = 0x189580u;
    if (runtime->hasFunction(0x189580u)) {
        auto targetFn = runtime->lookupFunction(0x189580u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1887DCu; }
        if (ctx->pc != 0x1887DCu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00189580_0x189580(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1887DCu; }
        if (ctx->pc != 0x1887DCu) { return; }
    }
    ctx->pc = 0x1887DCu;
label_1887dc:
    // 0x1887dc: 0x5455fffa  bnel        $v0, $s5, . + 4 + (-0x6 << 2)
    ctx->pc = 0x1887DCu;
    {
        const bool branch_taken_0x1887dc = (GPR_U64(ctx, 2) != GPR_U64(ctx, 21));
        if (branch_taken_0x1887dc) {
            ctx->pc = 0x1887E0u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x1887DCu;
            // 0x1887e0: 0x8e440000  lw          $a0, 0x0($s2) (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 18), 0)));
        ctx->in_delay_slot = false;
            ctx->pc = 0x1887C8u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_1887c8;
        }
    }
    ctx->pc = 0x1887E4u;
    // 0x1887e4: 0x3c040029  lui         $a0, 0x29
    ctx->pc = 0x1887e4u;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)41 << 16));
    // 0x1887e8: 0x3d41023  subu        $v0, $fp, $s4
    ctx->pc = 0x1887e8u;
    SET_GPR_S32(ctx, 2, (int32_t)SUB32(GPR_U32(ctx, 30), GPR_U32(ctx, 20)));
    // 0x1887ec: 0x2483b8c8  addiu       $v1, $a0, -0x4738
    ctx->pc = 0x1887ecu;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 4), 4294949064));
    // 0x1887f0: 0x21080  sll         $v0, $v0, 2
    ctx->pc = 0x1887f0u;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 2), 2));
    // 0x1887f4: 0x621821  addu        $v1, $v1, $v0
    ctx->pc = 0x1887f4u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 2)));
    // 0x1887f8: 0xc061db2  jal         func_1876C8
    ctx->pc = 0x1887F8u;
    SET_GPR_U32(ctx, 31, 0x188800u);
    ctx->pc = 0x1887FCu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1887F8u;
            // 0x1887fc: 0x8c640004  lw          $a0, 0x4($v1) (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 3), 4)));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1876C8u;
    if (runtime->hasFunction(0x1876C8u)) {
        auto targetFn = runtime->lookupFunction(0x1876C8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x188800u; }
        if (ctx->pc != 0x188800u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001876C8_0x1876c8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x188800u; }
        if (ctx->pc != 0x188800u) { return; }
    }
    ctx->pc = 0x188800u;
label_188800:
    // 0x188800: 0x8c420008  lw          $v0, 0x8($v0)
    ctx->pc = 0x188800u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 8)));
    // 0x188804: 0x2102b  sltu        $v0, $zero, $v0
    ctx->pc = 0x188804u;
    SET_GPR_U64(ctx, 2, ((uint64_t)GPR_U64(ctx, 0) < (uint64_t)GPR_U64(ctx, 2)) ? 1 : 0);
label_188808:
    // 0x188808: 0xdfb00010  ld          $s0, 0x10($sp)
    ctx->pc = 0x188808u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x18880c: 0xdfb10018  ld          $s1, 0x18($sp)
    ctx->pc = 0x18880cu;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 24)));
    // 0x188810: 0xdfb20020  ld          $s2, 0x20($sp)
    ctx->pc = 0x188810u;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x188814: 0xdfb30028  ld          $s3, 0x28($sp)
    ctx->pc = 0x188814u;
    SET_GPR_U64(ctx, 19, READ64(ADD32(GPR_U32(ctx, 29), 40)));
    // 0x188818: 0xdfb40030  ld          $s4, 0x30($sp)
    ctx->pc = 0x188818u;
    SET_GPR_U64(ctx, 20, READ64(ADD32(GPR_U32(ctx, 29), 48)));
    // 0x18881c: 0xdfb50038  ld          $s5, 0x38($sp)
    ctx->pc = 0x18881cu;
    SET_GPR_U64(ctx, 21, READ64(ADD32(GPR_U32(ctx, 29), 56)));
    // 0x188820: 0xdfb60040  ld          $s6, 0x40($sp)
    ctx->pc = 0x188820u;
    SET_GPR_U64(ctx, 22, READ64(ADD32(GPR_U32(ctx, 29), 64)));
    // 0x188824: 0xdfb70048  ld          $s7, 0x48($sp)
    ctx->pc = 0x188824u;
    SET_GPR_U64(ctx, 23, READ64(ADD32(GPR_U32(ctx, 29), 72)));
    // 0x188828: 0xdfbe0050  ld          $fp, 0x50($sp)
    ctx->pc = 0x188828u;
    SET_GPR_U64(ctx, 30, READ64(ADD32(GPR_U32(ctx, 29), 80)));
    // 0x18882c: 0xdfbf0058  ld          $ra, 0x58($sp)
    ctx->pc = 0x18882cu;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 88)));
    // 0x188830: 0x3e00008  jr          $ra
    ctx->pc = 0x188830u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x188834u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x188830u;
            // 0x188834: 0x27bd0060  addiu       $sp, $sp, 0x60 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 96));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x188710u: goto label_188710;
            case 0x188728u: goto label_188728;
            case 0x188740u: goto label_188740;
            case 0x1887ACu: goto label_1887ac;
            case 0x1887B8u: goto label_1887b8;
            case 0x1887C8u: goto label_1887c8;
            case 0x1887DCu: goto label_1887dc;
            case 0x188800u: goto label_188800;
            case 0x188808u: goto label_188808;
            default: break;
        }
        return;
    }
    ctx->pc = 0x188838u;
    // 0x188838: 0x3e00008  jr          $ra
    ctx->pc = 0x188838u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x18883Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x188838u;
            // 0x18883c: 0x24020001  addiu       $v0, $zero, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x188710u: goto label_188710;
            case 0x188728u: goto label_188728;
            case 0x188740u: goto label_188740;
            case 0x1887ACu: goto label_1887ac;
            case 0x1887B8u: goto label_1887b8;
            case 0x1887C8u: goto label_1887c8;
            case 0x1887DCu: goto label_1887dc;
            case 0x188800u: goto label_188800;
            case 0x188808u: goto label_188808;
            default: break;
        }
        return;
    }
    ctx->pc = 0x188840u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
