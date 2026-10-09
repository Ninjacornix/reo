#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00172F58
// Address: 0x172f58 - 0x172ff8
void sub_00172F58_0x172f58(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00172F58_0x172f58");
#endif

    switch (ctx->pc) {
        case 0x172f74u: goto label_172f74;
        case 0x172f84u: goto label_172f84;
        case 0x172f98u: goto label_172f98;
        case 0x172facu: goto label_172fac;
        case 0x172fb4u: goto label_172fb4;
        case 0x172fc4u: goto label_172fc4;
        case 0x172fd0u: goto label_172fd0;
        default: break;
    }

    ctx->pc = 0x172f58u;

    // 0x172f58: 0x27bdffe0  addiu       $sp, $sp, -0x20
    ctx->pc = 0x172f58u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967264));
    // 0x172f5c: 0x24050005  addiu       $a1, $zero, 0x5
    ctx->pc = 0x172f5cu;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 5));
    // 0x172f60: 0xffb10008  sd          $s1, 0x8($sp)
    ctx->pc = 0x172f60u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 8), GPR_U64(ctx, 17));
    // 0x172f64: 0xffb00000  sd          $s0, 0x0($sp)
    ctx->pc = 0x172f64u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x172f68: 0xffbf0010  sd          $ra, 0x10($sp)
    ctx->pc = 0x172f68u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 31));
    // 0x172f6c: 0xc05d58a  jal         func_175628
    ctx->pc = 0x172F6Cu;
    SET_GPR_U32(ctx, 31, 0x172F74u);
    ctx->pc = 0x172F70u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x172F6Cu;
            // 0x172f70: 0x80882d  daddu       $s1, $a0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x175628u;
    if (runtime->hasFunction(0x175628u)) {
        auto targetFn = runtime->lookupFunction(0x175628u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x172F74u; }
        if (ctx->pc != 0x172F74u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00175628_0x175628(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x172F74u; }
        if (ctx->pc != 0x172F74u) { return; }
    }
    ctx->pc = 0x172F74u;
label_172f74:
    // 0x172f74: 0x10400005  beqz        $v0, . + 4 + (0x5 << 2)
    ctx->pc = 0x172F74u;
    {
        const bool branch_taken_0x172f74 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x172F78u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x172F74u;
            // 0x172f78: 0x220202d  daddu       $a0, $s1, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x172f74) {
            ctx->pc = 0x172F8Cu;
            goto label_172f8c;
        }
    }
    ctx->pc = 0x172F7Cu;
    // 0x172f7c: 0xc05df1e  jal         func_177C78
    ctx->pc = 0x172F7Cu;
    SET_GPR_U32(ctx, 31, 0x172F84u);
    ctx->pc = 0x172F80u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x172F7Cu;
            // 0x172f80: 0x24050006  addiu       $a1, $zero, 0x6 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 6));
        ctx->in_delay_slot = false;
    ctx->pc = 0x177C78u;
    if (runtime->hasFunction(0x177C78u)) {
        auto targetFn = runtime->lookupFunction(0x177C78u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x172F84u; }
        if (ctx->pc != 0x172F84u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00177C78_0x177c78(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x172F84u; }
        if (ctx->pc != 0x172F84u) { return; }
    }
    ctx->pc = 0x172F84u;
label_172f84:
    // 0x172f84: 0x14400016  bnez        $v0, . + 4 + (0x16 << 2)
    ctx->pc = 0x172F84u;
    {
        const bool branch_taken_0x172f84 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x172F88u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x172F84u;
            // 0x172f88: 0x24020001  addiu       $v0, $zero, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
        ctx->in_delay_slot = false;
        if (branch_taken_0x172f84) {
            ctx->pc = 0x172FE0u;
            goto label_172fe0;
        }
    }
    ctx->pc = 0x172F8Cu;
label_172f8c:
    // 0x172f8c: 0x220202d  daddu       $a0, $s1, $zero
    ctx->pc = 0x172f8cu;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
    // 0x172f90: 0xc05d58a  jal         func_175628
    ctx->pc = 0x172F90u;
    SET_GPR_U32(ctx, 31, 0x172F98u);
    ctx->pc = 0x172F94u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x172F90u;
            // 0x172f94: 0x24050006  addiu       $a1, $zero, 0x6 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 6));
        ctx->in_delay_slot = false;
    ctx->pc = 0x175628u;
    if (runtime->hasFunction(0x175628u)) {
        auto targetFn = runtime->lookupFunction(0x175628u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x172F98u; }
        if (ctx->pc != 0x172F98u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00175628_0x175628(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x172F98u; }
        if (ctx->pc != 0x172F98u) { return; }
    }
    ctx->pc = 0x172F98u;
label_172f98:
    // 0x172f98: 0x10400009  beqz        $v0, . + 4 + (0x9 << 2)
    ctx->pc = 0x172F98u;
    {
        const bool branch_taken_0x172f98 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x172F9Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x172F98u;
            // 0x172f9c: 0x802d  daddu       $s0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x172f98) {
            ctx->pc = 0x172FC0u;
            goto label_172fc0;
        }
    }
    ctx->pc = 0x172FA0u;
    // 0x172fa0: 0x220202d  daddu       $a0, $s1, $zero
    ctx->pc = 0x172fa0u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
    // 0x172fa4: 0xc05df1e  jal         func_177C78
    ctx->pc = 0x172FA4u;
    SET_GPR_U32(ctx, 31, 0x172FACu);
    ctx->pc = 0x172FA8u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x172FA4u;
            // 0x172fa8: 0x24050007  addiu       $a1, $zero, 0x7 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 7));
        ctx->in_delay_slot = false;
    ctx->pc = 0x177C78u;
    if (runtime->hasFunction(0x177C78u)) {
        auto targetFn = runtime->lookupFunction(0x177C78u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x172FACu; }
        if (ctx->pc != 0x172FACu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00177C78_0x177c78(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x172FACu; }
        if (ctx->pc != 0x172FACu) { return; }
    }
    ctx->pc = 0x172FACu;
label_172fac:
    // 0x172fac: 0x10400004  beqz        $v0, . + 4 + (0x4 << 2)
    ctx->pc = 0x172FACu;
    {
        const bool branch_taken_0x172fac = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x172FB0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x172FACu;
            // 0x172fb0: 0x802d  daddu       $s0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x172fac) {
            ctx->pc = 0x172FC0u;
            goto label_172fc0;
        }
    }
    ctx->pc = 0x172FB4u;
label_172fb4:
    // 0x172fb4: 0x1000000a  b           . + 4 + (0xA << 2)
    ctx->pc = 0x172FB4u;
    {
        const bool branch_taken_0x172fb4 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x172FB8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x172FB4u;
            // 0x172fb8: 0x24020001  addiu       $v0, $zero, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
        ctx->in_delay_slot = false;
        if (branch_taken_0x172fb4) {
            ctx->pc = 0x172FE0u;
            goto label_172fe0;
        }
    }
    ctx->pc = 0x172FBCu;
    // 0x172fbc: 0x0  nop
    ctx->pc = 0x172fbcu;
    // NOP
label_172fc0:
    // 0x172fc0: 0x200282d  daddu       $a1, $s0, $zero
    ctx->pc = 0x172fc0u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
label_172fc4:
    // 0x172fc4: 0x26100001  addiu       $s0, $s0, 0x1
    ctx->pc = 0x172fc4u;
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 16), 1));
    // 0x172fc8: 0xc059f40  jal         func_167D00
    ctx->pc = 0x172FC8u;
    SET_GPR_U32(ctx, 31, 0x172FD0u);
    ctx->pc = 0x172FCCu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x172FC8u;
            // 0x172fcc: 0x220202d  daddu       $a0, $s1, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x167D00u;
    if (runtime->hasFunction(0x167D00u)) {
        auto targetFn = runtime->lookupFunction(0x167D00u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x172FD0u; }
        if (ctx->pc != 0x172FD0u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00167D00_0x167d00(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x172FD0u; }
        if (ctx->pc != 0x172FD0u) { return; }
    }
    ctx->pc = 0x172FD0u;
label_172fd0:
    // 0x172fd0: 0x1440fff8  bnez        $v0, . + 4 + (-0x8 << 2)
    ctx->pc = 0x172FD0u;
    {
        const bool branch_taken_0x172fd0 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x172FD4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x172FD0u;
            // 0x172fd4: 0x2e030008  sltiu       $v1, $s0, 0x8 (Delay Slot)
        SET_GPR_U64(ctx, 3, ((uint64_t)GPR_U64(ctx, 16) < (uint64_t)(int64_t)(int32_t)8) ? 1 : 0);
        ctx->in_delay_slot = false;
        if (branch_taken_0x172fd0) {
            ctx->pc = 0x172FB4u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_172fb4;
        }
    }
    ctx->pc = 0x172FD8u;
    // 0x172fd8: 0x1460fffa  bnez        $v1, . + 4 + (-0x6 << 2)
    ctx->pc = 0x172FD8u;
    {
        const bool branch_taken_0x172fd8 = (GPR_U64(ctx, 3) != GPR_U64(ctx, 0));
        ctx->pc = 0x172FDCu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x172FD8u;
            // 0x172fdc: 0x200282d  daddu       $a1, $s0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x172fd8) {
            ctx->pc = 0x172FC4u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_172fc4;
        }
    }
    ctx->pc = 0x172FE0u;
label_172fe0:
    // 0x172fe0: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x172fe0u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x172fe4: 0xdfb10008  ld          $s1, 0x8($sp)
    ctx->pc = 0x172fe4u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x172fe8: 0xdfbf0010  ld          $ra, 0x10($sp)
    ctx->pc = 0x172fe8u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x172fec: 0x3e00008  jr          $ra
    ctx->pc = 0x172FECu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x172FF0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x172FECu;
            // 0x172ff0: 0x27bd0020  addiu       $sp, $sp, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x172F74u: goto label_172f74;
            case 0x172F84u: goto label_172f84;
            case 0x172F8Cu: goto label_172f8c;
            case 0x172F98u: goto label_172f98;
            case 0x172FACu: goto label_172fac;
            case 0x172FB4u: goto label_172fb4;
            case 0x172FC0u: goto label_172fc0;
            case 0x172FC4u: goto label_172fc4;
            case 0x172FD0u: goto label_172fd0;
            case 0x172FE0u: goto label_172fe0;
            default: break;
        }
        return;
    }
    ctx->pc = 0x172FF4u;
    // 0x172ff4: 0x0  nop
    ctx->pc = 0x172ff4u;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
