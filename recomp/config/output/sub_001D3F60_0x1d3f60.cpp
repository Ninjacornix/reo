#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001D3F60
// Address: 0x1d3f60 - 0x1d4020
void sub_001D3F60_0x1d3f60(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001D3F60_0x1d3f60");
#endif

    switch (ctx->pc) {
        case 0x1d3f7cu: goto label_1d3f7c;
        case 0x1d3fb0u: goto label_1d3fb0;
        case 0x1d3fc4u: goto label_1d3fc4;
        case 0x1d3fe0u: goto label_1d3fe0;
        case 0x1d3fecu: goto label_1d3fec;
        case 0x1d4004u: goto label_1d4004;
        case 0x1d400cu: goto label_1d400c;
        default: break;
    }

    ctx->pc = 0x1d3f60u;

    // 0x1d3f60: 0x27bdff50  addiu       $sp, $sp, -0xB0
    ctx->pc = 0x1d3f60u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967120));
    // 0x1d3f64: 0xffbf0020  sd          $ra, 0x20($sp)
    ctx->pc = 0x1d3f64u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 32), GPR_U64(ctx, 31));
    // 0x1d3f68: 0x7fb10010  sq          $s1, 0x10($sp)
    ctx->pc = 0x1d3f68u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 16), GPR_VEC(ctx, 17));
    // 0x1d3f6c: 0x3c110032  lui         $s1, 0x32
    ctx->pc = 0x1d3f6cu;
    SET_GPR_S32(ctx, 17, (int32_t)((uint32_t)50 << 16));
    // 0x1d3f70: 0x7fb00000  sq          $s0, 0x0($sp)
    ctx->pc = 0x1d3f70u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 0), GPR_VEC(ctx, 16));
    // 0x1d3f74: 0xc06c0b4  jal         func_1B02D0
    ctx->pc = 0x1D3F74u;
    SET_GPR_U32(ctx, 31, 0x1D3F7Cu);
    ctx->pc = 0x1D3F78u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1D3F74u;
            // 0x1d3f78: 0x263143c0  addiu       $s1, $s1, 0x43C0 (Delay Slot)
        SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 17), 17344));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1B02D0u;
    if (runtime->hasFunction(0x1B02D0u)) {
        auto targetFn = runtime->lookupFunction(0x1B02D0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D3F7Cu; }
        if (ctx->pc != 0x1D3F7Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001B02D0_0x1b02d0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D3F7Cu; }
        if (ctx->pc != 0x1D3F7Cu) { return; }
    }
    ctx->pc = 0x1D3F7Cu;
label_1d3f7c:
    // 0x1d3f7c: 0x10400023  beqz        $v0, . + 4 + (0x23 << 2)
    ctx->pc = 0x1D3F7Cu;
    {
        const bool branch_taken_0x1d3f7c = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x1D3F80u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1D3F7Cu;
            // 0x1d3f80: 0x3c010032  lui         $at, 0x32 (Delay Slot)
        SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)50 << 16));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1d3f7c) {
            ctx->pc = 0x1D400Cu;
            goto label_1d400c;
        }
    }
    ctx->pc = 0x1D3F84u;
    // 0x1d3f84: 0x3c100084  lui         $s0, 0x84
    ctx->pc = 0x1d3f84u;
    SET_GPR_S32(ctx, 16, (int32_t)((uint32_t)132 << 16));
    // 0x1d3f88: 0x802243d7  lb          $v0, 0x43D7($at)
    ctx->pc = 0x1d3f88u;
    SET_GPR_S32(ctx, 2, (int8_t)READ8(ADD32(GPR_U32(ctx, 1), 17367)));
    // 0x1d3f8c: 0x1440000f  bnez        $v0, . + 4 + (0xF << 2)
    ctx->pc = 0x1D3F8Cu;
    {
        const bool branch_taken_0x1d3f8c = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x1D3F90u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1D3F8Cu;
            // 0x1d3f90: 0x26103780  addiu       $s0, $s0, 0x3780 (Delay Slot)
        SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 16), 14208));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1d3f8c) {
            ctx->pc = 0x1D3FCCu;
            goto label_1d3fcc;
        }
    }
    ctx->pc = 0x1D3F94u;
    // 0x1d3f94: 0x9627001a  lhu         $a3, 0x1A($s1)
    ctx->pc = 0x1d3f94u;
    SET_GPR_U32(ctx, 7, (uint16_t)READ16(ADD32(GPR_U32(ctx, 17), 26)));
    // 0x1d3f98: 0x3c050025  lui         $a1, 0x25
    ctx->pc = 0x1d3f98u;
    SET_GPR_S32(ctx, 5, (int32_t)((uint32_t)37 << 16));
    // 0x1d3f9c: 0x3c060025  lui         $a2, 0x25
    ctx->pc = 0x1d3f9cu;
    SET_GPR_S32(ctx, 6, (int32_t)((uint32_t)37 << 16));
    // 0x1d3fa0: 0x27a40030  addiu       $a0, $sp, 0x30
    ctx->pc = 0x1d3fa0u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 29), 48));
    // 0x1d3fa4: 0x24a566f8  addiu       $a1, $a1, 0x66F8
    ctx->pc = 0x1d3fa4u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 26360));
    // 0x1d3fa8: 0xc042a0c  jal         func_10A830
    ctx->pc = 0x1D3FA8u;
    SET_GPR_U32(ctx, 31, 0x1D3FB0u);
    ctx->pc = 0x1D3FACu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1D3FA8u;
            // 0x1d3fac: 0x24c66710  addiu       $a2, $a2, 0x6710 (Delay Slot)
        SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 6), 26384));
        ctx->in_delay_slot = false;
    ctx->pc = 0x10A830u;
    if (runtime->hasFunction(0x10A830u)) {
        auto targetFn = runtime->lookupFunction(0x10A830u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D3FB0u; }
        if (ctx->pc != 0x1D3FB0u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0010A830_0x10a830(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D3FB0u; }
        if (ctx->pc != 0x1D3FB0u) { return; }
    }
    ctx->pc = 0x1D3FB0u;
label_1d3fb0:
    // 0x1d3fb0: 0x27a40030  addiu       $a0, $sp, 0x30
    ctx->pc = 0x1d3fb0u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 29), 48));
    // 0x1d3fb4: 0x200282d  daddu       $a1, $s0, $zero
    ctx->pc = 0x1d3fb4u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1d3fb8: 0x24060001  addiu       $a2, $zero, 0x1
    ctx->pc = 0x1d3fb8u;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x1d3fbc: 0xc07323c  jal         func_1CC8F0
    ctx->pc = 0x1D3FBCu;
    SET_GPR_U32(ctx, 31, 0x1D3FC4u);
    ctx->pc = 0x1D3FC0u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1D3FBCu;
            // 0x1d3fc0: 0x382d  daddu       $a3, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 7, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1CC8F0u;
    if (runtime->hasFunction(0x1CC8F0u)) {
        auto targetFn = runtime->lookupFunction(0x1CC8F0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D3FC4u; }
        if (ctx->pc != 0x1D3FC4u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001CC8F0_0x1cc8f0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D3FC4u; }
        if (ctx->pc != 0x1D3FC4u) { return; }
    }
    ctx->pc = 0x1D3FC4u;
label_1d3fc4:
    // 0x1d3fc4: 0x10000009  b           . + 4 + (0x9 << 2)
    ctx->pc = 0x1D3FC4u;
    {
        const bool branch_taken_0x1d3fc4 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x1d3fc4) {
            ctx->pc = 0x1D3FECu;
            goto label_1d3fec;
        }
    }
    ctx->pc = 0x1D3FCCu;
label_1d3fcc:
    // 0x1d3fcc: 0x9626001a  lhu         $a2, 0x1A($s1)
    ctx->pc = 0x1d3fccu;
    SET_GPR_U32(ctx, 6, (uint16_t)READ16(ADD32(GPR_U32(ctx, 17), 26)));
    // 0x1d3fd0: 0x3c050025  lui         $a1, 0x25
    ctx->pc = 0x1d3fd0u;
    SET_GPR_S32(ctx, 5, (int32_t)((uint32_t)37 << 16));
    // 0x1d3fd4: 0x27a40030  addiu       $a0, $sp, 0x30
    ctx->pc = 0x1d3fd4u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 29), 48));
    // 0x1d3fd8: 0xc042a0c  jal         func_10A830
    ctx->pc = 0x1D3FD8u;
    SET_GPR_U32(ctx, 31, 0x1D3FE0u);
    ctx->pc = 0x1D3FDCu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1D3FD8u;
            // 0x1d3fdc: 0x24a56728  addiu       $a1, $a1, 0x6728 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 26408));
        ctx->in_delay_slot = false;
    ctx->pc = 0x10A830u;
    if (runtime->hasFunction(0x10A830u)) {
        auto targetFn = runtime->lookupFunction(0x10A830u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D3FE0u; }
        if (ctx->pc != 0x1D3FE0u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0010A830_0x10a830(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D3FE0u; }
        if (ctx->pc != 0x1D3FE0u) { return; }
    }
    ctx->pc = 0x1D3FE0u;
label_1d3fe0:
    // 0x1d3fe0: 0x27a40030  addiu       $a0, $sp, 0x30
    ctx->pc = 0x1d3fe0u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 29), 48));
    // 0x1d3fe4: 0xc06a8f8  jal         func_1AA3E0
    ctx->pc = 0x1D3FE4u;
    SET_GPR_U32(ctx, 31, 0x1D3FECu);
    ctx->pc = 0x1D3FE8u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1D3FE4u;
            // 0x1d3fe8: 0x200282d  daddu       $a1, $s0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1AA3E0u;
    if (runtime->hasFunction(0x1AA3E0u)) {
        auto targetFn = runtime->lookupFunction(0x1AA3E0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D3FECu; }
        if (ctx->pc != 0x1D3FECu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001AA3E0_0x1aa3e0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D3FECu; }
        if (ctx->pc != 0x1D3FECu) { return; }
    }
    ctx->pc = 0x1D3FECu;
label_1d3fec:
    // 0x1d3fec: 0x1c400003  bgtz        $v0, . + 4 + (0x3 << 2)
    ctx->pc = 0x1D3FECu;
    {
        const bool branch_taken_0x1d3fec = (GPR_S64(ctx, 2) > 0);
        if (branch_taken_0x1d3fec) {
            ctx->pc = 0x1D3FFCu;
            goto label_1d3ffc;
        }
    }
    ctx->pc = 0x1D3FF4u;
    // 0x1d3ff4: 0x10000005  b           . + 4 + (0x5 << 2)
    ctx->pc = 0x1D3FF4u;
    {
        const bool branch_taken_0x1d3ff4 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1D3FF8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1D3FF4u;
            // 0x1d3ff8: 0xae000000  sw          $zero, 0x0($s0) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 16), 0), GPR_U32(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1d3ff4) {
            ctx->pc = 0x1D400Cu;
            goto label_1d400c;
        }
    }
    ctx->pc = 0x1D3FFCu;
label_1d3ffc:
    // 0x1d3ffc: 0xc2058fc  jal         func_8163F0
    ctx->pc = 0x1D3FFCu;
    SET_GPR_U32(ctx, 31, 0x1D4004u);
    ctx->pc = 0x8163F0u;
    {
        auto targetFn = runtime->lookupFunction(0x8163F0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D4004u; }
        if (ctx->pc != 0x1D4004u) { return; }
    }
    ctx->pc = 0x1D4004u;
label_1d4004:
    // 0x1d4004: 0xc20579c  jal         func_815E70
    ctx->pc = 0x1D4004u;
    SET_GPR_U32(ctx, 31, 0x1D400Cu);
    ctx->pc = 0x1D4008u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1D4004u;
            // 0x1d4008: 0x24040002  addiu       $a0, $zero, 0x2 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 2));
        ctx->in_delay_slot = false;
    ctx->pc = 0x815E70u;
    {
        auto targetFn = runtime->lookupFunction(0x815E70u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D400Cu; }
        if (ctx->pc != 0x1D400Cu) { return; }
    }
    ctx->pc = 0x1D400Cu;
label_1d400c:
    // 0x1d400c: 0xdfbf0020  ld          $ra, 0x20($sp)
    ctx->pc = 0x1d400cu;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x1d4010: 0x7bb10010  lq          $s1, 0x10($sp)
    ctx->pc = 0x1d4010u;
    SET_GPR_VEC(ctx, 17, READ128(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x1d4014: 0x7bb00000  lq          $s0, 0x0($sp)
    ctx->pc = 0x1d4014u;
    SET_GPR_VEC(ctx, 16, READ128(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1d4018: 0x3e00008  jr          $ra
    ctx->pc = 0x1D4018u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1D401Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1D4018u;
            // 0x1d401c: 0x27bd00b0  addiu       $sp, $sp, 0xB0 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 176));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1D3F7Cu: goto label_1d3f7c;
            case 0x1D3FB0u: goto label_1d3fb0;
            case 0x1D3FC4u: goto label_1d3fc4;
            case 0x1D3FCCu: goto label_1d3fcc;
            case 0x1D3FE0u: goto label_1d3fe0;
            case 0x1D3FECu: goto label_1d3fec;
            case 0x1D3FFCu: goto label_1d3ffc;
            case 0x1D4004u: goto label_1d4004;
            case 0x1D400Cu: goto label_1d400c;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1D4020u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
