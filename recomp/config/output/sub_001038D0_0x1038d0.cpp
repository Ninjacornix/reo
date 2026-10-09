#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001038D0
// Address: 0x1038d0 - 0x103934
void sub_001038D0_0x1038d0(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001038D0_0x1038d0");
#endif

    switch (ctx->pc) {
        case 0x1038fcu: goto label_1038fc;
        case 0x10390cu: goto label_10390c;
        case 0x103918u: goto label_103918;
        default: break;
    }

    ctx->pc = 0x1038d0u;

    // 0x1038d0: 0x27bdffe0  addiu       $sp, $sp, -0x20
    ctx->pc = 0x1038d0u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967264));
    // 0x1038d4: 0xffb00000  sd          $s0, 0x0($sp)
    ctx->pc = 0x1038d4u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x1038d8: 0x3c100021  lui         $s0, 0x21
    ctx->pc = 0x1038d8u;
    SET_GPR_S32(ctx, 16, (int32_t)((uint32_t)33 << 16));
    // 0x1038dc: 0xffb10008  sd          $s1, 0x8($sp)
    ctx->pc = 0x1038dcu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 8), GPR_U64(ctx, 17));
    // 0x1038e0: 0xa0882d  daddu       $s1, $a1, $zero
    ctx->pc = 0x1038e0u;
    SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1038e4: 0xffb20010  sd          $s2, 0x10($sp)
    ctx->pc = 0x1038e4u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 18));
    // 0x1038e8: 0x80902d  daddu       $s2, $a0, $zero
    ctx->pc = 0x1038e8u;
    SET_GPR_U64(ctx, 18, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1038ec: 0xffbf0018  sd          $ra, 0x18($sp)
    ctx->pc = 0x1038ecu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 24), GPR_U64(ctx, 31));
    // 0x1038f0: 0x261097f0  addiu       $s0, $s0, -0x6810
    ctx->pc = 0x1038f0u;
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 16), 4294940656));
    // 0x1038f4: 0xc041f4a  jal         func_107D28
    ctx->pc = 0x1038F4u;
    SET_GPR_U32(ctx, 31, 0x1038FCu);
    ctx->pc = 0x1038F8u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1038F4u;
            // 0x1038f8: 0x8e040000  lw          $a0, 0x0($s0) (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 0)));
        ctx->in_delay_slot = false;
    ctx->pc = 0x107D28u;
    if (runtime->hasFunction(0x107D28u)) {
        auto targetFn = runtime->lookupFunction(0x107D28u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1038FCu; }
        if (ctx->pc != 0x1038FCu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00107D28_0x107d28(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1038FCu; }
        if (ctx->pc != 0x1038FCu) { return; }
    }
    ctx->pc = 0x1038FCu;
label_1038fc:
    // 0x1038fc: 0x8e040000  lw          $a0, 0x0($s0)
    ctx->pc = 0x1038fcu;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 0)));
    // 0x103900: 0x240282d  daddu       $a1, $s2, $zero
    ctx->pc = 0x103900u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 18) + (uint64_t)GPR_U64(ctx, 0));
    // 0x103904: 0xc040e4e  jal         func_103938
    ctx->pc = 0x103904u;
    SET_GPR_U32(ctx, 31, 0x10390Cu);
    ctx->pc = 0x103908u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x103904u;
            // 0x103908: 0x220302d  daddu       $a2, $s1, $zero (Delay Slot)
        SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x103938u;
    if (runtime->hasFunction(0x103938u)) {
        auto targetFn = runtime->lookupFunction(0x103938u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x10390Cu; }
        if (ctx->pc != 0x10390Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00103938_0x103938(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x10390Cu; }
        if (ctx->pc != 0x10390Cu) { return; }
    }
    ctx->pc = 0x10390Cu;
label_10390c:
    // 0x10390c: 0x8e040000  lw          $a0, 0x0($s0)
    ctx->pc = 0x10390cu;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 0)));
    // 0x103910: 0xc041f6a  jal         func_107DA8
    ctx->pc = 0x103910u;
    SET_GPR_U32(ctx, 31, 0x103918u);
    ctx->pc = 0x103914u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x103910u;
            // 0x103914: 0x40882d  daddu       $s1, $v0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x107DA8u;
    if (runtime->hasFunction(0x107DA8u)) {
        auto targetFn = runtime->lookupFunction(0x107DA8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x103918u; }
        if (ctx->pc != 0x103918u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00107DA8_0x107da8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x103918u; }
        if (ctx->pc != 0x103918u) { return; }
    }
    ctx->pc = 0x103918u;
label_103918:
    // 0x103918: 0x220102d  daddu       $v0, $s1, $zero
    ctx->pc = 0x103918u;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
    // 0x10391c: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x10391cu;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x103920: 0xdfb10008  ld          $s1, 0x8($sp)
    ctx->pc = 0x103920u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x103924: 0xdfb20010  ld          $s2, 0x10($sp)
    ctx->pc = 0x103924u;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x103928: 0xdfbf0018  ld          $ra, 0x18($sp)
    ctx->pc = 0x103928u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 24)));
    // 0x10392c: 0x3e00008  jr          $ra
    ctx->pc = 0x10392Cu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x103930u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x10392Cu;
            // 0x103930: 0x27bd0020  addiu       $sp, $sp, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1038FCu: goto label_1038fc;
            case 0x10390Cu: goto label_10390c;
            case 0x103918u: goto label_103918;
            default: break;
        }
        return;
    }
    ctx->pc = 0x103934u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
