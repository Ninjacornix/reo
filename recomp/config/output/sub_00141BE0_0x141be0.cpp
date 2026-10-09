#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00141BE0
// Address: 0x141be0 - 0x141c58
void sub_00141BE0_0x141be0(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00141BE0_0x141be0");
#endif

    switch (ctx->pc) {
        case 0x141c0cu: goto label_141c0c;
        case 0x141c14u: goto label_141c14;
        default: break;
    }

    ctx->pc = 0x141be0u;

    // 0x141be0: 0x27bdffe0  addiu       $sp, $sp, -0x20
    ctx->pc = 0x141be0u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967264));
    // 0x141be4: 0xffb10008  sd          $s1, 0x8($sp)
    ctx->pc = 0x141be4u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 8), GPR_U64(ctx, 17));
    // 0x141be8: 0xa0882d  daddu       $s1, $a1, $zero
    ctx->pc = 0x141be8u;
    SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
    // 0x141bec: 0x2e220006  sltiu       $v0, $s1, 0x6
    ctx->pc = 0x141becu;
    SET_GPR_U64(ctx, 2, ((uint64_t)GPR_U64(ctx, 17) < (uint64_t)(int64_t)(int32_t)6) ? 1 : 0);
    // 0x141bf0: 0xffb00000  sd          $s0, 0x0($sp)
    ctx->pc = 0x141bf0u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x141bf4: 0xffbf0010  sd          $ra, 0x10($sp)
    ctx->pc = 0x141bf4u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 31));
    // 0x141bf8: 0x14400004  bnez        $v0, . + 4 + (0x4 << 2)
    ctx->pc = 0x141BF8u;
    {
        const bool branch_taken_0x141bf8 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x141BFCu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x141BF8u;
            // 0x141bfc: 0x80802d  daddu       $s0, $a0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x141bf8) {
            ctx->pc = 0x141C0Cu;
            goto label_141c0c;
        }
    }
    ctx->pc = 0x141C00u;
    // 0x141c00: 0x3c040024  lui         $a0, 0x24
    ctx->pc = 0x141c00u;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)36 << 16));
    // 0x141c04: 0xc05062a  jal         func_1418A8
    ctx->pc = 0x141C04u;
    SET_GPR_U32(ctx, 31, 0x141C0Cu);
    ctx->pc = 0x141C08u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x141C04u;
            // 0x141c08: 0x2484dc28  addiu       $a0, $a0, -0x23D8 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 4294958120));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1418A8u;
    if (runtime->hasFunction(0x1418A8u)) {
        auto targetFn = runtime->lookupFunction(0x1418A8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x141C0Cu; }
        if (ctx->pc != 0x141C0Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001418A8_0x1418a8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x141C0Cu; }
        if (ctx->pc != 0x141C0Cu) { return; }
    }
    ctx->pc = 0x141C0Cu;
label_141c0c:
    // 0x141c0c: 0xc0505b4  jal         func_1416D0
    ctx->pc = 0x141C0Cu;
    SET_GPR_U32(ctx, 31, 0x141C14u);
    ctx->pc = 0x1416D0u;
    if (runtime->hasFunction(0x1416D0u)) {
        auto targetFn = runtime->lookupFunction(0x1416D0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x141C14u; }
        if (ctx->pc != 0x141C14u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001416D0_0x1416d0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x141C14u; }
        if (ctx->pc != 0x141C14u) { return; }
    }
    ctx->pc = 0x141C14u;
label_141c14:
    // 0x141c14: 0x3c020026  lui         $v0, 0x26
    ctx->pc = 0x141c14u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)38 << 16));
    // 0x141c18: 0x101840  sll         $v1, $s0, 1
    ctx->pc = 0x141c18u;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 16), 1));
    // 0x141c1c: 0x24424820  addiu       $v0, $v0, 0x4820
    ctx->pc = 0x141c1cu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 18464));
    // 0x141c20: 0x701821  addu        $v1, $v1, $s0
    ctx->pc = 0x141c20u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 16)));
    // 0x141c24: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x141c24u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x141c28: 0x31840  sll         $v1, $v1, 1
    ctx->pc = 0x141c28u;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 3), 1));
    // 0x141c2c: 0xdfbf0010  ld          $ra, 0x10($sp)
    ctx->pc = 0x141c2cu;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x141c30: 0x711821  addu        $v1, $v1, $s1
    ctx->pc = 0x141c30u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 17)));
    // 0x141c34: 0xdfb10008  ld          $s1, 0x8($sp)
    ctx->pc = 0x141c34u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x141c38: 0x318c0  sll         $v1, $v1, 3
    ctx->pc = 0x141c38u;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 3), 3));
    // 0x141c3c: 0x432021  addu        $a0, $v0, $v1
    ctx->pc = 0x141c3cu;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 3)));
    // 0x141c40: 0x621821  addu        $v1, $v1, $v0
    ctx->pc = 0x141c40u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 2)));
    // 0x141c44: 0xac600000  sw          $zero, 0x0($v1)
    ctx->pc = 0x141c44u;
    WRITE32(ADD32(GPR_U32(ctx, 3), 0), GPR_U32(ctx, 0));
    // 0x141c48: 0xac800004  sw          $zero, 0x4($a0)
    ctx->pc = 0x141c48u;
    WRITE32(ADD32(GPR_U32(ctx, 4), 4), GPR_U32(ctx, 0));
    // 0x141c4c: 0x80505ba  j           func_1416E8
    ctx->pc = 0x141C4Cu;
    ctx->pc = 0x141C50u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x141C4Cu;
            // 0x141c50: 0x27bd0020  addiu       $sp, $sp, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1416E8u;
    if (runtime->hasFunction(0x1416E8u)) {
        auto targetFn = runtime->lookupFunction(0x1416E8u);
        targetFn(rdram, ctx, runtime); return;
    } else {
        sub_001416E8_0x1416e8(rdram, ctx, runtime); return;
    }
    ctx->pc = 0x141C54u;
    // 0x141c54: 0x0  nop
    ctx->pc = 0x141c54u;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
