#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00139BD8
// Address: 0x139bd8 - 0x139c30
void sub_00139BD8_0x139bd8(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00139BD8_0x139bd8");
#endif

    switch (ctx->pc) {
        case 0x139c04u: goto label_139c04;
        default: break;
    }

    ctx->pc = 0x139bd8u;

    // 0x139bd8: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x139bd8u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x139bdc: 0xffb00000  sd          $s0, 0x0($sp)
    ctx->pc = 0x139bdcu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x139be0: 0x80802d  daddu       $s0, $a0, $zero
    ctx->pc = 0x139be0u;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x139be4: 0x1200000e  beqz        $s0, . + 4 + (0xE << 2)
    ctx->pc = 0x139BE4u;
    {
        const bool branch_taken_0x139be4 = (GPR_U64(ctx, 16) == GPR_U64(ctx, 0));
        ctx->pc = 0x139BE8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x139BE4u;
            // 0x139be8: 0xffbf0008  sd          $ra, 0x8($sp) (Delay Slot)
        WRITE64(ADD32(GPR_U32(ctx, 29), 8), GPR_U64(ctx, 31));
        ctx->in_delay_slot = false;
        if (branch_taken_0x139be4) {
            ctx->pc = 0x139C20u;
            goto label_139c20;
        }
    }
    ctx->pc = 0x139BECu;
    // 0x139bec: 0x92020002  lbu         $v0, 0x2($s0)
    ctx->pc = 0x139becu;
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 16), 2)));
    // 0x139bf0: 0x2c420002  sltiu       $v0, $v0, 0x2
    ctx->pc = 0x139bf0u;
    SET_GPR_U64(ctx, 2, ((uint64_t)GPR_U64(ctx, 2) < (uint64_t)(int64_t)(int32_t)2) ? 1 : 0);
    // 0x139bf4: 0x54400004  bnel        $v0, $zero, . + 4 + (0x4 << 2)
    ctx->pc = 0x139BF4u;
    {
        const bool branch_taken_0x139bf4 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x139bf4) {
            ctx->pc = 0x139BF8u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x139BF4u;
            // 0x139bf8: 0xa2000000  sb          $zero, 0x0($s0) (Delay Slot)
        WRITE8(ADD32(GPR_U32(ctx, 16), 0), (uint8_t)GPR_U32(ctx, 0));
        ctx->in_delay_slot = false;
            ctx->pc = 0x139C08u;
            goto label_139c08;
        }
    }
    ctx->pc = 0x139BFCu;
    // 0x139bfc: 0xc04e7aa  jal         func_139EA8
    ctx->pc = 0x139BFCu;
    SET_GPR_U32(ctx, 31, 0x139C04u);
    ctx->pc = 0x139EA8u;
    if (runtime->hasFunction(0x139EA8u)) {
        auto targetFn = runtime->lookupFunction(0x139EA8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x139C04u; }
        if (ctx->pc != 0x139C04u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00139EA8_0x139ea8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x139C04u; }
        if (ctx->pc != 0x139C04u) { return; }
    }
    ctx->pc = 0x139C04u;
label_139c04:
    // 0x139c04: 0xa2000000  sb          $zero, 0x0($s0)
    ctx->pc = 0x139c04u;
    WRITE8(ADD32(GPR_U32(ctx, 16), 0), (uint8_t)GPR_U32(ctx, 0));
label_139c08:
    // 0x139c08: 0x200202d  daddu       $a0, $s0, $zero
    ctx->pc = 0x139c08u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x139c0c: 0xdfbf0008  ld          $ra, 0x8($sp)
    ctx->pc = 0x139c0cu;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x139c10: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x139c10u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x139c14: 0x804e68c  j           func_139A30
    ctx->pc = 0x139C14u;
    ctx->pc = 0x139C18u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x139C14u;
            // 0x139c18: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
    ctx->pc = 0x139A30u;
    if (runtime->hasFunction(0x139A30u)) {
        auto targetFn = runtime->lookupFunction(0x139A30u);
        targetFn(rdram, ctx, runtime); return;
    } else {
        sub_00139A30_0x139a30(rdram, ctx, runtime); return;
    }
    ctx->pc = 0x139C1Cu;
    // 0x139c1c: 0x0  nop
    ctx->pc = 0x139c1cu;
    // NOP
label_139c20:
    // 0x139c20: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x139c20u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x139c24: 0xdfbf0008  ld          $ra, 0x8($sp)
    ctx->pc = 0x139c24u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x139c28: 0x3e00008  jr          $ra
    ctx->pc = 0x139C28u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x139C2Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x139C28u;
            // 0x139c2c: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x139C04u: goto label_139c04;
            case 0x139C08u: goto label_139c08;
            case 0x139C20u: goto label_139c20;
            default: break;
        }
        return;
    }
    ctx->pc = 0x139C30u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
