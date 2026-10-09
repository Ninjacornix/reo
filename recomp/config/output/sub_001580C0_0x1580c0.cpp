#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001580C0
// Address: 0x1580c0 - 0x158158
void sub_001580C0_0x1580c0(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001580C0_0x1580c0");
#endif

    switch (ctx->pc) {
        case 0x158100u: goto label_158100;
        case 0x158108u: goto label_158108;
        case 0x158120u: goto label_158120;
        default: break;
    }

    ctx->pc = 0x1580c0u;

    // 0x1580c0: 0x27bdffe0  addiu       $sp, $sp, -0x20
    ctx->pc = 0x1580c0u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967264));
    // 0x1580c4: 0xa0102d  daddu       $v0, $a1, $zero
    ctx->pc = 0x1580c4u;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1580c8: 0xffb10008  sd          $s1, 0x8($sp)
    ctx->pc = 0x1580c8u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 8), GPR_U64(ctx, 17));
    // 0x1580cc: 0x80882d  daddu       $s1, $a0, $zero
    ctx->pc = 0x1580ccu;
    SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1580d0: 0xffb00000  sd          $s0, 0x0($sp)
    ctx->pc = 0x1580d0u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x1580d4: 0x3c100023  lui         $s0, 0x23
    ctx->pc = 0x1580d4u;
    SET_GPR_S32(ctx, 16, (int32_t)((uint32_t)35 << 16));
    // 0x1580d8: 0x113040  sll         $a2, $s1, 1
    ctx->pc = 0x1580d8u;
    SET_GPR_S32(ctx, 6, (int32_t)SLL32(GPR_U32(ctx, 17), 1));
    // 0x1580dc: 0x2610d870  addiu       $s0, $s0, -0x2790
    ctx->pc = 0x1580dcu;
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 16), 4294957168));
    // 0x1580e0: 0xd13021  addu        $a2, $a2, $s1
    ctx->pc = 0x1580e0u;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 6), GPR_U32(ctx, 17)));
    // 0x1580e4: 0xffbf0010  sd          $ra, 0x10($sp)
    ctx->pc = 0x1580e4u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 31));
    // 0x1580e8: 0x63100  sll         $a2, $a2, 4
    ctx->pc = 0x1580e8u;
    SET_GPR_S32(ctx, 6, (int32_t)SLL32(GPR_U32(ctx, 6), 4));
    // 0x1580ec: 0xae020000  sw          $v0, 0x0($s0)
    ctx->pc = 0x1580ecu;
    WRITE32(ADD32(GPR_U32(ctx, 16), 0), GPR_U32(ctx, 2));
    // 0x1580f0: 0x40202d  daddu       $a0, $v0, $zero
    ctx->pc = 0x1580f0u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1580f4: 0x24c60004  addiu       $a2, $a2, 0x4
    ctx->pc = 0x1580f4u;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 6), 4));
    // 0x1580f8: 0xc0558b4  jal         func_1562D0
    ctx->pc = 0x1580F8u;
    SET_GPR_U32(ctx, 31, 0x158100u);
    ctx->pc = 0x1580FCu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1580F8u;
            // 0x1580fc: 0x282d  daddu       $a1, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1562D0u;
    if (runtime->hasFunction(0x1562D0u)) {
        auto targetFn = runtime->lookupFunction(0x1562D0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x158100u; }
        if (ctx->pc != 0x158100u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001562D0_0x1562d0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x158100u; }
        if (ctx->pc != 0x158100u) { return; }
    }
    ctx->pc = 0x158100u;
label_158100:
    // 0x158100: 0xc056074  jal         func_1581D0
    ctx->pc = 0x158100u;
    SET_GPR_U32(ctx, 31, 0x158108u);
    ctx->pc = 0x158104u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x158100u;
            // 0x158104: 0x8e040000  lw          $a0, 0x0($s0) (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 0)));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1581D0u;
    if (runtime->hasFunction(0x1581D0u)) {
        auto targetFn = runtime->lookupFunction(0x1581D0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x158108u; }
        if (ctx->pc != 0x158108u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001581D0_0x1581d0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x158108u; }
        if (ctx->pc != 0x158108u) { return; }
    }
    ctx->pc = 0x158108u;
label_158108:
    // 0x158108: 0x8e020000  lw          $v0, 0x0($s0)
    ctx->pc = 0x158108u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 0)));
    // 0x15810c: 0xac51000c  sw          $s1, 0xC($v0)
    ctx->pc = 0x15810cu;
    WRITE32(ADD32(GPR_U32(ctx, 2), 12), GPR_U32(ctx, 17));
    // 0x158110: 0x1a20000a  blez        $s1, . + 4 + (0xA << 2)
    ctx->pc = 0x158110u;
    {
        const bool branch_taken_0x158110 = (GPR_S64(ctx, 17) <= 0);
        ctx->pc = 0x158114u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x158110u;
            // 0x158114: 0x24420010  addiu       $v0, $v0, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 16));
        ctx->in_delay_slot = false;
        if (branch_taken_0x158110) {
            ctx->pc = 0x15813Cu;
            goto label_15813c;
        }
    }
    ctx->pc = 0x158118u;
    // 0x158118: 0x220202d  daddu       $a0, $s1, $zero
    ctx->pc = 0x158118u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
    // 0x15811c: 0x24030001  addiu       $v1, $zero, 0x1
    ctx->pc = 0x15811cu;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
label_158120:
    // 0x158120: 0x2484ffff  addiu       $a0, $a0, -0x1
    ctx->pc = 0x158120u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 4294967295));
    // 0x158124: 0xac430000  sw          $v1, 0x0($v0)
    ctx->pc = 0x158124u;
    WRITE32(ADD32(GPR_U32(ctx, 2), 0), GPR_U32(ctx, 3));
    // 0x158128: 0x0  nop
    ctx->pc = 0x158128u;
    // NOP
    // 0x15812c: 0x0  nop
    ctx->pc = 0x15812cu;
    // NOP
    // 0x158130: 0x0  nop
    ctx->pc = 0x158130u;
    // NOP
    // 0x158134: 0x1480fffa  bnez        $a0, . + 4 + (-0x6 << 2)
    ctx->pc = 0x158134u;
    {
        const bool branch_taken_0x158134 = (GPR_U64(ctx, 4) != GPR_U64(ctx, 0));
        ctx->pc = 0x158138u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x158134u;
            // 0x158138: 0x244200c0  addiu       $v0, $v0, 0xC0 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 192));
        ctx->in_delay_slot = false;
        if (branch_taken_0x158134) {
            ctx->pc = 0x158120u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_158120;
        }
    }
    ctx->pc = 0x15813Cu;
label_15813c:
    // 0x15813c: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x15813cu;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x158140: 0x102d  daddu       $v0, $zero, $zero
    ctx->pc = 0x158140u;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x158144: 0xdfb10008  ld          $s1, 0x8($sp)
    ctx->pc = 0x158144u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x158148: 0xdfbf0010  ld          $ra, 0x10($sp)
    ctx->pc = 0x158148u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x15814c: 0x3e00008  jr          $ra
    ctx->pc = 0x15814Cu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x158150u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x15814Cu;
            // 0x158150: 0x27bd0020  addiu       $sp, $sp, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x158100u: goto label_158100;
            case 0x158108u: goto label_158108;
            case 0x158120u: goto label_158120;
            case 0x15813Cu: goto label_15813c;
            default: break;
        }
        return;
    }
    ctx->pc = 0x158154u;
    // 0x158154: 0x0  nop
    ctx->pc = 0x158154u;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
