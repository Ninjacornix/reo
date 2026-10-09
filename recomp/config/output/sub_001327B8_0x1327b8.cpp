#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001327B8
// Address: 0x1327b8 - 0x1328a8
void sub_001327B8_0x1327b8(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001327B8_0x1327b8");
#endif

    switch (ctx->pc) {
        case 0x132800u: goto label_132800;
        case 0x132838u: goto label_132838;
        case 0x132860u: goto label_132860;
        case 0x132880u: goto label_132880;
        default: break;
    }

    ctx->pc = 0x1327b8u;

    // 0x1327b8: 0x27bdffe0  addiu       $sp, $sp, -0x20
    ctx->pc = 0x1327b8u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967264));
    // 0x1327bc: 0xffb10008  sd          $s1, 0x8($sp)
    ctx->pc = 0x1327bcu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 8), GPR_U64(ctx, 17));
    // 0x1327c0: 0x80882d  daddu       $s1, $a0, $zero
    ctx->pc = 0x1327c0u;
    SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1327c4: 0xffb00000  sd          $s0, 0x0($sp)
    ctx->pc = 0x1327c4u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x1327c8: 0x16200009  bnez        $s1, . + 4 + (0x9 << 2)
    ctx->pc = 0x1327C8u;
    {
        const bool branch_taken_0x1327c8 = (GPR_U64(ctx, 17) != GPR_U64(ctx, 0));
        ctx->pc = 0x1327CCu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1327C8u;
            // 0x1327cc: 0xffbf0010  sd          $ra, 0x10($sp) (Delay Slot)
        WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 31));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1327c8) {
            ctx->pc = 0x1327F0u;
            goto label_1327f0;
        }
    }
    ctx->pc = 0x1327D0u;
    // 0x1327d0: 0x3c040024  lui         $a0, 0x24
    ctx->pc = 0x1327d0u;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)36 << 16));
    // 0x1327d4: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x1327d4u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1327d8: 0xdfb10008  ld          $s1, 0x8($sp)
    ctx->pc = 0x1327d8u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x1327dc: 0x2484b178  addiu       $a0, $a0, -0x4E88
    ctx->pc = 0x1327dcu;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 4294947192));
    // 0x1327e0: 0xdfbf0010  ld          $ra, 0x10($sp)
    ctx->pc = 0x1327e0u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x1327e4: 0x804a034  j           func_1280D0
    ctx->pc = 0x1327E4u;
    ctx->pc = 0x1327E8u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1327E4u;
            // 0x1327e8: 0x27bd0020  addiu       $sp, $sp, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1280D0u;
    if (runtime->hasFunction(0x1280D0u)) {
        auto targetFn = runtime->lookupFunction(0x1280D0u);
        targetFn(rdram, ctx, runtime); return;
    } else {
        sub_001280D0_0x1280d0(rdram, ctx, runtime); return;
    }
    ctx->pc = 0x1327ECu;
    // 0x1327ec: 0x0  nop
    ctx->pc = 0x1327ecu;
    // NOP
label_1327f0:
    // 0x1327f0: 0xa6250040  sh          $a1, 0x40($s1)
    ctx->pc = 0x1327f0u;
    WRITE16(ADD32(GPR_U32(ctx, 17), 64), (uint16_t)GPR_U32(ctx, 5));
    // 0x1327f4: 0x8e240004  lw          $a0, 0x4($s1)
    ctx->pc = 0x1327f4u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 4)));
    // 0x1327f8: 0xc04b63e  jal         func_12D8F8
    ctx->pc = 0x1327F8u;
    SET_GPR_U32(ctx, 31, 0x132800u);
    ctx->pc = 0x1327FCu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1327F8u;
            // 0x1327fc: 0x8e30000c  lw          $s0, 0xC($s1) (Delay Slot)
        SET_GPR_S32(ctx, 16, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 12)));
        ctx->in_delay_slot = false;
    ctx->pc = 0x12D8F8u;
    if (runtime->hasFunction(0x12D8F8u)) {
        auto targetFn = runtime->lookupFunction(0x12D8F8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x132800u; }
        if (ctx->pc != 0x132800u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0012D8F8_0x12d8f8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x132800u; }
        if (ctx->pc != 0x132800u) { return; }
    }
    ctx->pc = 0x132800u;
label_132800:
    // 0x132800: 0x86250040  lh          $a1, 0x40($s1)
    ctx->pc = 0x132800u;
    SET_GPR_S32(ctx, 5, (int16_t)READ16(ADD32(GPR_U32(ctx, 17), 64)));
    // 0x132804: 0x200202d  daddu       $a0, $s0, $zero
    ctx->pc = 0x132804u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x132808: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x132808u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x13280c: 0xdfb10008  ld          $s1, 0x8($sp)
    ctx->pc = 0x13280cu;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x132810: 0xa22821  addu        $a1, $a1, $v0
    ctx->pc = 0x132810u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), GPR_U32(ctx, 2)));
    // 0x132814: 0xdfbf0010  ld          $ra, 0x10($sp)
    ctx->pc = 0x132814u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x132818: 0x804b1fe  j           func_12C7F8
    ctx->pc = 0x132818u;
    ctx->pc = 0x13281Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x132818u;
            // 0x13281c: 0x27bd0020  addiu       $sp, $sp, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
        ctx->in_delay_slot = false;
    ctx->pc = 0x12C7F8u;
    if (runtime->hasFunction(0x12C7F8u)) {
        auto targetFn = runtime->lookupFunction(0x12C7F8u);
        targetFn(rdram, ctx, runtime); return;
    } else {
        sub_0012C7F8_0x12c7f8(rdram, ctx, runtime); return;
    }
    ctx->pc = 0x132820u;
    // 0x132820: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x132820u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x132824: 0x14800006  bnez        $a0, . + 4 + (0x6 << 2)
    ctx->pc = 0x132824u;
    {
        const bool branch_taken_0x132824 = (GPR_U64(ctx, 4) != GPR_U64(ctx, 0));
        ctx->pc = 0x132828u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x132824u;
            // 0x132828: 0xffbf0000  sd          $ra, 0x0($sp) (Delay Slot)
        WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 31));
        ctx->in_delay_slot = false;
        if (branch_taken_0x132824) {
            ctx->pc = 0x132840u;
            goto label_132840;
        }
    }
    ctx->pc = 0x13282Cu;
    // 0x13282c: 0x3c040024  lui         $a0, 0x24
    ctx->pc = 0x13282cu;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)36 << 16));
    // 0x132830: 0xc04a034  jal         func_1280D0
    ctx->pc = 0x132830u;
    SET_GPR_U32(ctx, 31, 0x132838u);
    ctx->pc = 0x132834u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x132830u;
            // 0x132834: 0x2484b1a8  addiu       $a0, $a0, -0x4E58 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 4294947240));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1280D0u;
    if (runtime->hasFunction(0x1280D0u)) {
        auto targetFn = runtime->lookupFunction(0x1280D0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x132838u; }
        if (ctx->pc != 0x132838u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001280D0_0x1280d0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x132838u; }
        if (ctx->pc != 0x132838u) { return; }
    }
    ctx->pc = 0x132838u;
label_132838:
    // 0x132838: 0x10000002  b           . + 4 + (0x2 << 2)
    ctx->pc = 0x132838u;
    {
        const bool branch_taken_0x132838 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x13283Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x132838u;
            // 0x13283c: 0x102d  daddu       $v0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x132838) {
            ctx->pc = 0x132844u;
            goto label_132844;
        }
    }
    ctx->pc = 0x132840u;
label_132840:
    // 0x132840: 0x84820040  lh          $v0, 0x40($a0)
    ctx->pc = 0x132840u;
    SET_GPR_S32(ctx, 2, (int16_t)READ16(ADD32(GPR_U32(ctx, 4), 64)));
label_132844:
    // 0x132844: 0xdfbf0000  ld          $ra, 0x0($sp)
    ctx->pc = 0x132844u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x132848: 0x3e00008  jr          $ra
    ctx->pc = 0x132848u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x13284Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x132848u;
            // 0x13284c: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1327F0u: goto label_1327f0;
            case 0x132800u: goto label_132800;
            case 0x132838u: goto label_132838;
            case 0x132840u: goto label_132840;
            case 0x132844u: goto label_132844;
            case 0x132860u: goto label_132860;
            case 0x132880u: goto label_132880;
            default: break;
        }
        return;
    }
    ctx->pc = 0x132850u;
    // 0x132850: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x132850u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x132854: 0xffbf0000  sd          $ra, 0x0($sp)
    ctx->pc = 0x132854u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 31));
    // 0x132858: 0xc04b63e  jal         func_12D8F8
    ctx->pc = 0x132858u;
    SET_GPR_U32(ctx, 31, 0x132860u);
    ctx->pc = 0x13285Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x132858u;
            // 0x13285c: 0x8c840004  lw          $a0, 0x4($a0) (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 4)));
        ctx->in_delay_slot = false;
    ctx->pc = 0x12D8F8u;
    if (runtime->hasFunction(0x12D8F8u)) {
        auto targetFn = runtime->lookupFunction(0x12D8F8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x132860u; }
        if (ctx->pc != 0x132860u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0012D8F8_0x12d8f8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x132860u; }
        if (ctx->pc != 0x132860u) { return; }
    }
    ctx->pc = 0x132860u;
label_132860:
    // 0x132860: 0xdfbf0000  ld          $ra, 0x0($sp)
    ctx->pc = 0x132860u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x132864: 0x3e00008  jr          $ra
    ctx->pc = 0x132864u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x132868u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x132864u;
            // 0x132868: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1327F0u: goto label_1327f0;
            case 0x132800u: goto label_132800;
            case 0x132838u: goto label_132838;
            case 0x132840u: goto label_132840;
            case 0x132844u: goto label_132844;
            case 0x132860u: goto label_132860;
            case 0x132880u: goto label_132880;
            default: break;
        }
        return;
    }
    ctx->pc = 0x13286Cu;
    // 0x13286c: 0x0  nop
    ctx->pc = 0x13286cu;
    // NOP
    // 0x132870: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x132870u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x132874: 0xffbf0000  sd          $ra, 0x0($sp)
    ctx->pc = 0x132874u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 31));
    // 0x132878: 0xc04b654  jal         func_12D950
    ctx->pc = 0x132878u;
    SET_GPR_U32(ctx, 31, 0x132880u);
    ctx->pc = 0x13287Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x132878u;
            // 0x13287c: 0x8c840004  lw          $a0, 0x4($a0) (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 4)));
        ctx->in_delay_slot = false;
    ctx->pc = 0x12D950u;
    if (runtime->hasFunction(0x12D950u)) {
        auto targetFn = runtime->lookupFunction(0x12D950u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x132880u; }
        if (ctx->pc != 0x132880u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0012D950_0x12d950(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x132880u; }
        if (ctx->pc != 0x132880u) { return; }
    }
    ctx->pc = 0x132880u;
label_132880:
    // 0x132880: 0xdfbf0000  ld          $ra, 0x0($sp)
    ctx->pc = 0x132880u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x132884: 0x3e00008  jr          $ra
    ctx->pc = 0x132884u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x132888u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x132884u;
            // 0x132888: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1327F0u: goto label_1327f0;
            case 0x132800u: goto label_132800;
            case 0x132838u: goto label_132838;
            case 0x132840u: goto label_132840;
            case 0x132844u: goto label_132844;
            case 0x132860u: goto label_132860;
            case 0x132880u: goto label_132880;
            default: break;
        }
        return;
    }
    ctx->pc = 0x13288Cu;
    // 0x13288c: 0x0  nop
    ctx->pc = 0x13288cu;
    // NOP
    // 0x132890: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x132890u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x132894: 0xffbf0000  sd          $ra, 0x0($sp)
    ctx->pc = 0x132894u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 31));
    // 0x132898: 0x8c840004  lw          $a0, 0x4($a0)
    ctx->pc = 0x132898u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 4)));
    // 0x13289c: 0xdfbf0000  ld          $ra, 0x0($sp)
    ctx->pc = 0x13289cu;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1328a0: 0x804b66e  j           func_12D9B8
    ctx->pc = 0x1328A0u;
    ctx->pc = 0x1328A4u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1328A0u;
            // 0x1328a4: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
    ctx->pc = 0x12D9B8u;
    if (runtime->hasFunction(0x12D9B8u)) {
        auto targetFn = runtime->lookupFunction(0x12D9B8u);
        targetFn(rdram, ctx, runtime); return;
    } else {
        sub_0012D9B8_0x12d9b8(rdram, ctx, runtime); return;
    }
    ctx->pc = 0x1328A8u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
