#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00114F18
// Address: 0x114f18 - 0x114fb0
void sub_00114F18_0x114f18(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00114F18_0x114f18");
#endif

    switch (ctx->pc) {
        case 0x114f50u: goto label_114f50;
        case 0x114f64u: goto label_114f64;
        default: break;
    }

    ctx->pc = 0x114f18u;

    // 0x114f18: 0x27bdffc0  addiu       $sp, $sp, -0x40
    ctx->pc = 0x114f18u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967232));
    // 0x114f1c: 0xffb20020  sd          $s2, 0x20($sp)
    ctx->pc = 0x114f1cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 32), GPR_U64(ctx, 18));
    // 0x114f20: 0xffb10010  sd          $s1, 0x10($sp)
    ctx->pc = 0x114f20u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 17));
    // 0x114f24: 0x80902d  daddu       $s2, $a0, $zero
    ctx->pc = 0x114f24u;
    SET_GPR_U64(ctx, 18, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x114f28: 0xffbf0030  sd          $ra, 0x30($sp)
    ctx->pc = 0x114f28u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 48), GPR_U64(ctx, 31));
    // 0x114f2c: 0xa0882d  daddu       $s1, $a1, $zero
    ctx->pc = 0x114f2cu;
    SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
    // 0x114f30: 0xffb00000  sd          $s0, 0x0($sp)
    ctx->pc = 0x114f30u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x114f34: 0x40106000  mfc0        $s0, Status
    ctx->pc = 0x114f34u;
    SET_GPR_S32(ctx, 16, (int32_t)ctx->cop0_status);
    // 0x114f38: 0x3c020001  lui         $v0, 0x1
    ctx->pc = 0x114f38u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)1 << 16));
    // 0x114f3c: 0x2028024  and         $s0, $s0, $v0
    ctx->pc = 0x114f3cu;
    SET_GPR_U64(ctx, 16, GPR_U64(ctx, 16) & GPR_U64(ctx, 2));
    // 0x114f40: 0x12000003  beqz        $s0, . + 4 + (0x3 << 2)
    ctx->pc = 0x114F40u;
    {
        const bool branch_taken_0x114f40 = (GPR_U64(ctx, 16) == GPR_U64(ctx, 0));
        if (branch_taken_0x114f40) {
            ctx->pc = 0x114F50u;
            goto label_114f50;
        }
    }
    ctx->pc = 0x114F48u;
    // 0x114f48: 0xc047598  jal         func_11D660
    ctx->pc = 0x114F48u;
    SET_GPR_U32(ctx, 31, 0x114F50u);
    ctx->pc = 0x11D660u;
    if (runtime->hasFunction(0x11D660u)) {
        auto targetFn = runtime->lookupFunction(0x11D660u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x114F50u; }
        if (ctx->pc != 0x114F50u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0011D660_0x11d660(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x114F50u; }
        if (ctx->pc != 0x114F50u) { return; }
    }
    ctx->pc = 0x114F50u;
label_114f50:
    // 0x114f50: 0x3c04ffff  lui         $a0, 0xFFFF
    ctx->pc = 0x114f50u;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)65535 << 16));
    // 0x114f54: 0x3484ffc0  ori         $a0, $a0, 0xFFC0
    ctx->pc = 0x114f54u;
    SET_GPR_U64(ctx, 4, GPR_U64(ctx, 4) | (uint64_t)(uint16_t)65472);
    // 0x114f58: 0x2242824  and         $a1, $s1, $a0
    ctx->pc = 0x114f58u;
    SET_GPR_U64(ctx, 5, GPR_U64(ctx, 17) & GPR_U64(ctx, 4));
    // 0x114f5c: 0xc04539c  jal         func_114E70
    ctx->pc = 0x114F5Cu;
    SET_GPR_U32(ctx, 31, 0x114F64u);
    ctx->pc = 0x114F60u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x114F5Cu;
            // 0x114f60: 0x2442024  and         $a0, $s2, $a0 (Delay Slot)
        SET_GPR_U64(ctx, 4, GPR_U64(ctx, 18) & GPR_U64(ctx, 4));
        ctx->in_delay_slot = false;
    ctx->pc = 0x114E70u;
    if (runtime->hasFunction(0x114E70u)) {
        auto targetFn = runtime->lookupFunction(0x114E70u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x114F64u; }
        if (ctx->pc != 0x114F64u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00114E70_0x114e70(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x114F64u; }
        if (ctx->pc != 0x114F64u) { return; }
    }
    ctx->pc = 0x114F64u;
label_114f64:
    // 0x114f64: 0x12000006  beqz        $s0, . + 4 + (0x6 << 2)
    ctx->pc = 0x114F64u;
    {
        const bool branch_taken_0x114f64 = (GPR_U64(ctx, 16) == GPR_U64(ctx, 0));
        ctx->pc = 0x114F68u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x114F64u;
            // 0x114f68: 0xdfbf0030  ld          $ra, 0x30($sp) (Delay Slot)
        SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 48)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x114f64) {
            ctx->pc = 0x114F80u;
            goto label_114f80;
        }
    }
    ctx->pc = 0x114F6Cu;
    // 0x114f6c: 0xdfb20020  ld          $s2, 0x20($sp)
    ctx->pc = 0x114f6cu;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x114f70: 0xdfb10010  ld          $s1, 0x10($sp)
    ctx->pc = 0x114f70u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x114f74: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x114f74u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x114f78: 0x80475ae  j           func_11D6B8
    ctx->pc = 0x114F78u;
    ctx->pc = 0x114F7Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x114F78u;
            // 0x114f7c: 0x27bd0040  addiu       $sp, $sp, 0x40 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 64));
        ctx->in_delay_slot = false;
    ctx->pc = 0x11D6B8u;
    if (runtime->hasFunction(0x11D6B8u)) {
        auto targetFn = runtime->lookupFunction(0x11D6B8u);
        targetFn(rdram, ctx, runtime); return;
    } else {
        sub_0011D6B8_0x11d6b8(rdram, ctx, runtime); return;
    }
    ctx->pc = 0x114F80u;
label_114f80:
    // 0x114f80: 0xdfb20020  ld          $s2, 0x20($sp)
    ctx->pc = 0x114f80u;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x114f84: 0xdfb10010  ld          $s1, 0x10($sp)
    ctx->pc = 0x114f84u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x114f88: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x114f88u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x114f8c: 0x3e00008  jr          $ra
    ctx->pc = 0x114F8Cu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x114F90u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x114F8Cu;
            // 0x114f90: 0x27bd0040  addiu       $sp, $sp, 0x40 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 64));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x114F50u: goto label_114f50;
            case 0x114F64u: goto label_114f64;
            case 0x114F80u: goto label_114f80;
            default: break;
        }
        return;
    }
    ctx->pc = 0x114F94u;
    // 0x114f94: 0x0  nop
    ctx->pc = 0x114f94u;
    // NOP
    // 0x114f98: 0x3c02ffff  lui         $v0, 0xFFFF
    ctx->pc = 0x114f98u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)65535 << 16));
    // 0x114f9c: 0x3442ffc0  ori         $v0, $v0, 0xFFC0
    ctx->pc = 0x114f9cu;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) | (uint64_t)(uint16_t)65472);
    // 0x114fa0: 0xa22824  and         $a1, $a1, $v0
    ctx->pc = 0x114fa0u;
    SET_GPR_U64(ctx, 5, GPR_U64(ctx, 5) & GPR_U64(ctx, 2));
    // 0x114fa4: 0x804539c  j           func_114E70
    ctx->pc = 0x114FA4u;
    ctx->pc = 0x114FA8u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x114FA4u;
            // 0x114fa8: 0x822024  and         $a0, $a0, $v0 (Delay Slot)
        SET_GPR_U64(ctx, 4, GPR_U64(ctx, 4) & GPR_U64(ctx, 2));
        ctx->in_delay_slot = false;
    ctx->pc = 0x114E70u;
    if (runtime->hasFunction(0x114E70u)) {
        auto targetFn = runtime->lookupFunction(0x114E70u);
        targetFn(rdram, ctx, runtime); return;
    } else {
        sub_00114E70_0x114e70(rdram, ctx, runtime); return;
    }
    ctx->pc = 0x114FACu;
    // 0x114fac: 0x0  nop
    ctx->pc = 0x114facu;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
