#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00131D18
// Address: 0x131d18 - 0x131d98
void sub_00131D18_0x131d18(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00131D18_0x131d18");
#endif

    switch (ctx->pc) {
        case 0x131d60u: goto label_131d60;
        case 0x131d68u: goto label_131d68;
        case 0x131d74u: goto label_131d74;
        default: break;
    }

    ctx->pc = 0x131d18u;

    // 0x131d18: 0x27bdffe0  addiu       $sp, $sp, -0x20
    ctx->pc = 0x131d18u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967264));
    // 0x131d1c: 0xffb00000  sd          $s0, 0x0($sp)
    ctx->pc = 0x131d1cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x131d20: 0x80802d  daddu       $s0, $a0, $zero
    ctx->pc = 0x131d20u;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x131d24: 0xffb10008  sd          $s1, 0x8($sp)
    ctx->pc = 0x131d24u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 8), GPR_U64(ctx, 17));
    // 0x131d28: 0xa0882d  daddu       $s1, $a1, $zero
    ctx->pc = 0x131d28u;
    SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
    // 0x131d2c: 0x12000003  beqz        $s0, . + 4 + (0x3 << 2)
    ctx->pc = 0x131D2Cu;
    {
        const bool branch_taken_0x131d2c = (GPR_U64(ctx, 16) == GPR_U64(ctx, 0));
        ctx->pc = 0x131D30u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x131D2Cu;
            // 0x131d30: 0xffbf0010  sd          $ra, 0x10($sp) (Delay Slot)
        WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 31));
        ctx->in_delay_slot = false;
        if (branch_taken_0x131d2c) {
            ctx->pc = 0x131D3Cu;
            goto label_131d3c;
        }
    }
    ctx->pc = 0x131D34u;
    // 0x131d34: 0x16200008  bnez        $s1, . + 4 + (0x8 << 2)
    ctx->pc = 0x131D34u;
    {
        const bool branch_taken_0x131d34 = (GPR_U64(ctx, 17) != GPR_U64(ctx, 0));
        if (branch_taken_0x131d34) {
            ctx->pc = 0x131D58u;
            goto label_131d58;
        }
    }
    ctx->pc = 0x131D3Cu;
label_131d3c:
    // 0x131d3c: 0x3c040024  lui         $a0, 0x24
    ctx->pc = 0x131d3cu;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)36 << 16));
    // 0x131d40: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x131d40u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x131d44: 0xdfb10008  ld          $s1, 0x8($sp)
    ctx->pc = 0x131d44u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x131d48: 0x2484aef8  addiu       $a0, $a0, -0x5108
    ctx->pc = 0x131d48u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 4294946552));
    // 0x131d4c: 0xdfbf0010  ld          $ra, 0x10($sp)
    ctx->pc = 0x131d4cu;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x131d50: 0x804a034  j           func_1280D0
    ctx->pc = 0x131D50u;
    ctx->pc = 0x131D54u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x131D50u;
            // 0x131d54: 0x27bd0020  addiu       $sp, $sp, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1280D0u;
    if (runtime->hasFunction(0x1280D0u)) {
        auto targetFn = runtime->lookupFunction(0x1280D0u);
        targetFn(rdram, ctx, runtime); return;
    } else {
        sub_001280D0_0x1280d0(rdram, ctx, runtime); return;
    }
    ctx->pc = 0x131D58u;
label_131d58:
    // 0x131d58: 0xc04c78e  jal         func_131E38
    ctx->pc = 0x131D58u;
    SET_GPR_U32(ctx, 31, 0x131D60u);
    ctx->pc = 0x131E38u;
    if (runtime->hasFunction(0x131E38u)) {
        auto targetFn = runtime->lookupFunction(0x131E38u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x131D60u; }
        if (ctx->pc != 0x131D60u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00131E38_0x131e38(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x131D60u; }
        if (ctx->pc != 0x131D60u) { return; }
    }
    ctx->pc = 0x131D60u;
label_131d60:
    // 0x131d60: 0xc049938  jal         func_1264E0
    ctx->pc = 0x131D60u;
    SET_GPR_U32(ctx, 31, 0x131D68u);
    ctx->pc = 0x1264E0u;
    if (runtime->hasFunction(0x1264E0u)) {
        auto targetFn = runtime->lookupFunction(0x1264E0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x131D68u; }
        if (ctx->pc != 0x131D68u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001264E0_0x1264e0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x131D68u; }
        if (ctx->pc != 0x131D68u) { return; }
    }
    ctx->pc = 0x131D68u;
label_131d68:
    // 0x131d68: 0x200202d  daddu       $a0, $s0, $zero
    ctx->pc = 0x131d68u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x131d6c: 0xc04c6d8  jal         func_131B60
    ctx->pc = 0x131D6Cu;
    SET_GPR_U32(ctx, 31, 0x131D74u);
    ctx->pc = 0x131D70u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x131D6Cu;
            // 0x131d70: 0x220282d  daddu       $a1, $s1, $zero (Delay Slot)
        SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x131B60u;
    if (runtime->hasFunction(0x131B60u)) {
        auto targetFn = runtime->lookupFunction(0x131B60u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x131D74u; }
        if (ctx->pc != 0x131D74u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00131B60_0x131b60(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x131D74u; }
        if (ctx->pc != 0x131D74u) { return; }
    }
    ctx->pc = 0x131D74u;
label_131d74:
    // 0x131d74: 0x24020003  addiu       $v0, $zero, 0x3
    ctx->pc = 0x131d74u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 3));
    // 0x131d78: 0x24030001  addiu       $v1, $zero, 0x1
    ctx->pc = 0x131d78u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x131d7c: 0xa2020002  sb          $v0, 0x2($s0)
    ctx->pc = 0x131d7cu;
    WRITE8(ADD32(GPR_U32(ctx, 16), 2), (uint8_t)GPR_U32(ctx, 2));
    // 0x131d80: 0xa2030098  sb          $v1, 0x98($s0)
    ctx->pc = 0x131d80u;
    WRITE8(ADD32(GPR_U32(ctx, 16), 152), (uint8_t)GPR_U32(ctx, 3));
    // 0x131d84: 0xdfb10008  ld          $s1, 0x8($sp)
    ctx->pc = 0x131d84u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x131d88: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x131d88u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x131d8c: 0xdfbf0010  ld          $ra, 0x10($sp)
    ctx->pc = 0x131d8cu;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x131d90: 0x804993e  j           func_1264F8
    ctx->pc = 0x131D90u;
    ctx->pc = 0x131D94u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x131D90u;
            // 0x131d94: 0x27bd0020  addiu       $sp, $sp, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1264F8u;
    if (runtime->hasFunction(0x1264F8u)) {
        auto targetFn = runtime->lookupFunction(0x1264F8u);
        targetFn(rdram, ctx, runtime); return;
    } else {
        sub_001264F8_0x1264f8(rdram, ctx, runtime); return;
    }
    ctx->pc = 0x131D98u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
