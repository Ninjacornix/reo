#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001326F0
// Address: 0x1326f0 - 0x1327b8
void sub_001326F0_0x1326f0(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001326F0_0x1326f0");
#endif

    switch (ctx->pc) {
        case 0x13270cu: goto label_13270c;
        case 0x132768u: goto label_132768;
        case 0x132770u: goto label_132770;
        case 0x1327a0u: goto label_1327a0;
        default: break;
    }

    ctx->pc = 0x1326f0u;

    // 0x1326f0: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x1326f0u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x1326f4: 0x51840  sll         $v1, $a1, 1
    ctx->pc = 0x1326f4u;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 5), 1));
    // 0x1326f8: 0x14800007  bnez        $a0, . + 4 + (0x7 << 2)
    ctx->pc = 0x1326F8u;
    {
        const bool branch_taken_0x1326f8 = (GPR_U64(ctx, 4) != GPR_U64(ctx, 0));
        ctx->pc = 0x1326FCu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1326F8u;
            // 0x1326fc: 0xffbf0000  sd          $ra, 0x0($sp) (Delay Slot)
        WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 31));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1326f8) {
            ctx->pc = 0x132718u;
            goto label_132718;
        }
    }
    ctx->pc = 0x132700u;
    // 0x132700: 0x3c040024  lui         $a0, 0x24
    ctx->pc = 0x132700u;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)36 << 16));
    // 0x132704: 0xc04a034  jal         func_1280D0
    ctx->pc = 0x132704u;
    SET_GPR_U32(ctx, 31, 0x13270Cu);
    ctx->pc = 0x132708u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x132704u;
            // 0x132708: 0x2484b0e8  addiu       $a0, $a0, -0x4F18 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 4294947048));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1280D0u;
    if (runtime->hasFunction(0x1280D0u)) {
        auto targetFn = runtime->lookupFunction(0x1280D0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x13270Cu; }
        if (ctx->pc != 0x13270Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001280D0_0x1280d0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x13270Cu; }
        if (ctx->pc != 0x13270Cu) { return; }
    }
    ctx->pc = 0x13270Cu;
label_13270c:
    // 0x13270c: 0x10000004  b           . + 4 + (0x4 << 2)
    ctx->pc = 0x13270Cu;
    {
        const bool branch_taken_0x13270c = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x132710u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x13270Cu;
            // 0x132710: 0x102d  daddu       $v0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x13270c) {
            ctx->pc = 0x132720u;
            goto label_132720;
        }
    }
    ctx->pc = 0x132714u;
    // 0x132714: 0x0  nop
    ctx->pc = 0x132714u;
    // NOP
label_132718:
    // 0x132718: 0x641821  addu        $v1, $v1, $a0
    ctx->pc = 0x132718u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 4)));
    // 0x13271c: 0x84620042  lh          $v0, 0x42($v1)
    ctx->pc = 0x13271cu;
    SET_GPR_S32(ctx, 2, (int16_t)READ16(ADD32(GPR_U32(ctx, 3), 66)));
label_132720:
    // 0x132720: 0xdfbf0000  ld          $ra, 0x0($sp)
    ctx->pc = 0x132720u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x132724: 0x3e00008  jr          $ra
    ctx->pc = 0x132724u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x132728u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x132724u;
            // 0x132728: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x13270Cu: goto label_13270c;
            case 0x132718u: goto label_132718;
            case 0x132720u: goto label_132720;
            case 0x132760u: goto label_132760;
            case 0x132768u: goto label_132768;
            case 0x132770u: goto label_132770;
            case 0x1327A0u: goto label_1327a0;
            case 0x1327A8u: goto label_1327a8;
            case 0x1327ACu: goto label_1327ac;
            default: break;
        }
        return;
    }
    ctx->pc = 0x13272Cu;
    // 0x13272c: 0x0  nop
    ctx->pc = 0x13272cu;
    // NOP
    // 0x132730: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x132730u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x132734: 0xffb00000  sd          $s0, 0x0($sp)
    ctx->pc = 0x132734u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x132738: 0x80802d  daddu       $s0, $a0, $zero
    ctx->pc = 0x132738u;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x13273c: 0x16000008  bnez        $s0, . + 4 + (0x8 << 2)
    ctx->pc = 0x13273Cu;
    {
        const bool branch_taken_0x13273c = (GPR_U64(ctx, 16) != GPR_U64(ctx, 0));
        ctx->pc = 0x132740u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x13273Cu;
            // 0x132740: 0xffbf0008  sd          $ra, 0x8($sp) (Delay Slot)
        WRITE64(ADD32(GPR_U32(ctx, 29), 8), GPR_U64(ctx, 31));
        ctx->in_delay_slot = false;
        if (branch_taken_0x13273c) {
            ctx->pc = 0x132760u;
            goto label_132760;
        }
    }
    ctx->pc = 0x132744u;
    // 0x132744: 0x3c040024  lui         $a0, 0x24
    ctx->pc = 0x132744u;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)36 << 16));
    // 0x132748: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x132748u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x13274c: 0xdfbf0008  ld          $ra, 0x8($sp)
    ctx->pc = 0x13274cu;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x132750: 0x2484b118  addiu       $a0, $a0, -0x4EE8
    ctx->pc = 0x132750u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 4294947096));
    // 0x132754: 0x804a034  j           func_1280D0
    ctx->pc = 0x132754u;
    ctx->pc = 0x132758u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x132754u;
            // 0x132758: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1280D0u;
    if (runtime->hasFunction(0x1280D0u)) {
        auto targetFn = runtime->lookupFunction(0x1280D0u);
        targetFn(rdram, ctx, runtime); return;
    } else {
        sub_001280D0_0x1280d0(rdram, ctx, runtime); return;
    }
    ctx->pc = 0x13275Cu;
    // 0x13275c: 0x0  nop
    ctx->pc = 0x13275cu;
    // NOP
label_132760:
    // 0x132760: 0xc04b20a  jal         func_12C828
    ctx->pc = 0x132760u;
    SET_GPR_U32(ctx, 31, 0x132768u);
    ctx->pc = 0x132764u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x132760u;
            // 0x132764: 0x8e04000c  lw          $a0, 0xC($s0) (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 12)));
        ctx->in_delay_slot = false;
    ctx->pc = 0x12C828u;
    if (runtime->hasFunction(0x12C828u)) {
        auto targetFn = runtime->lookupFunction(0x12C828u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x132768u; }
        if (ctx->pc != 0x132768u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0012C828_0x12c828(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x132768u; }
        if (ctx->pc != 0x132768u) { return; }
    }
    ctx->pc = 0x132768u;
label_132768:
    // 0x132768: 0xc04b224  jal         func_12C890
    ctx->pc = 0x132768u;
    SET_GPR_U32(ctx, 31, 0x132770u);
    ctx->pc = 0x13276Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x132768u;
            // 0x13276c: 0x8e04000c  lw          $a0, 0xC($s0) (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 12)));
        ctx->in_delay_slot = false;
    ctx->pc = 0x12C890u;
    if (runtime->hasFunction(0x12C890u)) {
        auto targetFn = runtime->lookupFunction(0x12C890u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x132770u; }
        if (ctx->pc != 0x132770u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0012C890_0x12c890(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x132770u; }
        if (ctx->pc != 0x132770u) { return; }
    }
    ctx->pc = 0x132770u;
label_132770:
    // 0x132770: 0xa6020046  sh          $v0, 0x46($s0)
    ctx->pc = 0x132770u;
    WRITE16(ADD32(GPR_U32(ctx, 16), 70), (uint16_t)GPR_U32(ctx, 2));
    // 0x132774: 0xdfbf0008  ld          $ra, 0x8($sp)
    ctx->pc = 0x132774u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x132778: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x132778u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x13277c: 0x3e00008  jr          $ra
    ctx->pc = 0x13277Cu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x132780u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x13277Cu;
            // 0x132780: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x13270Cu: goto label_13270c;
            case 0x132718u: goto label_132718;
            case 0x132720u: goto label_132720;
            case 0x132760u: goto label_132760;
            case 0x132768u: goto label_132768;
            case 0x132770u: goto label_132770;
            case 0x1327A0u: goto label_1327a0;
            case 0x1327A8u: goto label_1327a8;
            case 0x1327ACu: goto label_1327ac;
            default: break;
        }
        return;
    }
    ctx->pc = 0x132784u;
    // 0x132784: 0x0  nop
    ctx->pc = 0x132784u;
    // NOP
    // 0x132788: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x132788u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x13278c: 0x14800006  bnez        $a0, . + 4 + (0x6 << 2)
    ctx->pc = 0x13278Cu;
    {
        const bool branch_taken_0x13278c = (GPR_U64(ctx, 4) != GPR_U64(ctx, 0));
        ctx->pc = 0x132790u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x13278Cu;
            // 0x132790: 0xffbf0000  sd          $ra, 0x0($sp) (Delay Slot)
        WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 31));
        ctx->in_delay_slot = false;
        if (branch_taken_0x13278c) {
            ctx->pc = 0x1327A8u;
            goto label_1327a8;
        }
    }
    ctx->pc = 0x132794u;
    // 0x132794: 0x3c040024  lui         $a0, 0x24
    ctx->pc = 0x132794u;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)36 << 16));
    // 0x132798: 0xc04a034  jal         func_1280D0
    ctx->pc = 0x132798u;
    SET_GPR_U32(ctx, 31, 0x1327A0u);
    ctx->pc = 0x13279Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x132798u;
            // 0x13279c: 0x2484b148  addiu       $a0, $a0, -0x4EB8 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 4294947144));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1280D0u;
    if (runtime->hasFunction(0x1280D0u)) {
        auto targetFn = runtime->lookupFunction(0x1280D0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1327A0u; }
        if (ctx->pc != 0x1327A0u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001280D0_0x1280d0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1327A0u; }
        if (ctx->pc != 0x1327A0u) { return; }
    }
    ctx->pc = 0x1327A0u;
label_1327a0:
    // 0x1327a0: 0x10000002  b           . + 4 + (0x2 << 2)
    ctx->pc = 0x1327A0u;
    {
        const bool branch_taken_0x1327a0 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1327A4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1327A0u;
            // 0x1327a4: 0x102d  daddu       $v0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1327a0) {
            ctx->pc = 0x1327ACu;
            goto label_1327ac;
        }
    }
    ctx->pc = 0x1327A8u;
label_1327a8:
    // 0x1327a8: 0x84820046  lh          $v0, 0x46($a0)
    ctx->pc = 0x1327a8u;
    SET_GPR_S32(ctx, 2, (int16_t)READ16(ADD32(GPR_U32(ctx, 4), 70)));
label_1327ac:
    // 0x1327ac: 0xdfbf0000  ld          $ra, 0x0($sp)
    ctx->pc = 0x1327acu;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1327b0: 0x3e00008  jr          $ra
    ctx->pc = 0x1327B0u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1327B4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1327B0u;
            // 0x1327b4: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x13270Cu: goto label_13270c;
            case 0x132718u: goto label_132718;
            case 0x132720u: goto label_132720;
            case 0x132760u: goto label_132760;
            case 0x132768u: goto label_132768;
            case 0x132770u: goto label_132770;
            case 0x1327A0u: goto label_1327a0;
            case 0x1327A8u: goto label_1327a8;
            case 0x1327ACu: goto label_1327ac;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1327B8u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
