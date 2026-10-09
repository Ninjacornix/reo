#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00109A10
// Address: 0x109a10 - 0x109a74
void sub_00109A10_0x109a10(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00109A10_0x109a10");
#endif

    switch (ctx->pc) {
        case 0x109a3cu: goto label_109a3c;
        case 0x109a4cu: goto label_109a4c;
        case 0x109a58u: goto label_109a58;
        default: break;
    }

    ctx->pc = 0x109a10u;

    // 0x109a10: 0x27bdffe0  addiu       $sp, $sp, -0x20
    ctx->pc = 0x109a10u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967264));
    // 0x109a14: 0xffb00000  sd          $s0, 0x0($sp)
    ctx->pc = 0x109a14u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x109a18: 0x3c100021  lui         $s0, 0x21
    ctx->pc = 0x109a18u;
    SET_GPR_S32(ctx, 16, (int32_t)((uint32_t)33 << 16));
    // 0x109a1c: 0xffb10008  sd          $s1, 0x8($sp)
    ctx->pc = 0x109a1cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 8), GPR_U64(ctx, 17));
    // 0x109a20: 0xa0882d  daddu       $s1, $a1, $zero
    ctx->pc = 0x109a20u;
    SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
    // 0x109a24: 0xffb20010  sd          $s2, 0x10($sp)
    ctx->pc = 0x109a24u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 18));
    // 0x109a28: 0x80902d  daddu       $s2, $a0, $zero
    ctx->pc = 0x109a28u;
    SET_GPR_U64(ctx, 18, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x109a2c: 0xffbf0018  sd          $ra, 0x18($sp)
    ctx->pc = 0x109a2cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 24), GPR_U64(ctx, 31));
    // 0x109a30: 0x261097f0  addiu       $s0, $s0, -0x6810
    ctx->pc = 0x109a30u;
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 16), 4294940656));
    // 0x109a34: 0xc041f4a  jal         func_107D28
    ctx->pc = 0x109A34u;
    SET_GPR_U32(ctx, 31, 0x109A3Cu);
    ctx->pc = 0x109A38u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x109A34u;
            // 0x109a38: 0x8e040000  lw          $a0, 0x0($s0) (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 0)));
        ctx->in_delay_slot = false;
    ctx->pc = 0x107D28u;
    if (runtime->hasFunction(0x107D28u)) {
        auto targetFn = runtime->lookupFunction(0x107D28u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x109A3Cu; }
        if (ctx->pc != 0x109A3Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00107D28_0x107d28(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x109A3Cu; }
        if (ctx->pc != 0x109A3Cu) { return; }
    }
    ctx->pc = 0x109A3Cu;
label_109a3c:
    // 0x109a3c: 0x8e040000  lw          $a0, 0x0($s0)
    ctx->pc = 0x109a3cu;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 0)));
    // 0x109a40: 0x240282d  daddu       $a1, $s2, $zero
    ctx->pc = 0x109a40u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 18) + (uint64_t)GPR_U64(ctx, 0));
    // 0x109a44: 0xc04269e  jal         func_109A78
    ctx->pc = 0x109A44u;
    SET_GPR_U32(ctx, 31, 0x109A4Cu);
    ctx->pc = 0x109A48u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x109A44u;
            // 0x109a48: 0x220302d  daddu       $a2, $s1, $zero (Delay Slot)
        SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x109A78u;
    if (runtime->hasFunction(0x109A78u)) {
        auto targetFn = runtime->lookupFunction(0x109A78u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x109A4Cu; }
        if (ctx->pc != 0x109A4Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00109A78_0x109a78(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x109A4Cu; }
        if (ctx->pc != 0x109A4Cu) { return; }
    }
    ctx->pc = 0x109A4Cu;
label_109a4c:
    // 0x109a4c: 0x8e040000  lw          $a0, 0x0($s0)
    ctx->pc = 0x109a4cu;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 0)));
    // 0x109a50: 0xc041f6a  jal         func_107DA8
    ctx->pc = 0x109A50u;
    SET_GPR_U32(ctx, 31, 0x109A58u);
    ctx->pc = 0x109A54u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x109A50u;
            // 0x109a54: 0x40882d  daddu       $s1, $v0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x107DA8u;
    if (runtime->hasFunction(0x107DA8u)) {
        auto targetFn = runtime->lookupFunction(0x107DA8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x109A58u; }
        if (ctx->pc != 0x109A58u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00107DA8_0x107da8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x109A58u; }
        if (ctx->pc != 0x109A58u) { return; }
    }
    ctx->pc = 0x109A58u;
label_109a58:
    // 0x109a58: 0x220102d  daddu       $v0, $s1, $zero
    ctx->pc = 0x109a58u;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
    // 0x109a5c: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x109a5cu;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x109a60: 0xdfb10008  ld          $s1, 0x8($sp)
    ctx->pc = 0x109a60u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x109a64: 0xdfb20010  ld          $s2, 0x10($sp)
    ctx->pc = 0x109a64u;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x109a68: 0xdfbf0018  ld          $ra, 0x18($sp)
    ctx->pc = 0x109a68u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 24)));
    // 0x109a6c: 0x3e00008  jr          $ra
    ctx->pc = 0x109A6Cu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x109A70u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x109A6Cu;
            // 0x109a70: 0x27bd0020  addiu       $sp, $sp, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x109A3Cu: goto label_109a3c;
            case 0x109A4Cu: goto label_109a4c;
            case 0x109A58u: goto label_109a58;
            default: break;
        }
        return;
    }
    ctx->pc = 0x109A74u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
