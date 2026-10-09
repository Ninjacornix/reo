#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001115D0
// Address: 0x1115d0 - 0x111648
void sub_001115D0_0x1115d0(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001115D0_0x1115d0");
#endif

    switch (ctx->pc) {
        case 0x1115f4u: goto label_1115f4;
        case 0x111610u: goto label_111610;
        case 0x11161cu: goto label_11161c;
        default: break;
    }

    ctx->pc = 0x1115d0u;

    // 0x1115d0: 0x27bdffe0  addiu       $sp, $sp, -0x20
    ctx->pc = 0x1115d0u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967264));
    // 0x1115d4: 0xffb10008  sd          $s1, 0x8($sp)
    ctx->pc = 0x1115d4u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 8), GPR_U64(ctx, 17));
    // 0x1115d8: 0x882d  daddu       $s1, $zero, $zero
    ctx->pc = 0x1115d8u;
    SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1115dc: 0x220282d  daddu       $a1, $s1, $zero
    ctx->pc = 0x1115dcu;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1115e0: 0xffb00000  sd          $s0, 0x0($sp)
    ctx->pc = 0x1115e0u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x1115e4: 0xffbf0010  sd          $ra, 0x10($sp)
    ctx->pc = 0x1115e4u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 31));
    // 0x1115e8: 0x80802d  daddu       $s0, $a0, $zero
    ctx->pc = 0x1115e8u;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1115ec: 0xc0448a6  jal         func_112298
    ctx->pc = 0x1115ECu;
    SET_GPR_U32(ctx, 31, 0x1115F4u);
    ctx->pc = 0x112298u;
    if (runtime->hasFunction(0x112298u)) {
        auto targetFn = runtime->lookupFunction(0x112298u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1115F4u; }
        if (ctx->pc != 0x1115F4u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00112298_0x112298(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1115F4u; }
        if (ctx->pc != 0x1115F4u) { return; }
    }
    ctx->pc = 0x1115F4u;
label_1115f4:
    // 0x1115f4: 0x200202d  daddu       $a0, $s0, $zero
    ctx->pc = 0x1115f4u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1115f8: 0x200282d  daddu       $a1, $s0, $zero
    ctx->pc = 0x1115f8u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1115fc: 0x443000e  bgezl       $v0, . + 4 + (0xE << 2)
    ctx->pc = 0x1115FCu;
    {
        const bool branch_taken_0x1115fc = (GPR_S64(ctx, 2) >= 0);
        if (branch_taken_0x1115fc) {
            ctx->pc = 0x111600u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x1115FCu;
            // 0x111600: 0xdfb00000  ld          $s0, 0x0($sp) (Delay Slot)
        SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
        ctx->in_delay_slot = false;
            ctx->pc = 0x111638u;
            goto label_111638;
        }
    }
    ctx->pc = 0x111604u;
    // 0x111604: 0x220202d  daddu       $a0, $s1, $zero
    ctx->pc = 0x111604u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
    // 0x111608: 0xc044752  jal         func_111D48
    ctx->pc = 0x111608u;
    SET_GPR_U32(ctx, 31, 0x111610u);
    ctx->pc = 0x111D48u;
    if (runtime->hasFunction(0x111D48u)) {
        auto targetFn = runtime->lookupFunction(0x111D48u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x111610u; }
        if (ctx->pc != 0x111610u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00111D48_0x111d48(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x111610u; }
        if (ctx->pc != 0x111610u) { return; }
    }
    ctx->pc = 0x111610u;
label_111610:
    // 0x111610: 0x40202d  daddu       $a0, $v0, $zero
    ctx->pc = 0x111610u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x111614: 0xc04452e  jal         func_1114B8
    ctx->pc = 0x111614u;
    SET_GPR_U32(ctx, 31, 0x11161Cu);
    ctx->pc = 0x1114B8u;
    if (runtime->hasFunction(0x1114B8u)) {
        auto targetFn = runtime->lookupFunction(0x1114B8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x11161Cu; }
        if (ctx->pc != 0x11161Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001114B8_0x1114b8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x11161Cu; }
        if (ctx->pc != 0x11161Cu) { return; }
    }
    ctx->pc = 0x11161Cu;
label_11161c:
    // 0x11161c: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x11161cu;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x111620: 0x2102f  dsubu       $v0, $zero, $v0
    ctx->pc = 0x111620u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 0) - GPR_U64(ctx, 2));
    // 0x111624: 0xdfb10008  ld          $s1, 0x8($sp)
    ctx->pc = 0x111624u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x111628: 0xdfbf0010  ld          $ra, 0x10($sp)
    ctx->pc = 0x111628u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x11162c: 0x3e00008  jr          $ra
    ctx->pc = 0x11162Cu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x111630u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x11162Cu;
            // 0x111630: 0x27bd0020  addiu       $sp, $sp, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1115F4u: goto label_1115f4;
            case 0x111610u: goto label_111610;
            case 0x11161Cu: goto label_11161c;
            case 0x111638u: goto label_111638;
            default: break;
        }
        return;
    }
    ctx->pc = 0x111634u;
    // 0x111634: 0x0  nop
    ctx->pc = 0x111634u;
    // NOP
label_111638:
    // 0x111638: 0xdfb10008  ld          $s1, 0x8($sp)
    ctx->pc = 0x111638u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x11163c: 0xdfbf0010  ld          $ra, 0x10($sp)
    ctx->pc = 0x11163cu;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x111640: 0x804452e  j           func_1114B8
    ctx->pc = 0x111640u;
    ctx->pc = 0x111644u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x111640u;
            // 0x111644: 0x27bd0020  addiu       $sp, $sp, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1114B8u;
    if (runtime->hasFunction(0x1114B8u)) {
        auto targetFn = runtime->lookupFunction(0x1114B8u);
        targetFn(rdram, ctx, runtime); return;
    } else {
        sub_001114B8_0x1114b8(rdram, ctx, runtime); return;
    }
    ctx->pc = 0x111648u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
