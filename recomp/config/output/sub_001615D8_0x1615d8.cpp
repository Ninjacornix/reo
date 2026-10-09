#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001615D8
// Address: 0x1615d8 - 0x161654
void sub_001615D8_0x1615d8(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001615D8_0x1615d8");
#endif

    switch (ctx->pc) {
        case 0x1615fcu: goto label_1615fc;
        case 0x161630u: goto label_161630;
        default: break;
    }

    ctx->pc = 0x1615d8u;

    // 0x1615d8: 0x27bdffe0  addiu       $sp, $sp, -0x20
    ctx->pc = 0x1615d8u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967264));
    // 0x1615dc: 0xffb00000  sd          $s0, 0x0($sp)
    ctx->pc = 0x1615dcu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x1615e0: 0x80802d  daddu       $s0, $a0, $zero
    ctx->pc = 0x1615e0u;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1615e4: 0xffb10008  sd          $s1, 0x8($sp)
    ctx->pc = 0x1615e4u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 8), GPR_U64(ctx, 17));
    // 0x1615e8: 0xa0882d  daddu       $s1, $a1, $zero
    ctx->pc = 0x1615e8u;
    SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1615ec: 0xffb20010  sd          $s2, 0x10($sp)
    ctx->pc = 0x1615ecu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 18));
    // 0x1615f0: 0xffbf0018  sd          $ra, 0x18($sp)
    ctx->pc = 0x1615f0u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 24), GPR_U64(ctx, 31));
    // 0x1615f4: 0xc057ff0  jal         func_15FFC0
    ctx->pc = 0x1615F4u;
    SET_GPR_U32(ctx, 31, 0x1615FCu);
    ctx->pc = 0x1615F8u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1615F4u;
            // 0x1615f8: 0xc0902d  daddu       $s2, $a2, $zero (Delay Slot)
        SET_GPR_U64(ctx, 18, (uint64_t)GPR_U64(ctx, 6) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x15FFC0u;
    if (runtime->hasFunction(0x15FFC0u)) {
        auto targetFn = runtime->lookupFunction(0x15FFC0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1615FCu; }
        if (ctx->pc != 0x1615FCu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0015FFC0_0x15ffc0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1615FCu; }
        if (ctx->pc != 0x1615FCu) { return; }
    }
    ctx->pc = 0x1615FCu;
label_1615fc:
    // 0x1615fc: 0x1440000a  bnez        $v0, . + 4 + (0xA << 2)
    ctx->pc = 0x1615FCu;
    {
        const bool branch_taken_0x1615fc = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x161600u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1615FCu;
            // 0x161600: 0x200202d  daddu       $a0, $s0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1615fc) {
            ctx->pc = 0x161628u;
            goto label_161628;
        }
    }
    ctx->pc = 0x161604u;
    // 0x161604: 0x3c040024  lui         $a0, 0x24
    ctx->pc = 0x161604u;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)36 << 16));
    // 0x161608: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x161608u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x16160c: 0xdfb10008  ld          $s1, 0x8($sp)
    ctx->pc = 0x16160cu;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x161610: 0x2484fd28  addiu       $a0, $a0, -0x2D8
    ctx->pc = 0x161610u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 4294966568));
    // 0x161614: 0xdfb20010  ld          $s2, 0x10($sp)
    ctx->pc = 0x161614u;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x161618: 0xdfbf0018  ld          $ra, 0x18($sp)
    ctx->pc = 0x161618u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 24)));
    // 0x16161c: 0x8058dd4  j           func_163750
    ctx->pc = 0x16161Cu;
    ctx->pc = 0x161620u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x16161Cu;
            // 0x161620: 0x27bd0020  addiu       $sp, $sp, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
        ctx->in_delay_slot = false;
    ctx->pc = 0x163750u;
    if (runtime->hasFunction(0x163750u)) {
        auto targetFn = runtime->lookupFunction(0x163750u);
        targetFn(rdram, ctx, runtime); return;
    } else {
        sub_00163750_0x163750(rdram, ctx, runtime); return;
    }
    ctx->pc = 0x161624u;
    // 0x161624: 0x0  nop
    ctx->pc = 0x161624u;
    // NOP
label_161628:
    // 0x161628: 0xc0582e4  jal         func_160B90
    ctx->pc = 0x161628u;
    SET_GPR_U32(ctx, 31, 0x161630u);
    ctx->pc = 0x160B90u;
    if (runtime->hasFunction(0x160B90u)) {
        auto targetFn = runtime->lookupFunction(0x160B90u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x161630u; }
        if (ctx->pc != 0x161630u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00160B90_0x160b90(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x161630u; }
        if (ctx->pc != 0x161630u) { return; }
    }
    ctx->pc = 0x161630u;
label_161630:
    // 0x161630: 0x220282d  daddu       $a1, $s1, $zero
    ctx->pc = 0x161630u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
    // 0x161634: 0x240302d  daddu       $a2, $s2, $zero
    ctx->pc = 0x161634u;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 18) + (uint64_t)GPR_U64(ctx, 0));
    // 0x161638: 0xdfb20010  ld          $s2, 0x10($sp)
    ctx->pc = 0x161638u;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x16163c: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x16163cu;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x161640: 0x40202d  daddu       $a0, $v0, $zero
    ctx->pc = 0x161640u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x161644: 0xdfb10008  ld          $s1, 0x8($sp)
    ctx->pc = 0x161644u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x161648: 0xdfbf0018  ld          $ra, 0x18($sp)
    ctx->pc = 0x161648u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 24)));
    // 0x16164c: 0x805f49a  j           func_17D268
    ctx->pc = 0x16164Cu;
    ctx->pc = 0x161650u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x16164Cu;
            // 0x161650: 0x27bd0020  addiu       $sp, $sp, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
        ctx->in_delay_slot = false;
    ctx->pc = 0x17D268u;
    if (runtime->hasFunction(0x17D268u)) {
        auto targetFn = runtime->lookupFunction(0x17D268u);
        targetFn(rdram, ctx, runtime); return;
    } else {
        sub_0017D268_0x17d268(rdram, ctx, runtime); return;
    }
    ctx->pc = 0x161654u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
