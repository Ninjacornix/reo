#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00115168
// Address: 0x115168 - 0x1151d0
void sub_00115168_0x115168(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00115168_0x115168");
#endif

    switch (ctx->pc) {
        case 0x115198u: goto label_115198;
        case 0x1151a0u: goto label_1151a0;
        case 0x1151b8u: goto label_1151b8;
        default: break;
    }

    ctx->pc = 0x115168u;

    // 0x115168: 0x27bdffd0  addiu       $sp, $sp, -0x30
    ctx->pc = 0x115168u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967248));
    // 0x11516c: 0xffb10010  sd          $s1, 0x10($sp)
    ctx->pc = 0x11516cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 17));
    // 0x115170: 0xffbf0020  sd          $ra, 0x20($sp)
    ctx->pc = 0x115170u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 32), GPR_U64(ctx, 31));
    // 0x115174: 0x80882d  daddu       $s1, $a0, $zero
    ctx->pc = 0x115174u;
    SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x115178: 0xffb00000  sd          $s0, 0x0($sp)
    ctx->pc = 0x115178u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x11517c: 0x40106000  mfc0        $s0, Status
    ctx->pc = 0x11517cu;
    SET_GPR_S32(ctx, 16, (int32_t)ctx->cop0_status);
    // 0x115180: 0x3c020001  lui         $v0, 0x1
    ctx->pc = 0x115180u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)1 << 16));
    // 0x115184: 0x2028024  and         $s0, $s0, $v0
    ctx->pc = 0x115184u;
    SET_GPR_U64(ctx, 16, GPR_U64(ctx, 16) & GPR_U64(ctx, 2));
    // 0x115188: 0x12000003  beqz        $s0, . + 4 + (0x3 << 2)
    ctx->pc = 0x115188u;
    {
        const bool branch_taken_0x115188 = (GPR_U64(ctx, 16) == GPR_U64(ctx, 0));
        if (branch_taken_0x115188) {
            ctx->pc = 0x115198u;
            goto label_115198;
        }
    }
    ctx->pc = 0x115190u;
    // 0x115190: 0xc047598  jal         func_11D660
    ctx->pc = 0x115190u;
    SET_GPR_U32(ctx, 31, 0x115198u);
    ctx->pc = 0x11D660u;
    if (runtime->hasFunction(0x11D660u)) {
        auto targetFn = runtime->lookupFunction(0x11D660u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x115198u; }
        if (ctx->pc != 0x115198u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0011D660_0x11d660(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x115198u; }
        if (ctx->pc != 0x115198u) { return; }
    }
    ctx->pc = 0x115198u;
label_115198:
    // 0x115198: 0xc0450d8  jal         func_114360
    ctx->pc = 0x115198u;
    SET_GPR_U32(ctx, 31, 0x1151A0u);
    ctx->pc = 0x11519Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x115198u;
            // 0x11519c: 0x220202d  daddu       $a0, $s1, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x114360u;
    if (runtime->hasFunction(0x114360u)) {
        auto targetFn = runtime->lookupFunction(0x114360u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1151A0u; }
        if (ctx->pc != 0x1151A0u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00114360_0x114360(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1151A0u; }
        if (ctx->pc != 0x1151A0u) { return; }
    }
    ctx->pc = 0x1151A0u;
label_1151a0:
    // 0x1151a0: 0x40882d  daddu       $s1, $v0, $zero
    ctx->pc = 0x1151a0u;
    SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1151a4: 0xf  sync
    ctx->pc = 0x1151a4u;
    // SYNC instruction - memory barrier
// In recompiled code, we don't need explicit memory barriers
    // 0x1151a8: 0x12000004  beqz        $s0, . + 4 + (0x4 << 2)
    ctx->pc = 0x1151A8u;
    {
        const bool branch_taken_0x1151a8 = (GPR_U64(ctx, 16) == GPR_U64(ctx, 0));
        ctx->pc = 0x1151ACu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1151A8u;
            // 0x1151ac: 0x220102d  daddu       $v0, $s1, $zero (Delay Slot)
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1151a8) {
            ctx->pc = 0x1151BCu;
            goto label_1151bc;
        }
    }
    ctx->pc = 0x1151B0u;
    // 0x1151b0: 0xc0475ae  jal         func_11D6B8
    ctx->pc = 0x1151B0u;
    SET_GPR_U32(ctx, 31, 0x1151B8u);
    ctx->pc = 0x11D6B8u;
    if (runtime->hasFunction(0x11D6B8u)) {
        auto targetFn = runtime->lookupFunction(0x11D6B8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1151B8u; }
        if (ctx->pc != 0x1151B8u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0011D6B8_0x11d6b8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1151B8u; }
        if (ctx->pc != 0x1151B8u) { return; }
    }
    ctx->pc = 0x1151B8u;
label_1151b8:
    // 0x1151b8: 0x220102d  daddu       $v0, $s1, $zero
    ctx->pc = 0x1151b8u;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
label_1151bc:
    // 0x1151bc: 0xdfbf0020  ld          $ra, 0x20($sp)
    ctx->pc = 0x1151bcu;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x1151c0: 0xdfb10010  ld          $s1, 0x10($sp)
    ctx->pc = 0x1151c0u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x1151c4: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x1151c4u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1151c8: 0x3e00008  jr          $ra
    ctx->pc = 0x1151C8u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1151CCu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1151C8u;
            // 0x1151cc: 0x27bd0030  addiu       $sp, $sp, 0x30 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 48));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x115198u: goto label_115198;
            case 0x1151A0u: goto label_1151a0;
            case 0x1151B8u: goto label_1151b8;
            case 0x1151BCu: goto label_1151bc;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1151D0u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
