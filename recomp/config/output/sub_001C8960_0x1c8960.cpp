#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001C8960
// Address: 0x1c8960 - 0x1c89d0
void sub_001C8960_0x1c8960(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001C8960_0x1c8960");
#endif

    switch (ctx->pc) {
        case 0x1c8994u: goto label_1c8994;
        case 0x1c89a8u: goto label_1c89a8;
        default: break;
    }

    ctx->pc = 0x1c8960u;

    // 0x1c8960: 0x27bdffd0  addiu       $sp, $sp, -0x30
    ctx->pc = 0x1c8960u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967248));
    // 0x1c8964: 0xffbf0020  sd          $ra, 0x20($sp)
    ctx->pc = 0x1c8964u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 32), GPR_U64(ctx, 31));
    // 0x1c8968: 0x7fb10010  sq          $s1, 0x10($sp)
    ctx->pc = 0x1c8968u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 16), GPR_VEC(ctx, 17));
    // 0x1c896c: 0x7fb00000  sq          $s0, 0x0($sp)
    ctx->pc = 0x1c896cu;
    WRITE128(ADD32(GPR_U32(ctx, 29), 0), GPR_VEC(ctx, 16));
    // 0x1c8970: 0xc0882d  daddu       $s1, $a2, $zero
    ctx->pc = 0x1c8970u;
    SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 6) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1c8974: 0x8c87000c  lw          $a3, 0xC($a0)
    ctx->pc = 0x1c8974u;
    SET_GPR_S32(ctx, 7, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 12)));
    // 0x1c8978: 0x8c820010  lw          $v0, 0x10($a0)
    ctx->pc = 0x1c8978u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 16)));
    // 0x1c897c: 0xe61821  addu        $v1, $a3, $a2
    ctx->pc = 0x1c897cu;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 7), GPR_U32(ctx, 6)));
    // 0x1c8980: 0x43082a  slt         $at, $v0, $v1
    ctx->pc = 0x1c8980u;
    SET_GPR_U64(ctx, 1, ((int64_t)GPR_S64(ctx, 2) < (int64_t)GPR_S64(ctx, 3)) ? 1 : 0);
    // 0x1c8984: 0x10200005  beqz        $at, . + 4 + (0x5 << 2)
    ctx->pc = 0x1C8984u;
    {
        const bool branch_taken_0x1c8984 = (GPR_U64(ctx, 1) == GPR_U64(ctx, 0));
        ctx->pc = 0x1C8988u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1C8984u;
            // 0x1c8988: 0x80802d  daddu       $s0, $a0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1c8984) {
            ctx->pc = 0x1C899Cu;
            goto label_1c899c;
        }
    }
    ctx->pc = 0x1C898Cu;
    // 0x1c898c: 0xc071ef0  jal         func_1C7BC0
    ctx->pc = 0x1C898Cu;
    SET_GPR_U32(ctx, 31, 0x1C8994u);
    ctx->pc = 0x1C8990u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1C898Cu;
            // 0x1c8990: 0x24040004  addiu       $a0, $zero, 0x4 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 4));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1C7BC0u;
    if (runtime->hasFunction(0x1C7BC0u)) {
        auto targetFn = runtime->lookupFunction(0x1C7BC0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1C8994u; }
        if (ctx->pc != 0x1C8994u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001C7BC0_0x1c7bc0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1C8994u; }
        if (ctx->pc != 0x1C8994u) { return; }
    }
    ctx->pc = 0x1C8994u;
label_1c8994:
    // 0x1c8994: 0x10000008  b           . + 4 + (0x8 << 2)
    ctx->pc = 0x1C8994u;
    {
        const bool branch_taken_0x1c8994 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1C8998u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1C8994u;
            // 0x1c8998: 0xdfbf0020  ld          $ra, 0x20($sp) (Delay Slot)
        SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 32)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1c8994) {
            ctx->pc = 0x1C89B8u;
            goto label_1c89b8;
        }
    }
    ctx->pc = 0x1C899Cu;
label_1c899c:
    // 0x1c899c: 0x8e020008  lw          $v0, 0x8($s0)
    ctx->pc = 0x1c899cu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 8)));
    // 0x1c89a0: 0xc041eac  jal         func_107AB0
    ctx->pc = 0x1C89A0u;
    SET_GPR_U32(ctx, 31, 0x1C89A8u);
    ctx->pc = 0x1C89A4u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1C89A0u;
            // 0x1c89a4: 0x472021  addu        $a0, $v0, $a3 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 7)));
        ctx->in_delay_slot = false;
    ctx->pc = 0x107AB0u;
    if (runtime->hasFunction(0x107AB0u)) {
        auto targetFn = runtime->lookupFunction(0x107AB0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1C89A8u; }
        if (ctx->pc != 0x1C89A8u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00107AB0_0x107ab0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1C89A8u; }
        if (ctx->pc != 0x1C89A8u) { return; }
    }
    ctx->pc = 0x1C89A8u;
label_1c89a8:
    // 0x1c89a8: 0x8e03000c  lw          $v1, 0xC($s0)
    ctx->pc = 0x1c89a8u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 12)));
    // 0x1c89ac: 0x711821  addu        $v1, $v1, $s1
    ctx->pc = 0x1c89acu;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 17)));
    // 0x1c89b0: 0xae03000c  sw          $v1, 0xC($s0)
    ctx->pc = 0x1c89b0u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 12), GPR_U32(ctx, 3));
    // 0x1c89b4: 0xdfbf0020  ld          $ra, 0x20($sp)
    ctx->pc = 0x1c89b4u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 32)));
label_1c89b8:
    // 0x1c89b8: 0x7bb10010  lq          $s1, 0x10($sp)
    ctx->pc = 0x1c89b8u;
    SET_GPR_VEC(ctx, 17, READ128(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x1c89bc: 0x7bb00000  lq          $s0, 0x0($sp)
    ctx->pc = 0x1c89bcu;
    SET_GPR_VEC(ctx, 16, READ128(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1c89c0: 0x3e00008  jr          $ra
    ctx->pc = 0x1C89C0u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1C89C4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1C89C0u;
            // 0x1c89c4: 0x27bd0030  addiu       $sp, $sp, 0x30 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 48));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1C8994u: goto label_1c8994;
            case 0x1C899Cu: goto label_1c899c;
            case 0x1C89A8u: goto label_1c89a8;
            case 0x1C89B8u: goto label_1c89b8;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1C89C8u;
    // 0x1c89c8: 0x0  nop
    ctx->pc = 0x1c89c8u;
    // NOP
    // 0x1c89cc: 0x0  nop
    ctx->pc = 0x1c89ccu;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
