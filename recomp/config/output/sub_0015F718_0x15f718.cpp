#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_0015F718
// Address: 0x15f718 - 0x15f8e0
void sub_0015F718_0x15f718(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_0015F718_0x15f718");
#endif

    switch (ctx->pc) {
        case 0x15f744u: goto label_15f744;
        case 0x15f780u: goto label_15f780;
        case 0x15f81cu: goto label_15f81c;
        case 0x15f830u: goto label_15f830;
        case 0x15f838u: goto label_15f838;
        case 0x15f84cu: goto label_15f84c;
        case 0x15f854u: goto label_15f854;
        case 0x15f894u: goto label_15f894;
        case 0x15f8a8u: goto label_15f8a8;
        case 0x15f8b0u: goto label_15f8b0;
        case 0x15f8c4u: goto label_15f8c4;
        case 0x15f8ccu: goto label_15f8cc;
        default: break;
    }

    ctx->pc = 0x15f718u;

    // 0x15f718: 0x27bdffe0  addiu       $sp, $sp, -0x20
    ctx->pc = 0x15f718u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967264));
    // 0x15f71c: 0xffb00010  sd          $s0, 0x10($sp)
    ctx->pc = 0x15f71cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 16));
    // 0x15f720: 0x80802d  daddu       $s0, $a0, $zero
    ctx->pc = 0x15f720u;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x15f724: 0xffbf0018  sd          $ra, 0x18($sp)
    ctx->pc = 0x15f724u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 24), GPR_U64(ctx, 31));
    // 0x15f728: 0xa0202d  daddu       $a0, $a1, $zero
    ctx->pc = 0x15f728u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
    // 0x15f72c: 0xc0282d  daddu       $a1, $a2, $zero
    ctx->pc = 0x15f72cu;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 6) + (uint64_t)GPR_U64(ctx, 0));
    // 0x15f730: 0x3a0382d  daddu       $a3, $sp, $zero
    ctx->pc = 0x15f730u;
    SET_GPR_U64(ctx, 7, (uint64_t)GPR_U64(ctx, 29) + (uint64_t)GPR_U64(ctx, 0));
    // 0x15f734: 0x8e060110  lw          $a2, 0x110($s0)
    ctx->pc = 0x15f734u;
    SET_GPR_S32(ctx, 6, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 272)));
    // 0x15f738: 0x27a80004  addiu       $t0, $sp, 0x4
    ctx->pc = 0x15f738u;
    SET_GPR_S32(ctx, 8, (int32_t)ADD32(GPR_U32(ctx, 29), 4));
    // 0x15f73c: 0xc04a786  jal         func_129E18
    ctx->pc = 0x15F73Cu;
    SET_GPR_U32(ctx, 31, 0x15F744u);
    ctx->pc = 0x15F740u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x15F73Cu;
            // 0x15f740: 0x27a90008  addiu       $t1, $sp, 0x8 (Delay Slot)
        SET_GPR_S32(ctx, 9, (int32_t)ADD32(GPR_U32(ctx, 29), 8));
        ctx->in_delay_slot = false;
    ctx->pc = 0x129E18u;
    if (runtime->hasFunction(0x129E18u)) {
        auto targetFn = runtime->lookupFunction(0x129E18u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x15F744u; }
        if (ctx->pc != 0x15F744u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00129E18_0x129e18(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x15F744u; }
        if (ctx->pc != 0x15F744u) { return; }
    }
    ctx->pc = 0x15F744u;
label_15f744:
    // 0x15f744: 0x3c040024  lui         $a0, 0x24
    ctx->pc = 0x15f744u;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)36 << 16));
    // 0x15f748: 0x1440000b  bnez        $v0, . + 4 + (0xB << 2)
    ctx->pc = 0x15F748u;
    {
        const bool branch_taken_0x15f748 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x15F74Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x15F748u;
            // 0x15f74c: 0x2484f280  addiu       $a0, $a0, -0xD80 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 4294963840));
        ctx->in_delay_slot = false;
        if (branch_taken_0x15f748) {
            ctx->pc = 0x15F778u;
            goto label_15f778;
        }
    }
    ctx->pc = 0x15F750u;
    // 0x15f750: 0x8fa30000  lw          $v1, 0x0($sp)
    ctx->pc = 0x15f750u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x15f754: 0x24020001  addiu       $v0, $zero, 0x1
    ctx->pc = 0x15f754u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x15f758: 0x8fa40004  lw          $a0, 0x4($sp)
    ctx->pc = 0x15f758u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 4)));
    // 0x15f75c: 0x8fa50008  lw          $a1, 0x8($sp)
    ctx->pc = 0x15f75cu;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x15f760: 0xae020118  sw          $v0, 0x118($s0)
    ctx->pc = 0x15f760u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 280), GPR_U32(ctx, 2));
    // 0x15f764: 0xae03011c  sw          $v1, 0x11C($s0)
    ctx->pc = 0x15f764u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 284), GPR_U32(ctx, 3));
    // 0x15f768: 0xae040120  sw          $a0, 0x120($s0)
    ctx->pc = 0x15f768u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 288), GPR_U32(ctx, 4));
    // 0x15f76c: 0x10000004  b           . + 4 + (0x4 << 2)
    ctx->pc = 0x15F76Cu;
    {
        const bool branch_taken_0x15f76c = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x15F770u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x15F76Cu;
            // 0x15f770: 0xae050124  sw          $a1, 0x124($s0) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 16), 292), GPR_U32(ctx, 5));
        ctx->in_delay_slot = false;
        if (branch_taken_0x15f76c) {
            ctx->pc = 0x15F780u;
            goto label_15f780;
        }
    }
    ctx->pc = 0x15F774u;
    // 0x15f774: 0x0  nop
    ctx->pc = 0x15f774u;
    // NOP
label_15f778:
    // 0x15f778: 0xc058dd4  jal         func_163750
    ctx->pc = 0x15F778u;
    SET_GPR_U32(ctx, 31, 0x15F780u);
    ctx->pc = 0x163750u;
    if (runtime->hasFunction(0x163750u)) {
        auto targetFn = runtime->lookupFunction(0x163750u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x15F780u; }
        if (ctx->pc != 0x15F780u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00163750_0x163750(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x15F780u; }
        if (ctx->pc != 0x15F780u) { return; }
    }
    ctx->pc = 0x15F780u;
label_15f780:
    // 0x15f780: 0xdfb00010  ld          $s0, 0x10($sp)
    ctx->pc = 0x15f780u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x15f784: 0xdfbf0018  ld          $ra, 0x18($sp)
    ctx->pc = 0x15f784u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 24)));
    // 0x15f788: 0x3e00008  jr          $ra
    ctx->pc = 0x15F788u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x15F78Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x15F788u;
            // 0x15f78c: 0x27bd0020  addiu       $sp, $sp, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x15F744u: goto label_15f744;
            case 0x15F778u: goto label_15f778;
            case 0x15F780u: goto label_15f780;
            case 0x15F81Cu: goto label_15f81c;
            case 0x15F830u: goto label_15f830;
            case 0x15F838u: goto label_15f838;
            case 0x15F84Cu: goto label_15f84c;
            case 0x15F854u: goto label_15f854;
            case 0x15F858u: goto label_15f858;
            case 0x15F894u: goto label_15f894;
            case 0x15F8A8u: goto label_15f8a8;
            case 0x15F8B0u: goto label_15f8b0;
            case 0x15F8C4u: goto label_15f8c4;
            case 0x15F8CCu: goto label_15f8cc;
            case 0x15F8D0u: goto label_15f8d0;
            default: break;
        }
        return;
    }
    ctx->pc = 0x15F790u;
    // 0x15f790: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x15f790u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x15f794: 0xffbf0000  sd          $ra, 0x0($sp)
    ctx->pc = 0x15f794u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 31));
    // 0x15f798: 0x8c840040  lw          $a0, 0x40($a0)
    ctx->pc = 0x15f798u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 64)));
    // 0x15f79c: 0xdfbf0000  ld          $ra, 0x0($sp)
    ctx->pc = 0x15f79cu;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x15f7a0: 0x8059898  j           func_166260
    ctx->pc = 0x15F7A0u;
    ctx->pc = 0x15F7A4u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x15F7A0u;
            // 0x15f7a4: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
    ctx->pc = 0x166260u;
    if (runtime->hasFunction(0x166260u)) {
        auto targetFn = runtime->lookupFunction(0x166260u);
        targetFn(rdram, ctx, runtime); return;
    } else {
        sub_00166260_0x166260(rdram, ctx, runtime); return;
    }
    ctx->pc = 0x15F7A8u;
    // 0x15f7a8: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x15f7a8u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x15f7ac: 0xffbf0000  sd          $ra, 0x0($sp)
    ctx->pc = 0x15f7acu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 31));
    // 0x15f7b0: 0x8c840040  lw          $a0, 0x40($a0)
    ctx->pc = 0x15f7b0u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 64)));
    // 0x15f7b4: 0xdfbf0000  ld          $ra, 0x0($sp)
    ctx->pc = 0x15f7b4u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x15f7b8: 0x80598b8  j           func_1662E0
    ctx->pc = 0x15F7B8u;
    ctx->pc = 0x15F7BCu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x15F7B8u;
            // 0x15f7bc: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1662E0u;
    if (runtime->hasFunction(0x1662E0u)) {
        auto targetFn = runtime->lookupFunction(0x1662E0u);
        targetFn(rdram, ctx, runtime); return;
    } else {
        sub_001662E0_0x1662e0(rdram, ctx, runtime); return;
    }
    ctx->pc = 0x15F7C0u;
    // 0x15f7c0: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x15f7c0u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x15f7c4: 0xffbf0000  sd          $ra, 0x0($sp)
    ctx->pc = 0x15f7c4u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 31));
    // 0x15f7c8: 0x8c840040  lw          $a0, 0x40($a0)
    ctx->pc = 0x15f7c8u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 64)));
    // 0x15f7cc: 0xdfbf0000  ld          $ra, 0x0($sp)
    ctx->pc = 0x15f7ccu;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x15f7d0: 0x8059856  j           func_166158
    ctx->pc = 0x15F7D0u;
    ctx->pc = 0x15F7D4u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x15F7D0u;
            // 0x15f7d4: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
    ctx->pc = 0x166158u;
    if (runtime->hasFunction(0x166158u)) {
        auto targetFn = runtime->lookupFunction(0x166158u);
        targetFn(rdram, ctx, runtime); return;
    } else {
        sub_00166158_0x166158(rdram, ctx, runtime); return;
    }
    ctx->pc = 0x15F7D8u;
    // 0x15f7d8: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x15f7d8u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x15f7dc: 0xffbf0000  sd          $ra, 0x0($sp)
    ctx->pc = 0x15f7dcu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 31));
    // 0x15f7e0: 0x8c840040  lw          $a0, 0x40($a0)
    ctx->pc = 0x15f7e0u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 64)));
    // 0x15f7e4: 0xdfbf0000  ld          $ra, 0x0($sp)
    ctx->pc = 0x15f7e4u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x15f7e8: 0x805987a  j           func_1661E8
    ctx->pc = 0x15F7E8u;
    ctx->pc = 0x15F7ECu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x15F7E8u;
            // 0x15f7ec: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1661E8u;
    if (runtime->hasFunction(0x1661E8u)) {
        auto targetFn = runtime->lookupFunction(0x1661E8u);
        targetFn(rdram, ctx, runtime); return;
    } else {
        sub_001661E8_0x1661e8(rdram, ctx, runtime); return;
    }
    ctx->pc = 0x15F7F0u;
    // 0x15f7f0: 0x27bdffe0  addiu       $sp, $sp, -0x20
    ctx->pc = 0x15f7f0u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967264));
    // 0x15f7f4: 0x3c030023  lui         $v1, 0x23
    ctx->pc = 0x15f7f4u;
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)35 << 16));
    // 0x15f7f8: 0xffb00000  sd          $s0, 0x0($sp)
    ctx->pc = 0x15f7f8u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x15f7fc: 0x2470ef48  addiu       $s0, $v1, -0x10B8
    ctx->pc = 0x15f7fcu;
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 3), 4294963016));
    // 0x15f800: 0x8e020000  lw          $v0, 0x0($s0)
    ctx->pc = 0x15f800u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 0)));
    // 0x15f804: 0xffb10008  sd          $s1, 0x8($sp)
    ctx->pc = 0x15f804u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 8), GPR_U64(ctx, 17));
    // 0x15f808: 0x24110001  addiu       $s1, $zero, 0x1
    ctx->pc = 0x15f808u;
    SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x15f80c: 0x10510012  beq         $v0, $s1, . + 4 + (0x12 << 2)
    ctx->pc = 0x15F80Cu;
    {
        const bool branch_taken_0x15f80c = (GPR_U64(ctx, 2) == GPR_U64(ctx, 17));
        ctx->pc = 0x15F810u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x15F80Cu;
            // 0x15f810: 0xffbf0010  sd          $ra, 0x10($sp) (Delay Slot)
        WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 31));
        ctx->in_delay_slot = false;
        if (branch_taken_0x15f80c) {
            ctx->pc = 0x15F858u;
            goto label_15f858;
        }
    }
    ctx->pc = 0x15F814u;
    // 0x15f814: 0xc057e38  jal         func_15F8E0
    ctx->pc = 0x15F814u;
    SET_GPR_U32(ctx, 31, 0x15F81Cu);
    ctx->pc = 0x15F8E0u;
    if (runtime->hasFunction(0x15F8E0u)) {
        auto targetFn = runtime->lookupFunction(0x15F8E0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x15F81Cu; }
        if (ctx->pc != 0x15F81Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0015F8E0_0x15f8e0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x15F81Cu; }
        if (ctx->pc != 0x15F81Cu) { return; }
    }
    ctx->pc = 0x15F81Cu;
label_15f81c:
    // 0x15f81c: 0x3c060027  lui         $a2, 0x27
    ctx->pc = 0x15f81cu;
    SET_GPR_S32(ctx, 6, (int32_t)((uint32_t)39 << 16));
    // 0x15f820: 0x24c68640  addiu       $a2, $a2, -0x79C0
    ctx->pc = 0x15f820u;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 6), 4294936128));
    // 0x15f824: 0x24054000  addiu       $a1, $zero, 0x4000
    ctx->pc = 0x15f824u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 16384));
    // 0x15f828: 0xc057e40  jal         func_15F900
    ctx->pc = 0x15F828u;
    SET_GPR_U32(ctx, 31, 0x15F830u);
    ctx->pc = 0x15F82Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x15F828u;
            // 0x15f82c: 0x202d  daddu       $a0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x15F900u;
    if (runtime->hasFunction(0x15F900u)) {
        auto targetFn = runtime->lookupFunction(0x15F900u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x15F830u; }
        if (ctx->pc != 0x15F830u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0015F900_0x15f900(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x15F830u; }
        if (ctx->pc != 0x15F830u) { return; }
    }
    ctx->pc = 0x15F830u;
label_15f830:
    // 0x15f830: 0xc057e74  jal         func_15F9D0
    ctx->pc = 0x15F830u;
    SET_GPR_U32(ctx, 31, 0x15F838u);
    ctx->pc = 0x15F834u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x15F830u;
            // 0x15f834: 0x24040008  addiu       $a0, $zero, 0x8 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 8));
        ctx->in_delay_slot = false;
    ctx->pc = 0x15F9D0u;
    if (runtime->hasFunction(0x15F9D0u)) {
        auto targetFn = runtime->lookupFunction(0x15F9D0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x15F838u; }
        if (ctx->pc != 0x15F838u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0015F9D0_0x15f9d0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x15F838u; }
        if (ctx->pc != 0x15F838u) { return; }
    }
    ctx->pc = 0x15F838u;
label_15f838:
    // 0x15f838: 0x3c040027  lui         $a0, 0x27
    ctx->pc = 0x15f838u;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)39 << 16));
    // 0x15f83c: 0x2484c640  addiu       $a0, $a0, -0x39C0
    ctx->pc = 0x15f83cu;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 4294952512));
    // 0x15f840: 0x24054000  addiu       $a1, $zero, 0x4000
    ctx->pc = 0x15f840u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 16384));
    // 0x15f844: 0xc057e5a  jal         func_15F968
    ctx->pc = 0x15F844u;
    SET_GPR_U32(ctx, 31, 0x15F84Cu);
    ctx->pc = 0x15F848u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x15F844u;
            // 0x15f848: 0x302d  daddu       $a2, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x15F968u;
    if (runtime->hasFunction(0x15F968u)) {
        auto targetFn = runtime->lookupFunction(0x15F968u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x15F84Cu; }
        if (ctx->pc != 0x15F84Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0015F968_0x15f968(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x15F84Cu; }
        if (ctx->pc != 0x15F84Cu) { return; }
    }
    ctx->pc = 0x15F84Cu;
label_15f84c:
    // 0x15f84c: 0xc057e74  jal         func_15F9D0
    ctx->pc = 0x15F84Cu;
    SET_GPR_U32(ctx, 31, 0x15F854u);
    ctx->pc = 0x15F850u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x15F84Cu;
            // 0x15f850: 0x24040009  addiu       $a0, $zero, 0x9 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 9));
        ctx->in_delay_slot = false;
    ctx->pc = 0x15F9D0u;
    if (runtime->hasFunction(0x15F9D0u)) {
        auto targetFn = runtime->lookupFunction(0x15F9D0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x15F854u; }
        if (ctx->pc != 0x15F854u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0015F9D0_0x15f9d0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x15F854u; }
        if (ctx->pc != 0x15F854u) { return; }
    }
    ctx->pc = 0x15F854u;
label_15f854:
    // 0x15f854: 0xae110000  sw          $s1, 0x0($s0)
    ctx->pc = 0x15f854u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 0), GPR_U32(ctx, 17));
label_15f858:
    // 0x15f858: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x15f858u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x15f85c: 0xdfb10008  ld          $s1, 0x8($sp)
    ctx->pc = 0x15f85cu;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x15f860: 0xdfbf0010  ld          $ra, 0x10($sp)
    ctx->pc = 0x15f860u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x15f864: 0x3e00008  jr          $ra
    ctx->pc = 0x15F864u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x15F868u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x15F864u;
            // 0x15f868: 0x27bd0020  addiu       $sp, $sp, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x15F744u: goto label_15f744;
            case 0x15F778u: goto label_15f778;
            case 0x15F780u: goto label_15f780;
            case 0x15F81Cu: goto label_15f81c;
            case 0x15F830u: goto label_15f830;
            case 0x15F838u: goto label_15f838;
            case 0x15F84Cu: goto label_15f84c;
            case 0x15F854u: goto label_15f854;
            case 0x15F858u: goto label_15f858;
            case 0x15F894u: goto label_15f894;
            case 0x15F8A8u: goto label_15f8a8;
            case 0x15F8B0u: goto label_15f8b0;
            case 0x15F8C4u: goto label_15f8c4;
            case 0x15F8CCu: goto label_15f8cc;
            case 0x15F8D0u: goto label_15f8d0;
            default: break;
        }
        return;
    }
    ctx->pc = 0x15F86Cu;
    // 0x15f86c: 0x0  nop
    ctx->pc = 0x15f86cu;
    // NOP
    // 0x15f870: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x15f870u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x15f874: 0x3c020023  lui         $v0, 0x23
    ctx->pc = 0x15f874u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)35 << 16));
    // 0x15f878: 0xffb00000  sd          $s0, 0x0($sp)
    ctx->pc = 0x15f878u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x15f87c: 0x2450ef48  addiu       $s0, $v0, -0x10B8
    ctx->pc = 0x15f87cu;
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 2), 4294963016));
    // 0x15f880: 0x8e030000  lw          $v1, 0x0($s0)
    ctx->pc = 0x15f880u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 0)));
    // 0x15f884: 0x10600012  beqz        $v1, . + 4 + (0x12 << 2)
    ctx->pc = 0x15F884u;
    {
        const bool branch_taken_0x15f884 = (GPR_U64(ctx, 3) == GPR_U64(ctx, 0));
        ctx->pc = 0x15F888u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x15F884u;
            // 0x15f888: 0xffbf0008  sd          $ra, 0x8($sp) (Delay Slot)
        WRITE64(ADD32(GPR_U32(ctx, 29), 8), GPR_U64(ctx, 31));
        ctx->in_delay_slot = false;
        if (branch_taken_0x15f884) {
            ctx->pc = 0x15F8D0u;
            goto label_15f8d0;
        }
    }
    ctx->pc = 0x15F88Cu;
    // 0x15f88c: 0xc057e38  jal         func_15F8E0
    ctx->pc = 0x15F88Cu;
    SET_GPR_U32(ctx, 31, 0x15F894u);
    ctx->pc = 0x15F8E0u;
    if (runtime->hasFunction(0x15F8E0u)) {
        auto targetFn = runtime->lookupFunction(0x15F8E0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x15F894u; }
        if (ctx->pc != 0x15F894u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0015F8E0_0x15f8e0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x15F894u; }
        if (ctx->pc != 0x15F894u) { return; }
    }
    ctx->pc = 0x15F894u;
label_15f894:
    // 0x15f894: 0x3c060027  lui         $a2, 0x27
    ctx->pc = 0x15f894u;
    SET_GPR_S32(ctx, 6, (int32_t)((uint32_t)39 << 16));
    // 0x15f898: 0x24c6c640  addiu       $a2, $a2, -0x39C0
    ctx->pc = 0x15f898u;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 6), 4294952512));
    // 0x15f89c: 0x24054000  addiu       $a1, $zero, 0x4000
    ctx->pc = 0x15f89cu;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 16384));
    // 0x15f8a0: 0xc057e40  jal         func_15F900
    ctx->pc = 0x15F8A0u;
    SET_GPR_U32(ctx, 31, 0x15F8A8u);
    ctx->pc = 0x15F8A4u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x15F8A0u;
            // 0x15f8a4: 0x202d  daddu       $a0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x15F900u;
    if (runtime->hasFunction(0x15F900u)) {
        auto targetFn = runtime->lookupFunction(0x15F900u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x15F8A8u; }
        if (ctx->pc != 0x15F8A8u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0015F900_0x15f900(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x15F8A8u; }
        if (ctx->pc != 0x15F8A8u) { return; }
    }
    ctx->pc = 0x15F8A8u;
label_15f8a8:
    // 0x15f8a8: 0xc057e74  jal         func_15F9D0
    ctx->pc = 0x15F8A8u;
    SET_GPR_U32(ctx, 31, 0x15F8B0u);
    ctx->pc = 0x15F8ACu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x15F8A8u;
            // 0x15f8ac: 0x24040008  addiu       $a0, $zero, 0x8 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 8));
        ctx->in_delay_slot = false;
    ctx->pc = 0x15F9D0u;
    if (runtime->hasFunction(0x15F9D0u)) {
        auto targetFn = runtime->lookupFunction(0x15F9D0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x15F8B0u; }
        if (ctx->pc != 0x15F8B0u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0015F9D0_0x15f9d0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x15F8B0u; }
        if (ctx->pc != 0x15F8B0u) { return; }
    }
    ctx->pc = 0x15F8B0u;
label_15f8b0:
    // 0x15f8b0: 0x3c040027  lui         $a0, 0x27
    ctx->pc = 0x15f8b0u;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)39 << 16));
    // 0x15f8b4: 0x24848640  addiu       $a0, $a0, -0x79C0
    ctx->pc = 0x15f8b4u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 4294936128));
    // 0x15f8b8: 0x24054000  addiu       $a1, $zero, 0x4000
    ctx->pc = 0x15f8b8u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 16384));
    // 0x15f8bc: 0xc057e5a  jal         func_15F968
    ctx->pc = 0x15F8BCu;
    SET_GPR_U32(ctx, 31, 0x15F8C4u);
    ctx->pc = 0x15F8C0u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x15F8BCu;
            // 0x15f8c0: 0x302d  daddu       $a2, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x15F968u;
    if (runtime->hasFunction(0x15F968u)) {
        auto targetFn = runtime->lookupFunction(0x15F968u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x15F8C4u; }
        if (ctx->pc != 0x15F8C4u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0015F968_0x15f968(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x15F8C4u; }
        if (ctx->pc != 0x15F8C4u) { return; }
    }
    ctx->pc = 0x15F8C4u;
label_15f8c4:
    // 0x15f8c4: 0xc057e74  jal         func_15F9D0
    ctx->pc = 0x15F8C4u;
    SET_GPR_U32(ctx, 31, 0x15F8CCu);
    ctx->pc = 0x15F8C8u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x15F8C4u;
            // 0x15f8c8: 0x24040009  addiu       $a0, $zero, 0x9 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 9));
        ctx->in_delay_slot = false;
    ctx->pc = 0x15F9D0u;
    if (runtime->hasFunction(0x15F9D0u)) {
        auto targetFn = runtime->lookupFunction(0x15F9D0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x15F8CCu; }
        if (ctx->pc != 0x15F8CCu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0015F9D0_0x15f9d0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x15F8CCu; }
        if (ctx->pc != 0x15F8CCu) { return; }
    }
    ctx->pc = 0x15F8CCu;
label_15f8cc:
    // 0x15f8cc: 0xae000000  sw          $zero, 0x0($s0)
    ctx->pc = 0x15f8ccu;
    WRITE32(ADD32(GPR_U32(ctx, 16), 0), GPR_U32(ctx, 0));
label_15f8d0:
    // 0x15f8d0: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x15f8d0u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x15f8d4: 0xdfbf0008  ld          $ra, 0x8($sp)
    ctx->pc = 0x15f8d4u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x15f8d8: 0x3e00008  jr          $ra
    ctx->pc = 0x15F8D8u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x15F8DCu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x15F8D8u;
            // 0x15f8dc: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x15F744u: goto label_15f744;
            case 0x15F778u: goto label_15f778;
            case 0x15F780u: goto label_15f780;
            case 0x15F81Cu: goto label_15f81c;
            case 0x15F830u: goto label_15f830;
            case 0x15F838u: goto label_15f838;
            case 0x15F84Cu: goto label_15f84c;
            case 0x15F854u: goto label_15f854;
            case 0x15F858u: goto label_15f858;
            case 0x15F894u: goto label_15f894;
            case 0x15F8A8u: goto label_15f8a8;
            case 0x15F8B0u: goto label_15f8b0;
            case 0x15F8C4u: goto label_15f8c4;
            case 0x15F8CCu: goto label_15f8cc;
            case 0x15F8D0u: goto label_15f8d0;
            default: break;
        }
        return;
    }
    ctx->pc = 0x15F8E0u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
