#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00178D38
// Address: 0x178d38 - 0x178d90
void sub_00178D38_0x178d38(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00178D38_0x178d38");
#endif

    switch (ctx->pc) {
        case 0x178d54u: goto label_178d54;
        case 0x178d64u: goto label_178d64;
        case 0x178d6cu: goto label_178d6c;
        case 0x178d78u: goto label_178d78;
        default: break;
    }

    ctx->pc = 0x178d38u;

    // 0x178d38: 0x27bdffe0  addiu       $sp, $sp, -0x20
    ctx->pc = 0x178d38u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967264));
    // 0x178d3c: 0x24050005  addiu       $a1, $zero, 0x5
    ctx->pc = 0x178d3cu;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 5));
    // 0x178d40: 0xffb10008  sd          $s1, 0x8($sp)
    ctx->pc = 0x178d40u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 8), GPR_U64(ctx, 17));
    // 0x178d44: 0xffb00000  sd          $s0, 0x0($sp)
    ctx->pc = 0x178d44u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x178d48: 0xffbf0010  sd          $ra, 0x10($sp)
    ctx->pc = 0x178d48u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 31));
    // 0x178d4c: 0xc05d58a  jal         func_175628
    ctx->pc = 0x178D4Cu;
    SET_GPR_U32(ctx, 31, 0x178D54u);
    ctx->pc = 0x178D50u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x178D4Cu;
            // 0x178d50: 0x80882d  daddu       $s1, $a0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x175628u;
    if (runtime->hasFunction(0x175628u)) {
        auto targetFn = runtime->lookupFunction(0x175628u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x178D54u; }
        if (ctx->pc != 0x178D54u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00175628_0x175628(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x178D54u; }
        if (ctx->pc != 0x178D54u) { return; }
    }
    ctx->pc = 0x178D54u;
label_178d54:
    // 0x178d54: 0x10400009  beqz        $v0, . + 4 + (0x9 << 2)
    ctx->pc = 0x178D54u;
    {
        const bool branch_taken_0x178d54 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x178D58u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x178D54u;
            // 0x178d58: 0x220202d  daddu       $a0, $s1, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x178d54) {
            ctx->pc = 0x178D7Cu;
            goto label_178d7c;
        }
    }
    ctx->pc = 0x178D5Cu;
    // 0x178d5c: 0xc05e364  jal         func_178D90
    ctx->pc = 0x178D5Cu;
    SET_GPR_U32(ctx, 31, 0x178D64u);
    ctx->pc = 0x178D90u;
    if (runtime->hasFunction(0x178D90u)) {
        auto targetFn = runtime->lookupFunction(0x178D90u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x178D64u; }
        if (ctx->pc != 0x178D64u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00178D90_0x178d90(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x178D64u; }
        if (ctx->pc != 0x178D64u) { return; }
    }
    ctx->pc = 0x178D64u;
label_178d64:
    // 0x178d64: 0xc05e3b8  jal         func_178EE0
    ctx->pc = 0x178D64u;
    SET_GPR_U32(ctx, 31, 0x178D6Cu);
    ctx->pc = 0x178D68u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x178D64u;
            // 0x178d68: 0x220202d  daddu       $a0, $s1, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x178EE0u;
    if (runtime->hasFunction(0x178EE0u)) {
        auto targetFn = runtime->lookupFunction(0x178EE0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x178D6Cu; }
        if (ctx->pc != 0x178D6Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00178EE0_0x178ee0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x178D6Cu; }
        if (ctx->pc != 0x178D6Cu) { return; }
    }
    ctx->pc = 0x178D6Cu;
label_178d6c:
    // 0x178d6c: 0x220202d  daddu       $a0, $s1, $zero
    ctx->pc = 0x178d6cu;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
    // 0x178d70: 0xc05e396  jal         func_178E58
    ctx->pc = 0x178D70u;
    SET_GPR_U32(ctx, 31, 0x178D78u);
    ctx->pc = 0x178D74u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x178D70u;
            // 0x178d74: 0x40802d  daddu       $s0, $v0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x178E58u;
    if (runtime->hasFunction(0x178E58u)) {
        auto targetFn = runtime->lookupFunction(0x178E58u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x178D78u; }
        if (ctx->pc != 0x178D78u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00178E58_0x178e58(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x178D78u; }
        if (ctx->pc != 0x178D78u) { return; }
    }
    ctx->pc = 0x178D78u;
label_178d78:
    // 0x178d78: 0x200102d  daddu       $v0, $s0, $zero
    ctx->pc = 0x178d78u;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
label_178d7c:
    // 0x178d7c: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x178d7cu;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x178d80: 0xdfb10008  ld          $s1, 0x8($sp)
    ctx->pc = 0x178d80u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x178d84: 0xdfbf0010  ld          $ra, 0x10($sp)
    ctx->pc = 0x178d84u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x178d88: 0x3e00008  jr          $ra
    ctx->pc = 0x178D88u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x178D8Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x178D88u;
            // 0x178d8c: 0x27bd0020  addiu       $sp, $sp, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x178D54u: goto label_178d54;
            case 0x178D64u: goto label_178d64;
            case 0x178D6Cu: goto label_178d6c;
            case 0x178D78u: goto label_178d78;
            case 0x178D7Cu: goto label_178d7c;
            default: break;
        }
        return;
    }
    ctx->pc = 0x178D90u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
