#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001385D8
// Address: 0x1385d8 - 0x138650
void sub_001385D8_0x1385d8(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001385D8_0x1385d8");
#endif

    switch (ctx->pc) {
        case 0x1385fcu: goto label_1385fc;
        case 0x13860cu: goto label_13860c;
        case 0x138628u: goto label_138628;
        case 0x138630u: goto label_138630;
        default: break;
    }

    ctx->pc = 0x1385d8u;

    // 0x1385d8: 0x27bdffe0  addiu       $sp, $sp, -0x20
    ctx->pc = 0x1385d8u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967264));
    // 0x1385dc: 0xffb00000  sd          $s0, 0x0($sp)
    ctx->pc = 0x1385dcu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x1385e0: 0x80802d  daddu       $s0, $a0, $zero
    ctx->pc = 0x1385e0u;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1385e4: 0xffb10008  sd          $s1, 0x8($sp)
    ctx->pc = 0x1385e4u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 8), GPR_U64(ctx, 17));
    // 0x1385e8: 0xa0882d  daddu       $s1, $a1, $zero
    ctx->pc = 0x1385e8u;
    SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1385ec: 0xffb20010  sd          $s2, 0x10($sp)
    ctx->pc = 0x1385ecu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 18));
    // 0x1385f0: 0xffbf0018  sd          $ra, 0x18($sp)
    ctx->pc = 0x1385f0u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 24), GPR_U64(ctx, 31));
    // 0x1385f4: 0xc04e0bc  jal         func_1382F0
    ctx->pc = 0x1385F4u;
    SET_GPR_U32(ctx, 31, 0x1385FCu);
    ctx->pc = 0x1385F8u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1385F4u;
            // 0x1385f8: 0xc0902d  daddu       $s2, $a2, $zero (Delay Slot)
        SET_GPR_U64(ctx, 18, (uint64_t)GPR_U64(ctx, 6) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1382F0u;
    if (runtime->hasFunction(0x1382F0u)) {
        auto targetFn = runtime->lookupFunction(0x1382F0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1385FCu; }
        if (ctx->pc != 0x1385FCu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001382F0_0x1382f0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1385FCu; }
        if (ctx->pc != 0x1385FCu) { return; }
    }
    ctx->pc = 0x1385FCu;
label_1385fc:
    // 0x1385fc: 0x200202d  daddu       $a0, $s0, $zero
    ctx->pc = 0x1385fcu;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x138600: 0x220282d  daddu       $a1, $s1, $zero
    ctx->pc = 0x138600u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
    // 0x138604: 0xc04642c  jal         func_1190B0
    ctx->pc = 0x138604u;
    SET_GPR_U32(ctx, 31, 0x13860Cu);
    ctx->pc = 0x138608u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x138604u;
            // 0x138608: 0x240302d  daddu       $a2, $s2, $zero (Delay Slot)
        SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 18) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1190B0u;
    if (runtime->hasFunction(0x1190B0u)) {
        auto targetFn = runtime->lookupFunction(0x1190B0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x13860Cu; }
        if (ctx->pc != 0x13860Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001190B0_0x1190b0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x13860Cu; }
        if (ctx->pc != 0x13860Cu) { return; }
    }
    ctx->pc = 0x13860Cu;
label_13860c:
    // 0x13860c: 0x3c040024  lui         $a0, 0x24
    ctx->pc = 0x13860cu;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)36 << 16));
    // 0x138610: 0x40802d  daddu       $s0, $v0, $zero
    ctx->pc = 0x138610u;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x138614: 0x2484c7a0  addiu       $a0, $a0, -0x3860
    ctx->pc = 0x138614u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 4294952864));
    // 0x138618: 0x6010003  bgez        $s0, . + 4 + (0x3 << 2)
    ctx->pc = 0x138618u;
    {
        const bool branch_taken_0x138618 = (GPR_S64(ctx, 16) >= 0);
        ctx->pc = 0x13861Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x138618u;
            // 0x13861c: 0x200282d  daddu       $a1, $s0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x138618) {
            ctx->pc = 0x138628u;
            goto label_138628;
        }
    }
    ctx->pc = 0x138620u;
    // 0x138620: 0xc045a12  jal         func_116848
    ctx->pc = 0x138620u;
    SET_GPR_U32(ctx, 31, 0x138628u);
    ctx->pc = 0x116848u;
    if (runtime->hasFunction(0x116848u)) {
        auto targetFn = runtime->lookupFunction(0x116848u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x138628u; }
        if (ctx->pc != 0x138628u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00116848_0x116848(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x138628u; }
        if (ctx->pc != 0x138628u) { return; }
    }
    ctx->pc = 0x138628u;
label_138628:
    // 0x138628: 0xc04e0ca  jal         func_138328
    ctx->pc = 0x138628u;
    SET_GPR_U32(ctx, 31, 0x138630u);
    ctx->pc = 0x138328u;
    if (runtime->hasFunction(0x138328u)) {
        auto targetFn = runtime->lookupFunction(0x138328u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x138630u; }
        if (ctx->pc != 0x138630u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00138328_0x138328(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x138630u; }
        if (ctx->pc != 0x138630u) { return; }
    }
    ctx->pc = 0x138630u;
label_138630:
    // 0x138630: 0x200102d  daddu       $v0, $s0, $zero
    ctx->pc = 0x138630u;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x138634: 0xdfb10008  ld          $s1, 0x8($sp)
    ctx->pc = 0x138634u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x138638: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x138638u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x13863c: 0xdfb20010  ld          $s2, 0x10($sp)
    ctx->pc = 0x13863cu;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x138640: 0xdfbf0018  ld          $ra, 0x18($sp)
    ctx->pc = 0x138640u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 24)));
    // 0x138644: 0x3e00008  jr          $ra
    ctx->pc = 0x138644u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x138648u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x138644u;
            // 0x138648: 0x27bd0020  addiu       $sp, $sp, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1385FCu: goto label_1385fc;
            case 0x13860Cu: goto label_13860c;
            case 0x138628u: goto label_138628;
            case 0x138630u: goto label_138630;
            default: break;
        }
        return;
    }
    ctx->pc = 0x13864Cu;
    // 0x13864c: 0x0  nop
    ctx->pc = 0x13864cu;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
