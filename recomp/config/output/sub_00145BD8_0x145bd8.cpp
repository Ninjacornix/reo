#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00145BD8
// Address: 0x145bd8 - 0x145c40
void sub_00145BD8_0x145bd8(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00145BD8_0x145bd8");
#endif

    switch (ctx->pc) {
        case 0x145bf0u: goto label_145bf0;
        case 0x145c00u: goto label_145c00;
        case 0x145c14u: goto label_145c14;
        case 0x145c20u: goto label_145c20;
        case 0x145c28u: goto label_145c28;
        default: break;
    }

    ctx->pc = 0x145bd8u;

    // 0x145bd8: 0x27bdffe0  addiu       $sp, $sp, -0x20
    ctx->pc = 0x145bd8u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967264));
    // 0x145bdc: 0x24050005  addiu       $a1, $zero, 0x5
    ctx->pc = 0x145bdcu;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 5));
    // 0x145be0: 0xffb00000  sd          $s0, 0x0($sp)
    ctx->pc = 0x145be0u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x145be4: 0xffbf0010  sd          $ra, 0x10($sp)
    ctx->pc = 0x145be4u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 31));
    // 0x145be8: 0xc05167a  jal         func_1459E8
    ctx->pc = 0x145BE8u;
    SET_GPR_U32(ctx, 31, 0x145BF0u);
    ctx->pc = 0x145BECu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x145BE8u;
            // 0x145bec: 0x80802d  daddu       $s0, $a0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1459E8u;
    if (runtime->hasFunction(0x1459E8u)) {
        auto targetFn = runtime->lookupFunction(0x1459E8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x145BF0u; }
        if (ctx->pc != 0x145BF0u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001459E8_0x1459e8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x145BF0u; }
        if (ctx->pc != 0x145BF0u) { return; }
    }
    ctx->pc = 0x145BF0u;
label_145bf0:
    // 0x145bf0: 0xae0201cc  sw          $v0, 0x1CC($s0)
    ctx->pc = 0x145bf0u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 460), GPR_U32(ctx, 2));
    // 0x145bf4: 0x200202d  daddu       $a0, $s0, $zero
    ctx->pc = 0x145bf4u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x145bf8: 0xc05167a  jal         func_1459E8
    ctx->pc = 0x145BF8u;
    SET_GPR_U32(ctx, 31, 0x145C00u);
    ctx->pc = 0x145BFCu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x145BF8u;
            // 0x145bfc: 0x24050001  addiu       $a1, $zero, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1459E8u;
    if (runtime->hasFunction(0x1459E8u)) {
        auto targetFn = runtime->lookupFunction(0x1459E8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x145C00u; }
        if (ctx->pc != 0x145C00u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001459E8_0x1459e8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x145C00u; }
        if (ctx->pc != 0x145C00u) { return; }
    }
    ctx->pc = 0x145C00u;
label_145c00:
    // 0x145c00: 0x1040000a  beqz        $v0, . + 4 + (0xA << 2)
    ctx->pc = 0x145C00u;
    {
        const bool branch_taken_0x145c00 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x145C04u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x145C00u;
            // 0x145c04: 0xdfbf0010  ld          $ra, 0x10($sp) (Delay Slot)
        SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 16)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x145c00) {
            ctx->pc = 0x145C2Cu;
            goto label_145c2c;
        }
    }
    ctx->pc = 0x145C08u;
    // 0x145c08: 0x200202d  daddu       $a0, $s0, $zero
    ctx->pc = 0x145c08u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x145c0c: 0xc05167a  jal         func_1459E8
    ctx->pc = 0x145C0Cu;
    SET_GPR_U32(ctx, 31, 0x145C14u);
    ctx->pc = 0x145C10u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x145C0Cu;
            // 0x145c10: 0x24050001  addiu       $a1, $zero, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1459E8u;
    if (runtime->hasFunction(0x1459E8u)) {
        auto targetFn = runtime->lookupFunction(0x1459E8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x145C14u; }
        if (ctx->pc != 0x145C14u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001459E8_0x1459e8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x145C14u; }
        if (ctx->pc != 0x145C14u) { return; }
    }
    ctx->pc = 0x145C14u;
label_145c14:
    // 0x145c14: 0x200202d  daddu       $a0, $s0, $zero
    ctx->pc = 0x145c14u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x145c18: 0xc051636  jal         func_1458D8
    ctx->pc = 0x145C18u;
    SET_GPR_U32(ctx, 31, 0x145C20u);
    ctx->pc = 0x145C1Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x145C18u;
            // 0x145c1c: 0x24050007  addiu       $a1, $zero, 0x7 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 7));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1458D8u;
    if (runtime->hasFunction(0x1458D8u)) {
        auto targetFn = runtime->lookupFunction(0x1458D8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x145C20u; }
        if (ctx->pc != 0x145C20u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001458D8_0x1458d8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x145C20u; }
        if (ctx->pc != 0x145C20u) { return; }
    }
    ctx->pc = 0x145C20u;
label_145c20:
    // 0x145c20: 0xc051850  jal         func_146140
    ctx->pc = 0x145C20u;
    SET_GPR_U32(ctx, 31, 0x145C28u);
    ctx->pc = 0x145C24u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x145C20u;
            // 0x145c24: 0x200202d  daddu       $a0, $s0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x146140u;
    if (runtime->hasFunction(0x146140u)) {
        auto targetFn = runtime->lookupFunction(0x146140u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x145C28u; }
        if (ctx->pc != 0x145C28u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00146140_0x146140(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x145C28u; }
        if (ctx->pc != 0x145C28u) { return; }
    }
    ctx->pc = 0x145C28u;
label_145c28:
    // 0x145c28: 0xdfbf0010  ld          $ra, 0x10($sp)
    ctx->pc = 0x145c28u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 16)));
label_145c2c:
    // 0x145c2c: 0x102d  daddu       $v0, $zero, $zero
    ctx->pc = 0x145c2cu;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x145c30: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x145c30u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x145c34: 0x3e00008  jr          $ra
    ctx->pc = 0x145C34u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x145C38u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x145C34u;
            // 0x145c38: 0x27bd0020  addiu       $sp, $sp, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x145BF0u: goto label_145bf0;
            case 0x145C00u: goto label_145c00;
            case 0x145C14u: goto label_145c14;
            case 0x145C20u: goto label_145c20;
            case 0x145C28u: goto label_145c28;
            case 0x145C2Cu: goto label_145c2c;
            default: break;
        }
        return;
    }
    ctx->pc = 0x145C3Cu;
    // 0x145c3c: 0x0  nop
    ctx->pc = 0x145c3cu;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
