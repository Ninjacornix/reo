#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001645D8
// Address: 0x1645d8 - 0x164648
void sub_001645D8_0x1645d8(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001645D8_0x1645d8");
#endif

    switch (ctx->pc) {
        case 0x16460cu: goto label_16460c;
        case 0x164628u: goto label_164628;
        default: break;
    }

    ctx->pc = 0x1645d8u;

    // 0x1645d8: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x1645d8u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x1645dc: 0xffbf0000  sd          $ra, 0x0($sp)
    ctx->pc = 0x1645dcu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 31));
    // 0x1645e0: 0xdfbf0000  ld          $ra, 0x0($sp)
    ctx->pc = 0x1645e0u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1645e4: 0x804c108  j           func_130420
    ctx->pc = 0x1645E4u;
    ctx->pc = 0x1645E8u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1645E4u;
            // 0x1645e8: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
    ctx->pc = 0x130420u;
    if (runtime->hasFunction(0x130420u)) {
        auto targetFn = runtime->lookupFunction(0x130420u);
        targetFn(rdram, ctx, runtime); return;
    } else {
        sub_00130420_0x130420(rdram, ctx, runtime); return;
    }
    ctx->pc = 0x1645ECu;
    // 0x1645ec: 0x0  nop
    ctx->pc = 0x1645ecu;
    // NOP
    // 0x1645f0: 0x27bdffe0  addiu       $sp, $sp, -0x20
    ctx->pc = 0x1645f0u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967264));
    // 0x1645f4: 0xffb00000  sd          $s0, 0x0($sp)
    ctx->pc = 0x1645f4u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x1645f8: 0xa0802d  daddu       $s0, $a1, $zero
    ctx->pc = 0x1645f8u;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1645fc: 0xffb10008  sd          $s1, 0x8($sp)
    ctx->pc = 0x1645fcu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 8), GPR_U64(ctx, 17));
    // 0x164600: 0xffbf0010  sd          $ra, 0x10($sp)
    ctx->pc = 0x164600u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 31));
    // 0x164604: 0xc04c148  jal         func_130520
    ctx->pc = 0x164604u;
    SET_GPR_U32(ctx, 31, 0x16460Cu);
    ctx->pc = 0x164608u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x164604u;
            // 0x164608: 0x80882d  daddu       $s1, $a0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x130520u;
    if (runtime->hasFunction(0x130520u)) {
        auto targetFn = runtime->lookupFunction(0x130520u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x16460Cu; }
        if (ctx->pc != 0x16460Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00130520_0x130520(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x16460Cu; }
        if (ctx->pc != 0x16460Cu) { return; }
    }
    ctx->pc = 0x16460Cu;
label_16460c:
    // 0x16460c: 0x3c08000f  lui         $t0, 0xF
    ctx->pc = 0x16460cu;
    SET_GPR_S32(ctx, 8, (int32_t)((uint32_t)15 << 16));
    // 0x164610: 0x220202d  daddu       $a0, $s1, $zero
    ctx->pc = 0x164610u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
    // 0x164614: 0x200282d  daddu       $a1, $s0, $zero
    ctx->pc = 0x164614u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x164618: 0x302d  daddu       $a2, $zero, $zero
    ctx->pc = 0x164618u;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x16461c: 0x382d  daddu       $a3, $zero, $zero
    ctx->pc = 0x16461cu;
    SET_GPR_U64(ctx, 7, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x164620: 0xc04c11e  jal         func_130478
    ctx->pc = 0x164620u;
    SET_GPR_U32(ctx, 31, 0x164628u);
    ctx->pc = 0x164624u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x164620u;
            // 0x164624: 0x3508ffff  ori         $t0, $t0, 0xFFFF (Delay Slot)
        SET_GPR_U64(ctx, 8, GPR_U64(ctx, 8) | (uint64_t)(uint16_t)65535);
        ctx->in_delay_slot = false;
    ctx->pc = 0x130478u;
    if (runtime->hasFunction(0x130478u)) {
        auto targetFn = runtime->lookupFunction(0x130478u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x164628u; }
        if (ctx->pc != 0x164628u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00130478_0x130478(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x164628u; }
        if (ctx->pc != 0x164628u) { return; }
    }
    ctx->pc = 0x164628u;
label_164628:
    // 0x164628: 0x220202d  daddu       $a0, $s1, $zero
    ctx->pc = 0x164628u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
    // 0x16462c: 0x3c05000f  lui         $a1, 0xF
    ctx->pc = 0x16462cu;
    SET_GPR_S32(ctx, 5, (int32_t)((uint32_t)15 << 16));
    // 0x164630: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x164630u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x164634: 0xdfb10008  ld          $s1, 0x8($sp)
    ctx->pc = 0x164634u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x164638: 0x34a5ffff  ori         $a1, $a1, 0xFFFF
    ctx->pc = 0x164638u;
    SET_GPR_U64(ctx, 5, GPR_U64(ctx, 5) | (uint64_t)(uint16_t)65535);
    // 0x16463c: 0xdfbf0010  ld          $ra, 0x10($sp)
    ctx->pc = 0x16463cu;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x164640: 0x804c1ea  j           func_1307A8
    ctx->pc = 0x164640u;
    ctx->pc = 0x164644u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x164640u;
            // 0x164644: 0x27bd0020  addiu       $sp, $sp, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1307A8u;
    if (runtime->hasFunction(0x1307A8u)) {
        auto targetFn = runtime->lookupFunction(0x1307A8u);
        targetFn(rdram, ctx, runtime); return;
    } else {
        sub_001307A8_0x1307a8(rdram, ctx, runtime); return;
    }
    ctx->pc = 0x164648u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
