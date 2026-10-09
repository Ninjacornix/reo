#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00145F50
// Address: 0x145f50 - 0x146140
void sub_00145F50_0x145f50(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00145F50_0x145f50");
#endif

    switch (ctx->pc) {
        case 0x145f68u: goto label_145f68;
        case 0x145f78u: goto label_145f78;
        case 0x145f88u: goto label_145f88;
        case 0x145f98u: goto label_145f98;
        case 0x145fa8u: goto label_145fa8;
        case 0x145fd8u: goto label_145fd8;
        case 0x145ff8u: goto label_145ff8;
        case 0x146008u: goto label_146008;
        case 0x146018u: goto label_146018;
        case 0x146028u: goto label_146028;
        case 0x146058u: goto label_146058;
        case 0x146088u: goto label_146088;
        case 0x1460b8u: goto label_1460b8;
        case 0x1460c8u: goto label_1460c8;
        case 0x1460d4u: goto label_1460d4;
        case 0x1460e4u: goto label_1460e4;
        case 0x1460f8u: goto label_1460f8;
        case 0x146104u: goto label_146104;
        case 0x146110u: goto label_146110;
        case 0x14611cu: goto label_14611c;
        default: break;
    }

    ctx->pc = 0x145f50u;

    // 0x145f50: 0x27bdffe0  addiu       $sp, $sp, -0x20
    ctx->pc = 0x145f50u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967264));
    // 0x145f54: 0x24050004  addiu       $a1, $zero, 0x4
    ctx->pc = 0x145f54u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 4));
    // 0x145f58: 0xffb00000  sd          $s0, 0x0($sp)
    ctx->pc = 0x145f58u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x145f5c: 0xffbf0010  sd          $ra, 0x10($sp)
    ctx->pc = 0x145f5cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 31));
    // 0x145f60: 0xc05167a  jal         func_1459E8
    ctx->pc = 0x145F60u;
    SET_GPR_U32(ctx, 31, 0x145F68u);
    ctx->pc = 0x145F64u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x145F60u;
            // 0x145f64: 0x80802d  daddu       $s0, $a0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1459E8u;
    if (runtime->hasFunction(0x1459E8u)) {
        auto targetFn = runtime->lookupFunction(0x1459E8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x145F68u; }
        if (ctx->pc != 0x145F68u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001459E8_0x1459e8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x145F68u; }
        if (ctx->pc != 0x145F68u) { return; }
    }
    ctx->pc = 0x145F68u;
label_145f68:
    // 0x145f68: 0xae02017c  sw          $v0, 0x17C($s0)
    ctx->pc = 0x145f68u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 380), GPR_U32(ctx, 2));
    // 0x145f6c: 0x200202d  daddu       $a0, $s0, $zero
    ctx->pc = 0x145f6cu;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x145f70: 0xc05167a  jal         func_1459E8
    ctx->pc = 0x145F70u;
    SET_GPR_U32(ctx, 31, 0x145F78u);
    ctx->pc = 0x145F74u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x145F70u;
            // 0x145f74: 0x24050004  addiu       $a1, $zero, 0x4 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 4));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1459E8u;
    if (runtime->hasFunction(0x1459E8u)) {
        auto targetFn = runtime->lookupFunction(0x1459E8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x145F78u; }
        if (ctx->pc != 0x145F78u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001459E8_0x1459e8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x145F78u; }
        if (ctx->pc != 0x145F78u) { return; }
    }
    ctx->pc = 0x145F78u;
label_145f78:
    // 0x145f78: 0xae020180  sw          $v0, 0x180($s0)
    ctx->pc = 0x145f78u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 384), GPR_U32(ctx, 2));
    // 0x145f7c: 0x200202d  daddu       $a0, $s0, $zero
    ctx->pc = 0x145f7cu;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x145f80: 0xc05167a  jal         func_1459E8
    ctx->pc = 0x145F80u;
    SET_GPR_U32(ctx, 31, 0x145F88u);
    ctx->pc = 0x145F84u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x145F80u;
            // 0x145f84: 0x24050004  addiu       $a1, $zero, 0x4 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 4));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1459E8u;
    if (runtime->hasFunction(0x1459E8u)) {
        auto targetFn = runtime->lookupFunction(0x1459E8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x145F88u; }
        if (ctx->pc != 0x145F88u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001459E8_0x1459e8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x145F88u; }
        if (ctx->pc != 0x145F88u) { return; }
    }
    ctx->pc = 0x145F88u;
label_145f88:
    // 0x145f88: 0xae020184  sw          $v0, 0x184($s0)
    ctx->pc = 0x145f88u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 388), GPR_U32(ctx, 2));
    // 0x145f8c: 0x200202d  daddu       $a0, $s0, $zero
    ctx->pc = 0x145f8cu;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x145f90: 0xc05167a  jal         func_1459E8
    ctx->pc = 0x145F90u;
    SET_GPR_U32(ctx, 31, 0x145F98u);
    ctx->pc = 0x145F94u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x145F90u;
            // 0x145f94: 0x24050004  addiu       $a1, $zero, 0x4 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 4));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1459E8u;
    if (runtime->hasFunction(0x1459E8u)) {
        auto targetFn = runtime->lookupFunction(0x1459E8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x145F98u; }
        if (ctx->pc != 0x145F98u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001459E8_0x1459e8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x145F98u; }
        if (ctx->pc != 0x145F98u) { return; }
    }
    ctx->pc = 0x145F98u;
label_145f98:
    // 0x145f98: 0xae020188  sw          $v0, 0x188($s0)
    ctx->pc = 0x145f98u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 392), GPR_U32(ctx, 2));
    // 0x145f9c: 0x200202d  daddu       $a0, $s0, $zero
    ctx->pc = 0x145f9cu;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x145fa0: 0xc05167a  jal         func_1459E8
    ctx->pc = 0x145FA0u;
    SET_GPR_U32(ctx, 31, 0x145FA8u);
    ctx->pc = 0x145FA4u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x145FA0u;
            // 0x145fa4: 0x24050002  addiu       $a1, $zero, 0x2 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 2));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1459E8u;
    if (runtime->hasFunction(0x1459E8u)) {
        auto targetFn = runtime->lookupFunction(0x1459E8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x145FA8u; }
        if (ctx->pc != 0x145FA8u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001459E8_0x1459e8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x145FA8u; }
        if (ctx->pc != 0x145FA8u) { return; }
    }
    ctx->pc = 0x145FA8u;
label_145fa8:
    // 0x145fa8: 0x3c071000  lui         $a3, 0x1000
    ctx->pc = 0x145fa8u;
    SET_GPR_S32(ctx, 7, (int32_t)((uint32_t)4096 << 16));
    // 0x145fac: 0x3c06fffc  lui         $a2, 0xFFFC
    ctx->pc = 0x145facu;
    SET_GPR_S32(ctx, 6, (int32_t)((uint32_t)65532 << 16));
    // 0x145fb0: 0x34e72010  ori         $a3, $a3, 0x2010
    ctx->pc = 0x145fb0u;
    SET_GPR_U64(ctx, 7, GPR_U64(ctx, 7) | (uint64_t)(uint16_t)8208);
    // 0x145fb4: 0x34c6ffff  ori         $a2, $a2, 0xFFFF
    ctx->pc = 0x145fb4u;
    SET_GPR_U64(ctx, 6, GPR_U64(ctx, 6) | (uint64_t)(uint16_t)65535);
    // 0x145fb8: 0x8ce30000  lw          $v1, 0x0($a3)
    ctx->pc = 0x145fb8u;
    SET_GPR_S32(ctx, 3, (int32_t)runtime->Load32(rdram, ctx, ADD32(GPR_U32(ctx, 7), 0))); // MMIO: 0x10000000
    // 0x145fbc: 0x21400  sll         $v0, $v0, 16
    ctx->pc = 0x145fbcu;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 2), 16));
    // 0x145fc0: 0x200202d  daddu       $a0, $s0, $zero
    ctx->pc = 0x145fc0u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x145fc4: 0x24050002  addiu       $a1, $zero, 0x2
    ctx->pc = 0x145fc4u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 2));
    // 0x145fc8: 0x661824  and         $v1, $v1, $a2
    ctx->pc = 0x145fc8u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) & GPR_U64(ctx, 6));
    // 0x145fcc: 0x621825  or          $v1, $v1, $v0
    ctx->pc = 0x145fccu;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) | GPR_U64(ctx, 2));
    // 0x145fd0: 0xc05167a  jal         func_1459E8
    ctx->pc = 0x145FD0u;
    SET_GPR_U32(ctx, 31, 0x145FD8u);
    ctx->pc = 0x145FD4u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x145FD0u;
            // 0x145fd4: 0xace30000  sw          $v1, 0x0($a3) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 7), 0), GPR_U32(ctx, 3));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1459E8u;
    if (runtime->hasFunction(0x1459E8u)) {
        auto targetFn = runtime->lookupFunction(0x1459E8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x145FD8u; }
        if (ctx->pc != 0x145FD8u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001459E8_0x1459e8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x145FD8u; }
        if (ctx->pc != 0x145FD8u) { return; }
    }
    ctx->pc = 0x145FD8u;
label_145fd8:
    // 0x145fd8: 0x40182d  daddu       $v1, $v0, $zero
    ctx->pc = 0x145fd8u;
    SET_GPR_U64(ctx, 3, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x145fdc: 0x8e0200ec  lw          $v0, 0xEC($s0)
    ctx->pc = 0x145fdcu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 236)));
    // 0x145fe0: 0x14400002  bnez        $v0, . + 4 + (0x2 << 2)
    ctx->pc = 0x145FE0u;
    {
        const bool branch_taken_0x145fe0 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x145FE4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x145FE0u;
            // 0x145fe4: 0xae03018c  sw          $v1, 0x18C($s0) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 16), 396), GPR_U32(ctx, 3));
        ctx->in_delay_slot = false;
        if (branch_taken_0x145fe0) {
            ctx->pc = 0x145FECu;
            goto label_145fec;
        }
    }
    ctx->pc = 0x145FE8u;
    // 0x145fe8: 0xae0300ec  sw          $v1, 0xEC($s0)
    ctx->pc = 0x145fe8u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 236), GPR_U32(ctx, 3));
label_145fec:
    // 0x145fec: 0x200202d  daddu       $a0, $s0, $zero
    ctx->pc = 0x145fecu;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x145ff0: 0xc05167a  jal         func_1459E8
    ctx->pc = 0x145FF0u;
    SET_GPR_U32(ctx, 31, 0x145FF8u);
    ctx->pc = 0x145FF4u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x145FF0u;
            // 0x145ff4: 0x24050001  addiu       $a1, $zero, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1459E8u;
    if (runtime->hasFunction(0x1459E8u)) {
        auto targetFn = runtime->lookupFunction(0x1459E8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x145FF8u; }
        if (ctx->pc != 0x145FF8u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001459E8_0x1459e8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x145FF8u; }
        if (ctx->pc != 0x145FF8u) { return; }
    }
    ctx->pc = 0x145FF8u;
label_145ff8:
    // 0x145ff8: 0xae020190  sw          $v0, 0x190($s0)
    ctx->pc = 0x145ff8u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 400), GPR_U32(ctx, 2));
    // 0x145ffc: 0x200202d  daddu       $a0, $s0, $zero
    ctx->pc = 0x145ffcu;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x146000: 0xc05167a  jal         func_1459E8
    ctx->pc = 0x146000u;
    SET_GPR_U32(ctx, 31, 0x146008u);
    ctx->pc = 0x146004u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x146000u;
            // 0x146004: 0x24050001  addiu       $a1, $zero, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1459E8u;
    if (runtime->hasFunction(0x1459E8u)) {
        auto targetFn = runtime->lookupFunction(0x1459E8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x146008u; }
        if (ctx->pc != 0x146008u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001459E8_0x1459e8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x146008u; }
        if (ctx->pc != 0x146008u) { return; }
    }
    ctx->pc = 0x146008u;
label_146008:
    // 0x146008: 0xae020194  sw          $v0, 0x194($s0)
    ctx->pc = 0x146008u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 404), GPR_U32(ctx, 2));
    // 0x14600c: 0x200202d  daddu       $a0, $s0, $zero
    ctx->pc = 0x14600cu;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x146010: 0xc05167a  jal         func_1459E8
    ctx->pc = 0x146010u;
    SET_GPR_U32(ctx, 31, 0x146018u);
    ctx->pc = 0x146014u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x146010u;
            // 0x146014: 0x24050001  addiu       $a1, $zero, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1459E8u;
    if (runtime->hasFunction(0x1459E8u)) {
        auto targetFn = runtime->lookupFunction(0x1459E8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x146018u; }
        if (ctx->pc != 0x146018u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001459E8_0x1459e8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x146018u; }
        if (ctx->pc != 0x146018u) { return; }
    }
    ctx->pc = 0x146018u;
label_146018:
    // 0x146018: 0xae020198  sw          $v0, 0x198($s0)
    ctx->pc = 0x146018u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 408), GPR_U32(ctx, 2));
    // 0x14601c: 0x200202d  daddu       $a0, $s0, $zero
    ctx->pc = 0x14601cu;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x146020: 0xc05167a  jal         func_1459E8
    ctx->pc = 0x146020u;
    SET_GPR_U32(ctx, 31, 0x146028u);
    ctx->pc = 0x146024u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x146020u;
            // 0x146024: 0x24050001  addiu       $a1, $zero, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1459E8u;
    if (runtime->hasFunction(0x1459E8u)) {
        auto targetFn = runtime->lookupFunction(0x1459E8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x146028u; }
        if (ctx->pc != 0x146028u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001459E8_0x1459e8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x146028u; }
        if (ctx->pc != 0x146028u) { return; }
    }
    ctx->pc = 0x146028u;
label_146028:
    // 0x146028: 0x3c061000  lui         $a2, 0x1000
    ctx->pc = 0x146028u;
    SET_GPR_S32(ctx, 6, (int32_t)((uint32_t)4096 << 16));
    // 0x14602c: 0x8cc62010  lw          $a2, 0x2010($a2)
    ctx->pc = 0x14602cu;
    SET_GPR_S32(ctx, 6, (int32_t)runtime->Load32(rdram, ctx, ADD32(GPR_U32(ctx, 6), 8208))); // MMIO: 0x10002010
    // 0x146030: 0x3c03ffbf  lui         $v1, 0xFFBF
    ctx->pc = 0x146030u;
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)65471 << 16));
    // 0x146034: 0x3463ffff  ori         $v1, $v1, 0xFFFF
    ctx->pc = 0x146034u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) | (uint64_t)(uint16_t)65535);
    // 0x146038: 0x21580  sll         $v0, $v0, 22
    ctx->pc = 0x146038u;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 2), 22));
    // 0x14603c: 0xc33024  and         $a2, $a2, $v1
    ctx->pc = 0x14603cu;
    SET_GPR_U64(ctx, 6, GPR_U64(ctx, 6) & GPR_U64(ctx, 3));
    // 0x146040: 0x200202d  daddu       $a0, $s0, $zero
    ctx->pc = 0x146040u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x146044: 0xc23025  or          $a2, $a2, $v0
    ctx->pc = 0x146044u;
    SET_GPR_U64(ctx, 6, GPR_U64(ctx, 6) | GPR_U64(ctx, 2));
    // 0x146048: 0x24050001  addiu       $a1, $zero, 0x1
    ctx->pc = 0x146048u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x14604c: 0x3c011000  lui         $at, 0x1000
    ctx->pc = 0x14604cu;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)4096 << 16));
    // 0x146050: 0xc05167a  jal         func_1459E8
    ctx->pc = 0x146050u;
    SET_GPR_U32(ctx, 31, 0x146058u);
    ctx->pc = 0x146054u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x146050u;
            // 0x146054: 0xac262010  sw          $a2, 0x2010($at) (Delay Slot)
        runtime->Store32(rdram, ctx, ADD32(GPR_U32(ctx, 1), 8208), GPR_U32(ctx, 6));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1459E8u;
    if (runtime->hasFunction(0x1459E8u)) {
        auto targetFn = runtime->lookupFunction(0x1459E8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x146058u; }
        if (ctx->pc != 0x146058u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001459E8_0x1459e8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x146058u; }
        if (ctx->pc != 0x146058u) { return; }
    }
    ctx->pc = 0x146058u;
label_146058:
    // 0x146058: 0x3c061000  lui         $a2, 0x1000
    ctx->pc = 0x146058u;
    SET_GPR_S32(ctx, 6, (int32_t)((uint32_t)4096 << 16));
    // 0x14605c: 0x8cc62010  lw          $a2, 0x2010($a2)
    ctx->pc = 0x14605cu;
    SET_GPR_S32(ctx, 6, (int32_t)runtime->Load32(rdram, ctx, ADD32(GPR_U32(ctx, 6), 8208))); // MMIO: 0x10002010
    // 0x146060: 0x3c03ffdf  lui         $v1, 0xFFDF
    ctx->pc = 0x146060u;
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)65503 << 16));
    // 0x146064: 0x3463ffff  ori         $v1, $v1, 0xFFFF
    ctx->pc = 0x146064u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) | (uint64_t)(uint16_t)65535);
    // 0x146068: 0x21540  sll         $v0, $v0, 21
    ctx->pc = 0x146068u;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 2), 21));
    // 0x14606c: 0xc33024  and         $a2, $a2, $v1
    ctx->pc = 0x14606cu;
    SET_GPR_U64(ctx, 6, GPR_U64(ctx, 6) & GPR_U64(ctx, 3));
    // 0x146070: 0x200202d  daddu       $a0, $s0, $zero
    ctx->pc = 0x146070u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x146074: 0xc23025  or          $a2, $a2, $v0
    ctx->pc = 0x146074u;
    SET_GPR_U64(ctx, 6, GPR_U64(ctx, 6) | GPR_U64(ctx, 2));
    // 0x146078: 0x24050001  addiu       $a1, $zero, 0x1
    ctx->pc = 0x146078u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x14607c: 0x3c011000  lui         $at, 0x1000
    ctx->pc = 0x14607cu;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)4096 << 16));
    // 0x146080: 0xc05167a  jal         func_1459E8
    ctx->pc = 0x146080u;
    SET_GPR_U32(ctx, 31, 0x146088u);
    ctx->pc = 0x146084u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x146080u;
            // 0x146084: 0xac262010  sw          $a2, 0x2010($at) (Delay Slot)
        runtime->Store32(rdram, ctx, ADD32(GPR_U32(ctx, 1), 8208), GPR_U32(ctx, 6));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1459E8u;
    if (runtime->hasFunction(0x1459E8u)) {
        auto targetFn = runtime->lookupFunction(0x1459E8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x146088u; }
        if (ctx->pc != 0x146088u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001459E8_0x1459e8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x146088u; }
        if (ctx->pc != 0x146088u) { return; }
    }
    ctx->pc = 0x146088u;
label_146088:
    // 0x146088: 0x3c061000  lui         $a2, 0x1000
    ctx->pc = 0x146088u;
    SET_GPR_S32(ctx, 6, (int32_t)((uint32_t)4096 << 16));
    // 0x14608c: 0x8cc62010  lw          $a2, 0x2010($a2)
    ctx->pc = 0x14608cu;
    SET_GPR_S32(ctx, 6, (int32_t)runtime->Load32(rdram, ctx, ADD32(GPR_U32(ctx, 6), 8208))); // MMIO: 0x10002010
    // 0x146090: 0x3c03ffef  lui         $v1, 0xFFEF
    ctx->pc = 0x146090u;
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)65519 << 16));
    // 0x146094: 0x3463ffff  ori         $v1, $v1, 0xFFFF
    ctx->pc = 0x146094u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) | (uint64_t)(uint16_t)65535);
    // 0x146098: 0x21500  sll         $v0, $v0, 20
    ctx->pc = 0x146098u;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 2), 20));
    // 0x14609c: 0xc33024  and         $a2, $a2, $v1
    ctx->pc = 0x14609cu;
    SET_GPR_U64(ctx, 6, GPR_U64(ctx, 6) & GPR_U64(ctx, 3));
    // 0x1460a0: 0x200202d  daddu       $a0, $s0, $zero
    ctx->pc = 0x1460a0u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1460a4: 0xc23025  or          $a2, $a2, $v0
    ctx->pc = 0x1460a4u;
    SET_GPR_U64(ctx, 6, GPR_U64(ctx, 6) | GPR_U64(ctx, 2));
    // 0x1460a8: 0x24050001  addiu       $a1, $zero, 0x1
    ctx->pc = 0x1460a8u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x1460ac: 0x3c011000  lui         $at, 0x1000
    ctx->pc = 0x1460acu;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)4096 << 16));
    // 0x1460b0: 0xc05167a  jal         func_1459E8
    ctx->pc = 0x1460B0u;
    SET_GPR_U32(ctx, 31, 0x1460B8u);
    ctx->pc = 0x1460B4u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1460B0u;
            // 0x1460b4: 0xac262010  sw          $a2, 0x2010($at) (Delay Slot)
        runtime->Store32(rdram, ctx, ADD32(GPR_U32(ctx, 1), 8208), GPR_U32(ctx, 6));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1459E8u;
    if (runtime->hasFunction(0x1459E8u)) {
        auto targetFn = runtime->lookupFunction(0x1459E8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1460B8u; }
        if (ctx->pc != 0x1460B8u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001459E8_0x1459e8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1460B8u; }
        if (ctx->pc != 0x1460B8u) { return; }
    }
    ctx->pc = 0x1460B8u;
label_1460b8:
    // 0x1460b8: 0xae02019c  sw          $v0, 0x19C($s0)
    ctx->pc = 0x1460b8u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 412), GPR_U32(ctx, 2));
    // 0x1460bc: 0x200202d  daddu       $a0, $s0, $zero
    ctx->pc = 0x1460bcu;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1460c0: 0xc05167a  jal         func_1459E8
    ctx->pc = 0x1460C0u;
    SET_GPR_U32(ctx, 31, 0x1460C8u);
    ctx->pc = 0x1460C4u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1460C0u;
            // 0x1460c4: 0x24050001  addiu       $a1, $zero, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1459E8u;
    if (runtime->hasFunction(0x1459E8u)) {
        auto targetFn = runtime->lookupFunction(0x1459E8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1460C8u; }
        if (ctx->pc != 0x1460C8u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001459E8_0x1459e8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1460C8u; }
        if (ctx->pc != 0x1460C8u) { return; }
    }
    ctx->pc = 0x1460C8u;
label_1460c8:
    // 0x1460c8: 0x200202d  daddu       $a0, $s0, $zero
    ctx->pc = 0x1460c8u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1460cc: 0xc05167a  jal         func_1459E8
    ctx->pc = 0x1460CCu;
    SET_GPR_U32(ctx, 31, 0x1460D4u);
    ctx->pc = 0x1460D0u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1460CCu;
            // 0x1460d0: 0x24050001  addiu       $a1, $zero, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1459E8u;
    if (runtime->hasFunction(0x1459E8u)) {
        auto targetFn = runtime->lookupFunction(0x1459E8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1460D4u; }
        if (ctx->pc != 0x1460D4u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001459E8_0x1459e8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1460D4u; }
        if (ctx->pc != 0x1460D4u) { return; }
    }
    ctx->pc = 0x1460D4u;
label_1460d4:
    // 0x1460d4: 0xae0201a0  sw          $v0, 0x1A0($s0)
    ctx->pc = 0x1460d4u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 416), GPR_U32(ctx, 2));
    // 0x1460d8: 0x200202d  daddu       $a0, $s0, $zero
    ctx->pc = 0x1460d8u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1460dc: 0xc05167a  jal         func_1459E8
    ctx->pc = 0x1460DCu;
    SET_GPR_U32(ctx, 31, 0x1460E4u);
    ctx->pc = 0x1460E0u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1460DCu;
            // 0x1460e0: 0x24050001  addiu       $a1, $zero, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1459E8u;
    if (runtime->hasFunction(0x1459E8u)) {
        auto targetFn = runtime->lookupFunction(0x1459E8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1460E4u; }
        if (ctx->pc != 0x1460E4u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001459E8_0x1459e8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1460E4u; }
        if (ctx->pc != 0x1460E4u) { return; }
    }
    ctx->pc = 0x1460E4u;
label_1460e4:
    // 0x1460e4: 0x10400013  beqz        $v0, . + 4 + (0x13 << 2)
    ctx->pc = 0x1460E4u;
    {
        const bool branch_taken_0x1460e4 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x1460E8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1460E4u;
            // 0x1460e8: 0xdfbf0010  ld          $ra, 0x10($sp) (Delay Slot)
        SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 16)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1460e4) {
            ctx->pc = 0x146134u;
            goto label_146134;
        }
    }
    ctx->pc = 0x1460ECu;
    // 0x1460ec: 0x200202d  daddu       $a0, $s0, $zero
    ctx->pc = 0x1460ecu;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1460f0: 0xc05167a  jal         func_1459E8
    ctx->pc = 0x1460F0u;
    SET_GPR_U32(ctx, 31, 0x1460F8u);
    ctx->pc = 0x1460F4u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1460F0u;
            // 0x1460f4: 0x24050001  addiu       $a1, $zero, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1459E8u;
    if (runtime->hasFunction(0x1459E8u)) {
        auto targetFn = runtime->lookupFunction(0x1459E8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1460F8u; }
        if (ctx->pc != 0x1460F8u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001459E8_0x1459e8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1460F8u; }
        if (ctx->pc != 0x1460F8u) { return; }
    }
    ctx->pc = 0x1460F8u;
label_1460f8:
    // 0x1460f8: 0x200202d  daddu       $a0, $s0, $zero
    ctx->pc = 0x1460f8u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1460fc: 0xc05167a  jal         func_1459E8
    ctx->pc = 0x1460FCu;
    SET_GPR_U32(ctx, 31, 0x146104u);
    ctx->pc = 0x146100u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1460FCu;
            // 0x146100: 0x24050003  addiu       $a1, $zero, 0x3 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 3));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1459E8u;
    if (runtime->hasFunction(0x1459E8u)) {
        auto targetFn = runtime->lookupFunction(0x1459E8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x146104u; }
        if (ctx->pc != 0x146104u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001459E8_0x1459e8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x146104u; }
        if (ctx->pc != 0x146104u) { return; }
    }
    ctx->pc = 0x146104u;
label_146104:
    // 0x146104: 0x200202d  daddu       $a0, $s0, $zero
    ctx->pc = 0x146104u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x146108: 0xc05167a  jal         func_1459E8
    ctx->pc = 0x146108u;
    SET_GPR_U32(ctx, 31, 0x146110u);
    ctx->pc = 0x14610Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x146108u;
            // 0x14610c: 0x24050001  addiu       $a1, $zero, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1459E8u;
    if (runtime->hasFunction(0x1459E8u)) {
        auto targetFn = runtime->lookupFunction(0x1459E8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x146110u; }
        if (ctx->pc != 0x146110u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001459E8_0x1459e8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x146110u; }
        if (ctx->pc != 0x146110u) { return; }
    }
    ctx->pc = 0x146110u;
label_146110:
    // 0x146110: 0x200202d  daddu       $a0, $s0, $zero
    ctx->pc = 0x146110u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x146114: 0xc05167a  jal         func_1459E8
    ctx->pc = 0x146114u;
    SET_GPR_U32(ctx, 31, 0x14611Cu);
    ctx->pc = 0x146118u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x146114u;
            // 0x146118: 0x24050007  addiu       $a1, $zero, 0x7 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 7));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1459E8u;
    if (runtime->hasFunction(0x1459E8u)) {
        auto targetFn = runtime->lookupFunction(0x1459E8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x14611Cu; }
        if (ctx->pc != 0x14611Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001459E8_0x1459e8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x14611Cu; }
        if (ctx->pc != 0x14611Cu) { return; }
    }
    ctx->pc = 0x14611Cu;
label_14611c:
    // 0x14611c: 0x200202d  daddu       $a0, $s0, $zero
    ctx->pc = 0x14611cu;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x146120: 0xdfbf0010  ld          $ra, 0x10($sp)
    ctx->pc = 0x146120u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x146124: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x146124u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x146128: 0x24050008  addiu       $a1, $zero, 0x8
    ctx->pc = 0x146128u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 8));
    // 0x14612c: 0x805167a  j           func_1459E8
    ctx->pc = 0x14612Cu;
    ctx->pc = 0x146130u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x14612Cu;
            // 0x146130: 0x27bd0020  addiu       $sp, $sp, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1459E8u;
    if (runtime->hasFunction(0x1459E8u)) {
        auto targetFn = runtime->lookupFunction(0x1459E8u);
        targetFn(rdram, ctx, runtime); return;
    } else {
        sub_001459E8_0x1459e8(rdram, ctx, runtime); return;
    }
    ctx->pc = 0x146134u;
label_146134:
    // 0x146134: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x146134u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x146138: 0x3e00008  jr          $ra
    ctx->pc = 0x146138u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x14613Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x146138u;
            // 0x14613c: 0x27bd0020  addiu       $sp, $sp, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x145F68u: goto label_145f68;
            case 0x145F78u: goto label_145f78;
            case 0x145F88u: goto label_145f88;
            case 0x145F98u: goto label_145f98;
            case 0x145FA8u: goto label_145fa8;
            case 0x145FD8u: goto label_145fd8;
            case 0x145FECu: goto label_145fec;
            case 0x145FF8u: goto label_145ff8;
            case 0x146008u: goto label_146008;
            case 0x146018u: goto label_146018;
            case 0x146028u: goto label_146028;
            case 0x146058u: goto label_146058;
            case 0x146088u: goto label_146088;
            case 0x1460B8u: goto label_1460b8;
            case 0x1460C8u: goto label_1460c8;
            case 0x1460D4u: goto label_1460d4;
            case 0x1460E4u: goto label_1460e4;
            case 0x1460F8u: goto label_1460f8;
            case 0x146104u: goto label_146104;
            case 0x146110u: goto label_146110;
            case 0x14611Cu: goto label_14611c;
            case 0x146134u: goto label_146134;
            default: break;
        }
        return;
    }
    ctx->pc = 0x146140u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
