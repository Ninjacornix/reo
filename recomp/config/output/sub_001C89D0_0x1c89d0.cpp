#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001C89D0
// Address: 0x1c89d0 - 0x1c8a50
void sub_001C89D0_0x1c89d0(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001C89D0_0x1c89d0");
#endif

    switch (ctx->pc) {
        case 0x1c8a0cu: goto label_1c8a0c;
        case 0x1c8a24u: goto label_1c8a24;
        default: break;
    }

    ctx->pc = 0x1c89d0u;

    // 0x1c89d0: 0x27bdffc0  addiu       $sp, $sp, -0x40
    ctx->pc = 0x1c89d0u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967232));
    // 0x1c89d4: 0xffbf0030  sd          $ra, 0x30($sp)
    ctx->pc = 0x1c89d4u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 48), GPR_U64(ctx, 31));
    // 0x1c89d8: 0x7fb20020  sq          $s2, 0x20($sp)
    ctx->pc = 0x1c89d8u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 32), GPR_VEC(ctx, 18));
    // 0x1c89dc: 0x7fb10010  sq          $s1, 0x10($sp)
    ctx->pc = 0x1c89dcu;
    WRITE128(ADD32(GPR_U32(ctx, 29), 16), GPR_VEC(ctx, 17));
    // 0x1c89e0: 0xa0902d  daddu       $s2, $a1, $zero
    ctx->pc = 0x1c89e0u;
    SET_GPR_U64(ctx, 18, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1c89e4: 0x7fb00000  sq          $s0, 0x0($sp)
    ctx->pc = 0x1c89e4u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 0), GPR_VEC(ctx, 16));
    // 0x1c89e8: 0x80882d  daddu       $s1, $a0, $zero
    ctx->pc = 0x1c89e8u;
    SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1c89ec: 0x8c820004  lw          $v0, 0x4($a0)
    ctx->pc = 0x1c89ecu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 4)));
    // 0x1c89f0: 0x8c83000c  lw          $v1, 0xC($a0)
    ctx->pc = 0x1c89f0u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 12)));
    // 0x1c89f4: 0x461021  addu        $v0, $v0, $a2
    ctx->pc = 0x1c89f4u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 6)));
    // 0x1c89f8: 0x62082a  slt         $at, $v1, $v0
    ctx->pc = 0x1c89f8u;
    SET_GPR_U64(ctx, 1, ((int64_t)GPR_S64(ctx, 3) < (int64_t)GPR_S64(ctx, 2)) ? 1 : 0);
    // 0x1c89fc: 0x10200003  beqz        $at, . + 4 + (0x3 << 2)
    ctx->pc = 0x1C89FCu;
    {
        const bool branch_taken_0x1c89fc = (GPR_U64(ctx, 1) == GPR_U64(ctx, 0));
        ctx->pc = 0x1C8A00u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1C89FCu;
            // 0x1c8a00: 0xc0802d  daddu       $s0, $a2, $zero (Delay Slot)
        SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 6) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1c89fc) {
            ctx->pc = 0x1C8A0Cu;
            goto label_1c8a0c;
        }
    }
    ctx->pc = 0x1C8A04u;
    // 0x1c8a04: 0xc071ef0  jal         func_1C7BC0
    ctx->pc = 0x1C8A04u;
    SET_GPR_U32(ctx, 31, 0x1C8A0Cu);
    ctx->pc = 0x1C8A08u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1C8A04u;
            // 0x1c8a08: 0x24040004  addiu       $a0, $zero, 0x4 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 4));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1C7BC0u;
    if (runtime->hasFunction(0x1C7BC0u)) {
        auto targetFn = runtime->lookupFunction(0x1C7BC0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1C8A0Cu; }
        if (ctx->pc != 0x1C8A0Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001C7BC0_0x1c7bc0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1C8A0Cu; }
        if (ctx->pc != 0x1C8A0Cu) { return; }
    }
    ctx->pc = 0x1C8A0Cu;
label_1c8a0c:
    // 0x1c8a0c: 0x8e230008  lw          $v1, 0x8($s1)
    ctx->pc = 0x1c8a0cu;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 8)));
    // 0x1c8a10: 0x240202d  daddu       $a0, $s2, $zero
    ctx->pc = 0x1c8a10u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 18) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1c8a14: 0x8e220004  lw          $v0, 0x4($s1)
    ctx->pc = 0x1c8a14u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 4)));
    // 0x1c8a18: 0x200302d  daddu       $a2, $s0, $zero
    ctx->pc = 0x1c8a18u;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1c8a1c: 0xc041eac  jal         func_107AB0
    ctx->pc = 0x1C8A1Cu;
    SET_GPR_U32(ctx, 31, 0x1C8A24u);
    ctx->pc = 0x1C8A20u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1C8A1Cu;
            // 0x1c8a20: 0x622821  addu        $a1, $v1, $v0 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 2)));
        ctx->in_delay_slot = false;
    ctx->pc = 0x107AB0u;
    if (runtime->hasFunction(0x107AB0u)) {
        auto targetFn = runtime->lookupFunction(0x107AB0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1C8A24u; }
        if (ctx->pc != 0x1C8A24u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00107AB0_0x107ab0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1C8A24u; }
        if (ctx->pc != 0x1C8A24u) { return; }
    }
    ctx->pc = 0x1C8A24u;
label_1c8a24:
    // 0x1c8a24: 0x8e230004  lw          $v1, 0x4($s1)
    ctx->pc = 0x1c8a24u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 4)));
    // 0x1c8a28: 0x701821  addu        $v1, $v1, $s0
    ctx->pc = 0x1c8a28u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 16)));
    // 0x1c8a2c: 0xae230004  sw          $v1, 0x4($s1)
    ctx->pc = 0x1c8a2cu;
    WRITE32(ADD32(GPR_U32(ctx, 17), 4), GPR_U32(ctx, 3));
    // 0x1c8a30: 0xdfbf0030  ld          $ra, 0x30($sp)
    ctx->pc = 0x1c8a30u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 48)));
    // 0x1c8a34: 0x7bb20020  lq          $s2, 0x20($sp)
    ctx->pc = 0x1c8a34u;
    SET_GPR_VEC(ctx, 18, READ128(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x1c8a38: 0x7bb10010  lq          $s1, 0x10($sp)
    ctx->pc = 0x1c8a38u;
    SET_GPR_VEC(ctx, 17, READ128(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x1c8a3c: 0x7bb00000  lq          $s0, 0x0($sp)
    ctx->pc = 0x1c8a3cu;
    SET_GPR_VEC(ctx, 16, READ128(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1c8a40: 0x3e00008  jr          $ra
    ctx->pc = 0x1C8A40u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1C8A44u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1C8A40u;
            // 0x1c8a44: 0x27bd0040  addiu       $sp, $sp, 0x40 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 64));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1C8A0Cu: goto label_1c8a0c;
            case 0x1C8A24u: goto label_1c8a24;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1C8A48u;
    // 0x1c8a48: 0x0  nop
    ctx->pc = 0x1c8a48u;
    // NOP
    // 0x1c8a4c: 0x0  nop
    ctx->pc = 0x1c8a4cu;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
