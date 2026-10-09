#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_0017A3E8
// Address: 0x17a3e8 - 0x17a460
void sub_0017A3E8_0x17a3e8(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_0017A3E8_0x17a3e8");
#endif

    switch (ctx->pc) {
        case 0x17a40cu: goto label_17a40c;
        case 0x17a424u: goto label_17a424;
        default: break;
    }

    ctx->pc = 0x17a3e8u;

    // 0x17a3e8: 0x27bdffe0  addiu       $sp, $sp, -0x20
    ctx->pc = 0x17a3e8u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967264));
    // 0x17a3ec: 0xffb00000  sd          $s0, 0x0($sp)
    ctx->pc = 0x17a3ecu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x17a3f0: 0x30b000ff  andi        $s0, $a1, 0xFF
    ctx->pc = 0x17a3f0u;
    SET_GPR_U64(ctx, 16, GPR_U64(ctx, 5) & (uint64_t)(uint16_t)255);
    // 0x17a3f4: 0x200282d  daddu       $a1, $s0, $zero
    ctx->pc = 0x17a3f4u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x17a3f8: 0xffb10008  sd          $s1, 0x8($sp)
    ctx->pc = 0x17a3f8u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 8), GPR_U64(ctx, 17));
    // 0x17a3fc: 0xffb20010  sd          $s2, 0x10($sp)
    ctx->pc = 0x17a3fcu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 18));
    // 0x17a400: 0xffbf0018  sd          $ra, 0x18($sp)
    ctx->pc = 0x17a400u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 24), GPR_U64(ctx, 31));
    // 0x17a404: 0xc05e756  jal         func_179D58
    ctx->pc = 0x17A404u;
    SET_GPR_U32(ctx, 31, 0x17A40Cu);
    ctx->pc = 0x17A408u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x17A404u;
            // 0x17a408: 0xc0902d  daddu       $s2, $a2, $zero (Delay Slot)
        SET_GPR_U64(ctx, 18, (uint64_t)GPR_U64(ctx, 6) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x179D58u;
    if (runtime->hasFunction(0x179D58u)) {
        auto targetFn = runtime->lookupFunction(0x179D58u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x17A40Cu; }
        if (ctx->pc != 0x17A40Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00179D58_0x179d58(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x17A40Cu; }
        if (ctx->pc != 0x17A40Cu) { return; }
    }
    ctx->pc = 0x17A40Cu;
label_17a40c:
    // 0x17a40c: 0x40882d  daddu       $s1, $v0, $zero
    ctx->pc = 0x17a40cu;
    SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x17a410: 0x200202d  daddu       $a0, $s0, $zero
    ctx->pc = 0x17a410u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x17a414: 0x1220000c  beqz        $s1, . + 4 + (0xC << 2)
    ctx->pc = 0x17A414u;
    {
        const bool branch_taken_0x17a414 = (GPR_U64(ctx, 17) == GPR_U64(ctx, 0));
        ctx->pc = 0x17A418u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x17A414u;
            // 0x17a418: 0x220282d  daddu       $a1, $s1, $zero (Delay Slot)
        SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x17a414) {
            ctx->pc = 0x17A448u;
            goto label_17a448;
        }
    }
    ctx->pc = 0x17A41Cu;
    // 0x17a41c: 0xc05e966  jal         func_17A598
    ctx->pc = 0x17A41Cu;
    SET_GPR_U32(ctx, 31, 0x17A424u);
    ctx->pc = 0x17A598u;
    if (runtime->hasFunction(0x17A598u)) {
        auto targetFn = runtime->lookupFunction(0x17A598u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x17A424u; }
        if (ctx->pc != 0x17A424u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0017A598_0x17a598(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x17A424u; }
        if (ctx->pc != 0x17A424u) { return; }
    }
    ctx->pc = 0x17A424u;
label_17a424:
    // 0x17a424: 0x10400009  beqz        $v0, . + 4 + (0x9 << 2)
    ctx->pc = 0x17A424u;
    {
        const bool branch_taken_0x17a424 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x17A428u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x17A424u;
            // 0x17a428: 0xdfb00000  ld          $s0, 0x0($sp) (Delay Slot)
        SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x17a424) {
            ctx->pc = 0x17A44Cu;
            goto label_17a44c;
        }
    }
    ctx->pc = 0x17A42Cu;
    // 0x17a42c: 0x92220026  lbu         $v0, 0x26($s1)
    ctx->pc = 0x17a42cu;
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 17), 38)));
    // 0x17a430: 0x28430040  slti        $v1, $v0, 0x40
    ctx->pc = 0x17a430u;
    SET_GPR_U64(ctx, 3, ((int64_t)GPR_S64(ctx, 2) < (int64_t)(int32_t)64) ? 1 : 0);
    // 0x17a434: 0x14600003  bnez        $v1, . + 4 + (0x3 << 2)
    ctx->pc = 0x17A434u;
    {
        const bool branch_taken_0x17a434 = (GPR_U64(ctx, 3) != GPR_U64(ctx, 0));
        ctx->pc = 0x17A438u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x17A434u;
            // 0x17a438: 0xae420000  sw          $v0, 0x0($s2) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 18), 0), GPR_U32(ctx, 2));
        ctx->in_delay_slot = false;
        if (branch_taken_0x17a434) {
            ctx->pc = 0x17A444u;
            goto label_17a444;
        }
    }
    ctx->pc = 0x17A43Cu;
    // 0x17a43c: 0x2402ffff  addiu       $v0, $zero, -0x1
    ctx->pc = 0x17a43cu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
    // 0x17a440: 0xae420000  sw          $v0, 0x0($s2)
    ctx->pc = 0x17a440u;
    WRITE32(ADD32(GPR_U32(ctx, 18), 0), GPR_U32(ctx, 2));
label_17a444:
    // 0x17a444: 0x24020001  addiu       $v0, $zero, 0x1
    ctx->pc = 0x17a444u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
label_17a448:
    // 0x17a448: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x17a448u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
label_17a44c:
    // 0x17a44c: 0xdfb10008  ld          $s1, 0x8($sp)
    ctx->pc = 0x17a44cu;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x17a450: 0xdfb20010  ld          $s2, 0x10($sp)
    ctx->pc = 0x17a450u;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x17a454: 0xdfbf0018  ld          $ra, 0x18($sp)
    ctx->pc = 0x17a454u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 24)));
    // 0x17a458: 0x3e00008  jr          $ra
    ctx->pc = 0x17A458u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x17A45Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x17A458u;
            // 0x17a45c: 0x27bd0020  addiu       $sp, $sp, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x17A40Cu: goto label_17a40c;
            case 0x17A424u: goto label_17a424;
            case 0x17A444u: goto label_17a444;
            case 0x17A448u: goto label_17a448;
            case 0x17A44Cu: goto label_17a44c;
            default: break;
        }
        return;
    }
    ctx->pc = 0x17A460u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
