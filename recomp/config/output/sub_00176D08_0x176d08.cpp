#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00176D08
// Address: 0x176d08 - 0x176d68
void sub_00176D08_0x176d08(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00176D08_0x176d08");
#endif

    switch (ctx->pc) {
        case 0x176d38u: goto label_176d38;
        case 0x176d48u: goto label_176d48;
        case 0x176d58u: goto label_176d58;
        default: break;
    }

    ctx->pc = 0x176d08u;

    // 0x176d08: 0x27bdffe0  addiu       $sp, $sp, -0x20
    ctx->pc = 0x176d08u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967264));
    // 0x176d0c: 0x2ca20002  sltiu       $v0, $a1, 0x2
    ctx->pc = 0x176d0cu;
    SET_GPR_U64(ctx, 2, ((uint64_t)GPR_U64(ctx, 5) < (uint64_t)(int64_t)(int32_t)2) ? 1 : 0);
    // 0x176d10: 0xffb00010  sd          $s0, 0x10($sp)
    ctx->pc = 0x176d10u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 16));
    // 0x176d14: 0x80802d  daddu       $s0, $a0, $zero
    ctx->pc = 0x176d14u;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x176d18: 0x1440000f  bnez        $v0, . + 4 + (0xF << 2)
    ctx->pc = 0x176D18u;
    {
        const bool branch_taken_0x176d18 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x176D1Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x176D18u;
            // 0x176d1c: 0xffbf0018  sd          $ra, 0x18($sp) (Delay Slot)
        WRITE64(ADD32(GPR_U32(ctx, 29), 24), GPR_U64(ctx, 31));
        ctx->in_delay_slot = false;
        if (branch_taken_0x176d18) {
            ctx->pc = 0x176D58u;
            goto label_176d58;
        }
    }
    ctx->pc = 0x176D20u;
    // 0x176d20: 0x24020002  addiu       $v0, $zero, 0x2
    ctx->pc = 0x176d20u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 2));
    // 0x176d24: 0x54a2000d  bnel        $a1, $v0, . + 4 + (0xD << 2)
    ctx->pc = 0x176D24u;
    {
        const bool branch_taken_0x176d24 = (GPR_U64(ctx, 5) != GPR_U64(ctx, 2));
        if (branch_taken_0x176d24) {
            ctx->pc = 0x176D28u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x176D24u;
            // 0x176d28: 0xdfb00010  ld          $s0, 0x10($sp) (Delay Slot)
        SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 16)));
        ctx->in_delay_slot = false;
            ctx->pc = 0x176D5Cu;
            goto label_176d5c;
        }
    }
    ctx->pc = 0x176D2Cu;
    // 0x176d2c: 0x3a0282d  daddu       $a1, $sp, $zero
    ctx->pc = 0x176d2cu;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 29) + (uint64_t)GPR_U64(ctx, 0));
    // 0x176d30: 0xc05db7a  jal         func_176DE8
    ctx->pc = 0x176D30u;
    SET_GPR_U32(ctx, 31, 0x176D38u);
    ctx->pc = 0x176D34u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x176D30u;
            // 0x176d34: 0x27a60004  addiu       $a2, $sp, 0x4 (Delay Slot)
        SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 29), 4));
        ctx->in_delay_slot = false;
    ctx->pc = 0x176DE8u;
    if (runtime->hasFunction(0x176DE8u)) {
        auto targetFn = runtime->lookupFunction(0x176DE8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x176D38u; }
        if (ctx->pc != 0x176D38u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00176DE8_0x176de8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x176D38u; }
        if (ctx->pc != 0x176D38u) { return; }
    }
    ctx->pc = 0x176D38u;
label_176d38:
    // 0x176d38: 0x200202d  daddu       $a0, $s0, $zero
    ctx->pc = 0x176d38u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x176d3c: 0x8fa50000  lw          $a1, 0x0($sp)
    ctx->pc = 0x176d3cu;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x176d40: 0xc05db5a  jal         func_176D68
    ctx->pc = 0x176D40u;
    SET_GPR_U32(ctx, 31, 0x176D48u);
    ctx->pc = 0x176D44u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x176D40u;
            // 0x176d44: 0x8fa60004  lw          $a2, 0x4($sp) (Delay Slot)
        SET_GPR_S32(ctx, 6, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 4)));
        ctx->in_delay_slot = false;
    ctx->pc = 0x176D68u;
    if (runtime->hasFunction(0x176D68u)) {
        auto targetFn = runtime->lookupFunction(0x176D68u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x176D48u; }
        if (ctx->pc != 0x176D48u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00176D68_0x176d68(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x176D48u; }
        if (ctx->pc != 0x176D48u) { return; }
    }
    ctx->pc = 0x176D48u;
label_176d48:
    // 0x176d48: 0x200202d  daddu       $a0, $s0, $zero
    ctx->pc = 0x176d48u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x176d4c: 0x8fa50000  lw          $a1, 0x0($sp)
    ctx->pc = 0x176d4cu;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x176d50: 0xc05db6c  jal         func_176DB0
    ctx->pc = 0x176D50u;
    SET_GPR_U32(ctx, 31, 0x176D58u);
    ctx->pc = 0x176D54u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x176D50u;
            // 0x176d54: 0x8fa60004  lw          $a2, 0x4($sp) (Delay Slot)
        SET_GPR_S32(ctx, 6, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 4)));
        ctx->in_delay_slot = false;
    ctx->pc = 0x176DB0u;
    if (runtime->hasFunction(0x176DB0u)) {
        auto targetFn = runtime->lookupFunction(0x176DB0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x176D58u; }
        if (ctx->pc != 0x176D58u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00176DB0_0x176db0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x176D58u; }
        if (ctx->pc != 0x176D58u) { return; }
    }
    ctx->pc = 0x176D58u;
label_176d58:
    // 0x176d58: 0xdfb00010  ld          $s0, 0x10($sp)
    ctx->pc = 0x176d58u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 16)));
label_176d5c:
    // 0x176d5c: 0xdfbf0018  ld          $ra, 0x18($sp)
    ctx->pc = 0x176d5cu;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 24)));
    // 0x176d60: 0x3e00008  jr          $ra
    ctx->pc = 0x176D60u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x176D64u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x176D60u;
            // 0x176d64: 0x27bd0020  addiu       $sp, $sp, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x176D38u: goto label_176d38;
            case 0x176D48u: goto label_176d48;
            case 0x176D58u: goto label_176d58;
            case 0x176D5Cu: goto label_176d5c;
            default: break;
        }
        return;
    }
    ctx->pc = 0x176D68u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
