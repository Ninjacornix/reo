#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_0011F5A0
// Address: 0x11f5a0 - 0x11f618
void sub_0011F5A0_0x11f5a0(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_0011F5A0_0x11f5a0");
#endif

    switch (ctx->pc) {
        case 0x11f5e4u: goto label_11f5e4;
        default: break;
    }

    ctx->pc = 0x11f5a0u;

    // 0x11f5a0: 0x27bdffe0  addiu       $sp, $sp, -0x20
    ctx->pc = 0x11f5a0u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967264));
    // 0x11f5a4: 0x41202  srl         $v0, $a0, 8
    ctx->pc = 0x11f5a4u;
    SET_GPR_S32(ctx, 2, (int32_t)SRL32(GPR_U32(ctx, 4), 8));
    // 0x11f5a8: 0xffb00000  sd          $s0, 0x0($sp)
    ctx->pc = 0x11f5a8u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x11f5ac: 0xffbf0010  sd          $ra, 0x10($sp)
    ctx->pc = 0x11f5acu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 31));
    // 0x11f5b0: 0x4800006  bltz        $a0, . + 4 + (0x6 << 2)
    ctx->pc = 0x11F5B0u;
    {
        const bool branch_taken_0x11f5b0 = (GPR_S64(ctx, 4) < 0);
        ctx->pc = 0x11F5B4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x11F5B0u;
            // 0x11f5b4: 0x28100  sll         $s0, $v0, 4 (Delay Slot)
        SET_GPR_S32(ctx, 16, (int32_t)SLL32(GPR_U32(ctx, 2), 4));
        ctx->in_delay_slot = false;
        if (branch_taken_0x11f5b0) {
            ctx->pc = 0x11F5CCu;
            goto label_11f5cc;
        }
    }
    ctx->pc = 0x11F5B8u;
    // 0x11f5b8: 0x8e020004  lw          $v0, 0x4($s0)
    ctx->pc = 0x11f5b8u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 4)));
    // 0x11f5bc: 0x821026  xor         $v0, $a0, $v0
    ctx->pc = 0x11f5bcu;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 4) ^ GPR_U64(ctx, 2));
    // 0x11f5c0: 0x304200ff  andi        $v0, $v0, 0xFF
    ctx->pc = 0x11f5c0u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) & (uint64_t)(uint16_t)255);
    // 0x11f5c4: 0x10400004  beqz        $v0, . + 4 + (0x4 << 2)
    ctx->pc = 0x11F5C4u;
    {
        const bool branch_taken_0x11f5c4 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        if (branch_taken_0x11f5c4) {
            ctx->pc = 0x11F5D8u;
            goto label_11f5d8;
        }
    }
    ctx->pc = 0x11F5CCu;
label_11f5cc:
    // 0x11f5cc: 0x3c028000  lui         $v0, 0x8000
    ctx->pc = 0x11f5ccu;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)32768 << 16));
    // 0x11f5d0: 0x1000000d  b           . + 4 + (0xD << 2)
    ctx->pc = 0x11F5D0u;
    {
        const bool branch_taken_0x11f5d0 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x11F5D4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x11F5D0u;
            // 0x11f5d4: 0x34428002  ori         $v0, $v0, 0x8002 (Delay Slot)
        SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) | (uint64_t)(uint16_t)32770);
        ctx->in_delay_slot = false;
        if (branch_taken_0x11f5d0) {
            ctx->pc = 0x11F608u;
            goto label_11f608;
        }
    }
    ctx->pc = 0x11F5D8u;
label_11f5d8:
    // 0x11f5d8: 0x8e040004  lw          $a0, 0x4($s0)
    ctx->pc = 0x11f5d8u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 4)));
    // 0x11f5dc: 0xc047a4a  jal         func_11E928
    ctx->pc = 0x11F5DCu;
    SET_GPR_U32(ctx, 31, 0x11F5E4u);
    ctx->pc = 0x11E928u;
    if (runtime->hasFunction(0x11E928u)) {
        auto targetFn = runtime->lookupFunction(0x11E928u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x11F5E4u; }
        if (ctx->pc != 0x11F5E4u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0011E928_0x11e928(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x11F5E4u; }
        if (ctx->pc != 0x11F5E4u) { return; }
    }
    ctx->pc = 0x11F5E4u;
label_11f5e4:
    // 0x11f5e4: 0x40202d  daddu       $a0, $v0, $zero
    ctx->pc = 0x11f5e4u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x11f5e8: 0x14800007  bnez        $a0, . + 4 + (0x7 << 2)
    ctx->pc = 0x11F5E8u;
    {
        const bool branch_taken_0x11f5e8 = (GPR_U64(ctx, 4) != GPR_U64(ctx, 0));
        ctx->pc = 0x11F5ECu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x11F5E8u;
            // 0x11f5ec: 0x80102d  daddu       $v0, $a0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x11f5e8) {
            ctx->pc = 0x11F608u;
            goto label_11f608;
        }
    }
    ctx->pc = 0x11F5F0u;
    // 0x11f5f0: 0x3c020026  lui         $v0, 0x26
    ctx->pc = 0x11f5f0u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)38 << 16));
    // 0x11f5f4: 0x8c431d00  lw          $v1, 0x1D00($v0)
    ctx->pc = 0x11f5f4u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 7424)));
    // 0x11f5f8: 0xac501d00  sw          $s0, 0x1D00($v0)
    ctx->pc = 0x11f5f8u;
    WRITE32(ADD32(GPR_U32(ctx, 2), 7424), GPR_U32(ctx, 16));
    // 0x11f5fc: 0xae030000  sw          $v1, 0x0($s0)
    ctx->pc = 0x11f5fcu;
    WRITE32(ADD32(GPR_U32(ctx, 16), 0), GPR_U32(ctx, 3));
    // 0x11f600: 0xae000004  sw          $zero, 0x4($s0)
    ctx->pc = 0x11f600u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 4), GPR_U32(ctx, 0));
    // 0x11f604: 0x80102d  daddu       $v0, $a0, $zero
    ctx->pc = 0x11f604u;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
label_11f608:
    // 0x11f608: 0xdfbf0010  ld          $ra, 0x10($sp)
    ctx->pc = 0x11f608u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x11f60c: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x11f60cu;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x11f610: 0x3e00008  jr          $ra
    ctx->pc = 0x11F610u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x11F614u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x11F610u;
            // 0x11f614: 0x27bd0020  addiu       $sp, $sp, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x11F5CCu: goto label_11f5cc;
            case 0x11F5D8u: goto label_11f5d8;
            case 0x11F5E4u: goto label_11f5e4;
            case 0x11F608u: goto label_11f608;
            default: break;
        }
        return;
    }
    ctx->pc = 0x11F618u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
