#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00178A30
// Address: 0x178a30 - 0x178a74
void sub_00178A30_0x178a30(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00178A30_0x178a30");
#endif

    switch (ctx->pc) {
        case 0x178a48u: goto label_178a48;
        case 0x178a50u: goto label_178a50;
        case 0x178a5cu: goto label_178a5c;
        default: break;
    }

    ctx->pc = 0x178a30u;

    // 0x178a30: 0x27bdffe0  addiu       $sp, $sp, -0x20
    ctx->pc = 0x178a30u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967264));
    // 0x178a34: 0xffb10008  sd          $s1, 0x8($sp)
    ctx->pc = 0x178a34u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 8), GPR_U64(ctx, 17));
    // 0x178a38: 0xffb00000  sd          $s0, 0x0($sp)
    ctx->pc = 0x178a38u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x178a3c: 0xffbf0010  sd          $ra, 0x10($sp)
    ctx->pc = 0x178a3cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 31));
    // 0x178a40: 0xc05e29e  jal         func_178A78
    ctx->pc = 0x178A40u;
    SET_GPR_U32(ctx, 31, 0x178A48u);
    ctx->pc = 0x178A44u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x178A40u;
            // 0x178a44: 0x80882d  daddu       $s1, $a0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x178A78u;
    if (runtime->hasFunction(0x178A78u)) {
        auto targetFn = runtime->lookupFunction(0x178A78u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x178A48u; }
        if (ctx->pc != 0x178A48u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00178A78_0x178a78(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x178A48u; }
        if (ctx->pc != 0x178A48u) { return; }
    }
    ctx->pc = 0x178A48u;
label_178a48:
    // 0x178a48: 0xc05e2e2  jal         func_178B88
    ctx->pc = 0x178A48u;
    SET_GPR_U32(ctx, 31, 0x178A50u);
    ctx->pc = 0x178A4Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x178A48u;
            // 0x178a4c: 0x220202d  daddu       $a0, $s1, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x178B88u;
    if (runtime->hasFunction(0x178B88u)) {
        auto targetFn = runtime->lookupFunction(0x178B88u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x178A50u; }
        if (ctx->pc != 0x178A50u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00178B88_0x178b88(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x178A50u; }
        if (ctx->pc != 0x178A50u) { return; }
    }
    ctx->pc = 0x178A50u;
label_178a50:
    // 0x178a50: 0x220202d  daddu       $a0, $s1, $zero
    ctx->pc = 0x178a50u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
    // 0x178a54: 0xc05e2c0  jal         func_178B00
    ctx->pc = 0x178A54u;
    SET_GPR_U32(ctx, 31, 0x178A5Cu);
    ctx->pc = 0x178A58u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x178A54u;
            // 0x178a58: 0x40802d  daddu       $s0, $v0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x178B00u;
    if (runtime->hasFunction(0x178B00u)) {
        auto targetFn = runtime->lookupFunction(0x178B00u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x178A5Cu; }
        if (ctx->pc != 0x178A5Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00178B00_0x178b00(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x178A5Cu; }
        if (ctx->pc != 0x178A5Cu) { return; }
    }
    ctx->pc = 0x178A5Cu;
label_178a5c:
    // 0x178a5c: 0xdfb10008  ld          $s1, 0x8($sp)
    ctx->pc = 0x178a5cu;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x178a60: 0x200102d  daddu       $v0, $s0, $zero
    ctx->pc = 0x178a60u;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x178a64: 0xdfbf0010  ld          $ra, 0x10($sp)
    ctx->pc = 0x178a64u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x178a68: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x178a68u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x178a6c: 0x3e00008  jr          $ra
    ctx->pc = 0x178A6Cu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x178A70u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x178A6Cu;
            // 0x178a70: 0x27bd0020  addiu       $sp, $sp, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x178A48u: goto label_178a48;
            case 0x178A50u: goto label_178a50;
            case 0x178A5Cu: goto label_178a5c;
            default: break;
        }
        return;
    }
    ctx->pc = 0x178A74u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
