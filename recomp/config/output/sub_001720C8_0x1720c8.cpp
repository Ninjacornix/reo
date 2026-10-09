#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001720C8
// Address: 0x1720c8 - 0x172158
void sub_001720C8_0x1720c8(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001720C8_0x1720c8");
#endif

    switch (ctx->pc) {
        case 0x1720e4u: goto label_1720e4;
        case 0x172138u: goto label_172138;
        default: break;
    }

    ctx->pc = 0x1720c8u;

    // 0x1720c8: 0x27bdffe0  addiu       $sp, $sp, -0x20
    ctx->pc = 0x1720c8u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967264));
    // 0x1720cc: 0xffb00000  sd          $s0, 0x0($sp)
    ctx->pc = 0x1720ccu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x1720d0: 0x80802d  daddu       $s0, $a0, $zero
    ctx->pc = 0x1720d0u;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1720d4: 0xffb10008  sd          $s1, 0x8($sp)
    ctx->pc = 0x1720d4u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 8), GPR_U64(ctx, 17));
    // 0x1720d8: 0xffbf0010  sd          $ra, 0x10($sp)
    ctx->pc = 0x1720d8u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 31));
    // 0x1720dc: 0xc05a78c  jal         func_169E30
    ctx->pc = 0x1720DCu;
    SET_GPR_U32(ctx, 31, 0x1720E4u);
    ctx->pc = 0x1720E0u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1720DCu;
            // 0x1720e0: 0xa0882d  daddu       $s1, $a1, $zero (Delay Slot)
        SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x169E30u;
    if (runtime->hasFunction(0x169E30u)) {
        auto targetFn = runtime->lookupFunction(0x169E30u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1720E4u; }
        if (ctx->pc != 0x1720E4u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00169E30_0x169e30(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1720E4u; }
        if (ctx->pc != 0x1720E4u) { return; }
    }
    ctx->pc = 0x1720E4u;
label_1720e4:
    // 0x1720e4: 0x3c05ff00  lui         $a1, 0xFF00
    ctx->pc = 0x1720e4u;
    SET_GPR_S32(ctx, 5, (int32_t)((uint32_t)65280 << 16));
    // 0x1720e8: 0x202d  daddu       $a0, $zero, $zero
    ctx->pc = 0x1720e8u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1720ec: 0x34a50142  ori         $a1, $a1, 0x142
    ctx->pc = 0x1720ecu;
    SET_GPR_U64(ctx, 5, GPR_U64(ctx, 5) | (uint64_t)(uint16_t)322);
    // 0x1720f0: 0x10400007  beqz        $v0, . + 4 + (0x7 << 2)
    ctx->pc = 0x1720F0u;
    {
        const bool branch_taken_0x1720f0 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x1720F4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1720F0u;
            // 0x1720f4: 0x24060001  addiu       $a2, $zero, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1720f0) {
            ctx->pc = 0x172110u;
            goto label_172110;
        }
    }
    ctx->pc = 0x1720F8u;
    // 0x1720f8: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x1720f8u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1720fc: 0xdfb10008  ld          $s1, 0x8($sp)
    ctx->pc = 0x1720fcu;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x172100: 0xdfbf0010  ld          $ra, 0x10($sp)
    ctx->pc = 0x172100u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x172104: 0x805a704  j           func_169C10
    ctx->pc = 0x172104u;
    ctx->pc = 0x172108u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x172104u;
            // 0x172108: 0x27bd0020  addiu       $sp, $sp, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
        ctx->in_delay_slot = false;
    ctx->pc = 0x169C10u;
    if (runtime->hasFunction(0x169C10u)) {
        auto targetFn = runtime->lookupFunction(0x169C10u);
        targetFn(rdram, ctx, runtime); return;
    } else {
        sub_00169C10_0x169c10(rdram, ctx, runtime); return;
    }
    ctx->pc = 0x17210Cu;
    // 0x17210c: 0x0  nop
    ctx->pc = 0x17210cu;
    // NOP
label_172110:
    // 0x172110: 0x8e040050  lw          $a0, 0x50($s0)
    ctx->pc = 0x172110u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 80)));
    // 0x172114: 0x24030002  addiu       $v1, $zero, 0x2
    ctx->pc = 0x172114u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 2));
    // 0x172118: 0x16200003  bnez        $s1, . + 4 + (0x3 << 2)
    ctx->pc = 0x172118u;
    {
        const bool branch_taken_0x172118 = (GPR_U64(ctx, 17) != GPR_U64(ctx, 0));
        ctx->pc = 0x17211Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x172118u;
            // 0x17211c: 0x64300b  movn        $a2, $v1, $a0 (Delay Slot)
        if (GPR_U64(ctx, 4) != 0) SET_GPR_VEC(ctx, 6, GPR_VEC(ctx, 3));
        ctx->in_delay_slot = false;
        if (branch_taken_0x172118) {
            ctx->pc = 0x172128u;
            goto label_172128;
        }
    }
    ctx->pc = 0x172120u;
    // 0x172120: 0x10800007  beqz        $a0, . + 4 + (0x7 << 2)
    ctx->pc = 0x172120u;
    {
        const bool branch_taken_0x172120 = (GPR_U64(ctx, 4) == GPR_U64(ctx, 0));
        ctx->pc = 0x172124u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x172120u;
            // 0x172124: 0x302d  daddu       $a2, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x172120) {
            ctx->pc = 0x172140u;
            goto label_172140;
        }
    }
    ctx->pc = 0x172128u;
label_172128:
    // 0x172128: 0xae110050  sw          $s1, 0x50($s0)
    ctx->pc = 0x172128u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 80), GPR_U32(ctx, 17));
    // 0x17212c: 0xc0282d  daddu       $a1, $a2, $zero
    ctx->pc = 0x17212cu;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 6) + (uint64_t)GPR_U64(ctx, 0));
    // 0x172130: 0xc05c856  jal         func_172158
    ctx->pc = 0x172130u;
    SET_GPR_U32(ctx, 31, 0x172138u);
    ctx->pc = 0x172134u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x172130u;
            // 0x172134: 0x200202d  daddu       $a0, $s0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x172158u;
    if (runtime->hasFunction(0x172158u)) {
        auto targetFn = runtime->lookupFunction(0x172158u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x172138u; }
        if (ctx->pc != 0x172138u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00172158_0x172158(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x172138u; }
        if (ctx->pc != 0x172138u) { return; }
    }
    ctx->pc = 0x172138u;
label_172138:
    // 0x172138: 0x24030001  addiu       $v1, $zero, 0x1
    ctx->pc = 0x172138u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x17213c: 0xae030044  sw          $v1, 0x44($s0)
    ctx->pc = 0x17213cu;
    WRITE32(ADD32(GPR_U32(ctx, 16), 68), GPR_U32(ctx, 3));
label_172140:
    // 0x172140: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x172140u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x172144: 0xdfb10008  ld          $s1, 0x8($sp)
    ctx->pc = 0x172144u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x172148: 0xdfbf0010  ld          $ra, 0x10($sp)
    ctx->pc = 0x172148u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x17214c: 0x3e00008  jr          $ra
    ctx->pc = 0x17214Cu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x172150u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x17214Cu;
            // 0x172150: 0x27bd0020  addiu       $sp, $sp, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1720E4u: goto label_1720e4;
            case 0x172110u: goto label_172110;
            case 0x172128u: goto label_172128;
            case 0x172138u: goto label_172138;
            case 0x172140u: goto label_172140;
            default: break;
        }
        return;
    }
    ctx->pc = 0x172154u;
    // 0x172154: 0x0  nop
    ctx->pc = 0x172154u;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
