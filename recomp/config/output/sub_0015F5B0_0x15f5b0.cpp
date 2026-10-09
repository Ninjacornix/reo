#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_0015F5B0
// Address: 0x15f5b0 - 0x15f660
void sub_0015F5B0_0x15f5b0(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_0015F5B0_0x15f5b0");
#endif

    switch (ctx->pc) {
        case 0x15f5d0u: goto label_15f5d0;
        case 0x15f5e0u: goto label_15f5e0;
        case 0x15f5e8u: goto label_15f5e8;
        case 0x15f62cu: goto label_15f62c;
        default: break;
    }

    ctx->pc = 0x15f5b0u;

    // 0x15f5b0: 0x27bdffe0  addiu       $sp, $sp, -0x20
    ctx->pc = 0x15f5b0u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967264));
    // 0x15f5b4: 0xffb00000  sd          $s0, 0x0($sp)
    ctx->pc = 0x15f5b4u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x15f5b8: 0x80802d  daddu       $s0, $a0, $zero
    ctx->pc = 0x15f5b8u;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x15f5bc: 0xffbf0010  sd          $ra, 0x10($sp)
    ctx->pc = 0x15f5bcu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 31));
    // 0x15f5c0: 0xffb10008  sd          $s1, 0x8($sp)
    ctx->pc = 0x15f5c0u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 8), GPR_U64(ctx, 17));
    // 0x15f5c4: 0x8e110134  lw          $s1, 0x134($s0)
    ctx->pc = 0x15f5c4u;
    SET_GPR_S32(ctx, 17, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 308)));
    // 0x15f5c8: 0xc0448ba  jal         func_1122E8
    ctx->pc = 0x15F5C8u;
    SET_GPR_U32(ctx, 31, 0x15F5D0u);
    ctx->pc = 0x15F5CCu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x15F5C8u;
            // 0x15f5cc: 0x220202d  daddu       $a0, $s1, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1122E8u;
    if (runtime->hasFunction(0x1122E8u)) {
        auto targetFn = runtime->lookupFunction(0x1122E8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x15F5D0u; }
        if (ctx->pc != 0x15F5D0u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001122E8_0x1122e8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x15F5D0u; }
        if (ctx->pc != 0x15F5D0u) { return; }
    }
    ctx->pc = 0x15F5D0u;
label_15f5d0:
    // 0x15f5d0: 0x3c010024  lui         $at, 0x24
    ctx->pc = 0x15f5d0u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)36 << 16));
    // 0x15f5d4: 0xdc25f258  ld          $a1, -0xDA8($at)
    ctx->pc = 0x15f5d4u;
    SET_GPR_U64(ctx, 5, READ64(ADD32(GPR_U32(ctx, 1), 4294963800)));
    // 0x15f5d8: 0xc04476c  jal         func_111DB0
    ctx->pc = 0x15F5D8u;
    SET_GPR_U32(ctx, 31, 0x15F5E0u);
    ctx->pc = 0x15F5DCu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x15F5D8u;
            // 0x15f5dc: 0x40202d  daddu       $a0, $v0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x111DB0u;
    if (runtime->hasFunction(0x111DB0u)) {
        auto targetFn = runtime->lookupFunction(0x111DB0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x15F5E0u; }
        if (ctx->pc != 0x15F5E0u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00111DB0_0x111db0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x15F5E0u; }
        if (ctx->pc != 0x15F5E0u) { return; }
    }
    ctx->pc = 0x15F5E0u;
label_15f5e0:
    // 0x15f5e0: 0xc0448e8  jal         func_1123A0
    ctx->pc = 0x15F5E0u;
    SET_GPR_U32(ctx, 31, 0x15F5E8u);
    ctx->pc = 0x15F5E4u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x15F5E0u;
            // 0x15f5e4: 0x40202d  daddu       $a0, $v0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1123A0u;
    if (runtime->hasFunction(0x1123A0u)) {
        auto targetFn = runtime->lookupFunction(0x1123A0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x15F5E8u; }
        if (ctx->pc != 0x15F5E8u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001123A0_0x1123a0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x15F5E8u; }
        if (ctx->pc != 0x15F5E8u) { return; }
    }
    ctx->pc = 0x15F5E8u;
label_15f5e8:
    // 0x15f5e8: 0x200202d  daddu       $a0, $s0, $zero
    ctx->pc = 0x15f5e8u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x15f5ec: 0x220302d  daddu       $a2, $s1, $zero
    ctx->pc = 0x15f5ecu;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
    // 0x15f5f0: 0xdfb10008  ld          $s1, 0x8($sp)
    ctx->pc = 0x15f5f0u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x15f5f4: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x15f5f4u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x15f5f8: 0x40282d  daddu       $a1, $v0, $zero
    ctx->pc = 0x15f5f8u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x15f5fc: 0xdfbf0010  ld          $ra, 0x10($sp)
    ctx->pc = 0x15f5fcu;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x15f600: 0x8057fc6  j           func_15FF18
    ctx->pc = 0x15F600u;
    ctx->pc = 0x15F604u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x15F600u;
            // 0x15f604: 0x27bd0020  addiu       $sp, $sp, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
        ctx->in_delay_slot = false;
    ctx->pc = 0x15FF18u;
    if (runtime->hasFunction(0x15FF18u)) {
        auto targetFn = runtime->lookupFunction(0x15FF18u);
        targetFn(rdram, ctx, runtime); return;
    } else {
        sub_0015FF18_0x15ff18(rdram, ctx, runtime); return;
    }
    ctx->pc = 0x15F608u;
    // 0x15f608: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x15f608u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x15f60c: 0xffb00000  sd          $s0, 0x0($sp)
    ctx->pc = 0x15f60cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x15f610: 0xffbf0008  sd          $ra, 0x8($sp)
    ctx->pc = 0x15f610u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 8), GPR_U64(ctx, 31));
    // 0x15f614: 0x8c820044  lw          $v0, 0x44($a0)
    ctx->pc = 0x15f614u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 68)));
    // 0x15f618: 0x8c900040  lw          $s0, 0x40($a0)
    ctx->pc = 0x15f618u;
    SET_GPR_S32(ctx, 16, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 64)));
    // 0x15f61c: 0x1040000c  beqz        $v0, . + 4 + (0xC << 2)
    ctx->pc = 0x15F61Cu;
    {
        const bool branch_taken_0x15f61c = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x15F620u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x15F61Cu;
            // 0x15f620: 0x40202d  daddu       $a0, $v0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x15f61c) {
            ctx->pc = 0x15F650u;
            goto label_15f650;
        }
    }
    ctx->pc = 0x15F624u;
    // 0x15f624: 0xc0591ca  jal         func_164728
    ctx->pc = 0x15F624u;
    SET_GPR_U32(ctx, 31, 0x15F62Cu);
    ctx->pc = 0x164728u;
    if (runtime->hasFunction(0x164728u)) {
        auto targetFn = runtime->lookupFunction(0x164728u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x15F62Cu; }
        if (ctx->pc != 0x15F62Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00164728_0x164728(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x15F62Cu; }
        if (ctx->pc != 0x15F62Cu) { return; }
    }
    ctx->pc = 0x15F62Cu;
label_15f62c:
    // 0x15f62c: 0x24030003  addiu       $v1, $zero, 0x3
    ctx->pc = 0x15f62cu;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 3));
    // 0x15f630: 0x54430008  bnel        $v0, $v1, . + 4 + (0x8 << 2)
    ctx->pc = 0x15F630u;
    {
        const bool branch_taken_0x15f630 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 3));
        if (branch_taken_0x15f630) {
            ctx->pc = 0x15F634u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x15F630u;
            // 0x15f634: 0xdfb00000  ld          $s0, 0x0($sp) (Delay Slot)
        SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
        ctx->in_delay_slot = false;
            ctx->pc = 0x15F654u;
            goto label_15f654;
        }
    }
    ctx->pc = 0x15F638u;
    // 0x15f638: 0x200202d  daddu       $a0, $s0, $zero
    ctx->pc = 0x15f638u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x15f63c: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x15f63cu;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x15f640: 0xdfbf0008  ld          $ra, 0x8($sp)
    ctx->pc = 0x15f640u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x15f644: 0x805cfca  j           func_173F28
    ctx->pc = 0x15F644u;
    ctx->pc = 0x15F648u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x15F644u;
            // 0x15f648: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
    ctx->pc = 0x173F28u;
    if (runtime->hasFunction(0x173F28u)) {
        auto targetFn = runtime->lookupFunction(0x173F28u);
        targetFn(rdram, ctx, runtime); return;
    } else {
        sub_00173F28_0x173f28(rdram, ctx, runtime); return;
    }
    ctx->pc = 0x15F64Cu;
    // 0x15f64c: 0x0  nop
    ctx->pc = 0x15f64cu;
    // NOP
label_15f650:
    // 0x15f650: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x15f650u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
label_15f654:
    // 0x15f654: 0xdfbf0008  ld          $ra, 0x8($sp)
    ctx->pc = 0x15f654u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x15f658: 0x3e00008  jr          $ra
    ctx->pc = 0x15F658u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x15F65Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x15F658u;
            // 0x15f65c: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x15F5D0u: goto label_15f5d0;
            case 0x15F5E0u: goto label_15f5e0;
            case 0x15F5E8u: goto label_15f5e8;
            case 0x15F62Cu: goto label_15f62c;
            case 0x15F650u: goto label_15f650;
            case 0x15F654u: goto label_15f654;
            default: break;
        }
        return;
    }
    ctx->pc = 0x15F660u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
