#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00168A78
// Address: 0x168a78 - 0x168af0
void sub_00168A78_0x168a78(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00168A78_0x168a78");
#endif

    switch (ctx->pc) {
        case 0x168a94u: goto label_168a94;
        default: break;
    }

    ctx->pc = 0x168a78u;

    // 0x168a78: 0x27bdffe0  addiu       $sp, $sp, -0x20
    ctx->pc = 0x168a78u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967264));
    // 0x168a7c: 0x80102d  daddu       $v0, $a0, $zero
    ctx->pc = 0x168a7cu;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x168a80: 0xa0302d  daddu       $a2, $a1, $zero
    ctx->pc = 0x168a80u;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
    // 0x168a84: 0x40282d  daddu       $a1, $v0, $zero
    ctx->pc = 0x168a84u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x168a88: 0xffbf0010  sd          $ra, 0x10($sp)
    ctx->pc = 0x168a88u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 31));
    // 0x168a8c: 0xc05a31c  jal         func_168C70
    ctx->pc = 0x168A8Cu;
    SET_GPR_U32(ctx, 31, 0x168A94u);
    ctx->pc = 0x168A90u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x168A8Cu;
            // 0x168a90: 0x3a0202d  daddu       $a0, $sp, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 29) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x168C70u;
    if (runtime->hasFunction(0x168C70u)) {
        auto targetFn = runtime->lookupFunction(0x168C70u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x168A94u; }
        if (ctx->pc != 0x168A94u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00168C70_0x168c70(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x168A94u; }
        if (ctx->pc != 0x168A94u) { return; }
    }
    ctx->pc = 0x168A94u;
label_168a94:
    // 0x168a94: 0x14400004  bnez        $v0, . + 4 + (0x4 << 2)
    ctx->pc = 0x168A94u;
    {
        const bool branch_taken_0x168a94 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x168A98u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x168A94u;
            // 0x168a98: 0x2405ffff  addiu       $a1, $zero, -0x1 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
        ctx->in_delay_slot = false;
        if (branch_taken_0x168a94) {
            ctx->pc = 0x168AA8u;
            goto label_168aa8;
        }
    }
    ctx->pc = 0x168A9Cu;
    // 0x168a9c: 0x10000011  b           . + 4 + (0x11 << 2)
    ctx->pc = 0x168A9Cu;
    {
        const bool branch_taken_0x168a9c = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x168AA0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x168A9Cu;
            // 0x168aa0: 0x2402ffff  addiu       $v0, $zero, -0x1 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
        ctx->in_delay_slot = false;
        if (branch_taken_0x168a9c) {
            ctx->pc = 0x168AE4u;
            goto label_168ae4;
        }
    }
    ctx->pc = 0x168AA4u;
    // 0x168aa4: 0x0  nop
    ctx->pc = 0x168aa4u;
    // NOP
label_168aa8:
    // 0x168aa8: 0x93a30000  lbu         $v1, 0x0($sp)
    ctx->pc = 0x168aa8u;
    SET_GPR_U32(ctx, 3, (uint8_t)READ8(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x168aac: 0x2402ffff  addiu       $v0, $zero, -0x1
    ctx->pc = 0x168aacu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
    // 0x168ab0: 0x93a40002  lbu         $a0, 0x2($sp)
    ctx->pc = 0x168ab0u;
    SET_GPR_U32(ctx, 4, (uint8_t)READ8(ADD32(GPR_U32(ctx, 29), 2)));
    // 0x168ab4: 0x31900  sll         $v1, $v1, 4
    ctx->pc = 0x168ab4u;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 3), 4));
    // 0x168ab8: 0x641821  addu        $v1, $v1, $a0
    ctx->pc = 0x168ab8u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 4)));
    // 0x168abc: 0x31880  sll         $v1, $v1, 2
    ctx->pc = 0x168abcu;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 3), 2));
    // 0x168ac0: 0x3c010024  lui         $at, 0x24
    ctx->pc = 0x168ac0u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)36 << 16));
    // 0x168ac4: 0x230821  addu        $at, $at, $v1
    ctx->pc = 0x168ac4u;
    SET_GPR_S32(ctx, 1, (int32_t)ADD32(GPR_U32(ctx, 1), GPR_U32(ctx, 3)));
    // 0x168ac8: 0x8c230680  lw          $v1, 0x680($at)
    ctx->pc = 0x168ac8u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 1), 1664)));
    // 0x168acc: 0x10650005  beq         $v1, $a1, . + 4 + (0x5 << 2)
    ctx->pc = 0x168ACCu;
    {
        const bool branch_taken_0x168acc = (GPR_U64(ctx, 3) == GPR_U64(ctx, 5));
        ctx->pc = 0x168AD0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x168ACCu;
            // 0x168ad0: 0x32140  sll         $a0, $v1, 5 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)SLL32(GPR_U32(ctx, 3), 5));
        ctx->in_delay_slot = false;
        if (branch_taken_0x168acc) {
            ctx->pc = 0x168AE4u;
            goto label_168ae4;
        }
    }
    ctx->pc = 0x168AD4u;
    // 0x168ad4: 0x831023  subu        $v0, $a0, $v1
    ctx->pc = 0x168ad4u;
    SET_GPR_S32(ctx, 2, (int32_t)SUB32(GPR_U32(ctx, 4), GPR_U32(ctx, 3)));
    // 0x168ad8: 0x21080  sll         $v0, $v0, 2
    ctx->pc = 0x168ad8u;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 2), 2));
    // 0x168adc: 0x431021  addu        $v0, $v0, $v1
    ctx->pc = 0x168adcu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 3)));
    // 0x168ae0: 0x210c0  sll         $v0, $v0, 3
    ctx->pc = 0x168ae0u;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 2), 3));
label_168ae4:
    // 0x168ae4: 0xdfbf0010  ld          $ra, 0x10($sp)
    ctx->pc = 0x168ae4u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x168ae8: 0x3e00008  jr          $ra
    ctx->pc = 0x168AE8u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x168AECu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x168AE8u;
            // 0x168aec: 0x27bd0020  addiu       $sp, $sp, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x168A94u: goto label_168a94;
            case 0x168AA8u: goto label_168aa8;
            case 0x168AE4u: goto label_168ae4;
            default: break;
        }
        return;
    }
    ctx->pc = 0x168AF0u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
