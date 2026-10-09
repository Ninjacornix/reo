#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_0010A970
// Address: 0x10a970 - 0x10a9d4
void sub_0010A970_0x10a970(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_0010A970_0x10a970");
#endif

    switch (ctx->pc) {
        case 0x10a994u: goto label_10a994;
        default: break;
    }

    ctx->pc = 0x10a970u;

    // 0x10a970: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x10a970u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x10a974: 0xc0382d  daddu       $a3, $a2, $zero
    ctx->pc = 0x10a974u;
    SET_GPR_U64(ctx, 7, (uint64_t)GPR_U64(ctx, 6) + (uint64_t)GPR_U64(ctx, 0));
    // 0x10a978: 0xffb00000  sd          $s0, 0x0($sp)
    ctx->pc = 0x10a978u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x10a97c: 0x80802d  daddu       $s0, $a0, $zero
    ctx->pc = 0x10a97cu;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x10a980: 0xffbf0008  sd          $ra, 0x8($sp)
    ctx->pc = 0x10a980u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 8), GPR_U64(ctx, 31));
    // 0x10a984: 0xa0302d  daddu       $a2, $a1, $zero
    ctx->pc = 0x10a984u;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
    // 0x10a988: 0x8e040054  lw          $a0, 0x54($s0)
    ctx->pc = 0x10a988u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 84)));
    // 0x10a98c: 0xc04266c  jal         func_1099B0
    ctx->pc = 0x10A98Cu;
    SET_GPR_U32(ctx, 31, 0x10A994u);
    ctx->pc = 0x10A990u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x10A98Cu;
            // 0x10a990: 0x8605000e  lh          $a1, 0xE($s0) (Delay Slot)
        SET_GPR_S32(ctx, 5, (int16_t)READ16(ADD32(GPR_U32(ctx, 16), 14)));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1099B0u;
    if (runtime->hasFunction(0x1099B0u)) {
        auto targetFn = runtime->lookupFunction(0x1099B0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x10A994u; }
        if (ctx->pc != 0x10A994u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001099B0_0x1099b0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x10A994u; }
        if (ctx->pc != 0x10A994u) { return; }
    }
    ctx->pc = 0x10A994u;
label_10a994:
    // 0x10a994: 0x2203c  dsll32      $a0, $v0, 0
    ctx->pc = 0x10a994u;
    SET_GPR_U64(ctx, 4, GPR_U64(ctx, 2) << (32 + 0));
    // 0x10a998: 0x4203f  dsra32      $a0, $a0, 0
    ctx->pc = 0x10a998u;
    SET_GPR_S64(ctx, 4, GPR_S64(ctx, 4) >> (32 + 0));
    // 0x10a99c: 0x4800006  bltz        $a0, . + 4 + (0x6 << 2)
    ctx->pc = 0x10A99Cu;
    {
        const bool branch_taken_0x10a99c = (GPR_S64(ctx, 4) < 0);
        ctx->pc = 0x10A9A0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x10A99Cu;
            // 0x10a9a0: 0x80102d  daddu       $v0, $a0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x10a99c) {
            ctx->pc = 0x10A9B8u;
            goto label_10a9b8;
        }
    }
    ctx->pc = 0x10A9A4u;
    // 0x10a9a4: 0x8e030050  lw          $v1, 0x50($s0)
    ctx->pc = 0x10a9a4u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 80)));
    // 0x10a9a8: 0x641821  addu        $v1, $v1, $a0
    ctx->pc = 0x10a9a8u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 4)));
    // 0x10a9ac: 0x10000005  b           . + 4 + (0x5 << 2)
    ctx->pc = 0x10A9ACu;
    {
        const bool branch_taken_0x10a9ac = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x10A9B0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x10A9ACu;
            // 0x10a9b0: 0xae030050  sw          $v1, 0x50($s0) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 16), 80), GPR_U32(ctx, 3));
        ctx->in_delay_slot = false;
        if (branch_taken_0x10a9ac) {
            ctx->pc = 0x10A9C4u;
            goto label_10a9c4;
        }
    }
    ctx->pc = 0x10A9B4u;
    // 0x10a9b4: 0x0  nop
    ctx->pc = 0x10a9b4u;
    // NOP
label_10a9b8:
    // 0x10a9b8: 0x9603000c  lhu         $v1, 0xC($s0)
    ctx->pc = 0x10a9b8u;
    SET_GPR_U32(ctx, 3, (uint16_t)READ16(ADD32(GPR_U32(ctx, 16), 12)));
    // 0x10a9bc: 0x3063efff  andi        $v1, $v1, 0xEFFF
    ctx->pc = 0x10a9bcu;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) & (uint64_t)(uint16_t)61439);
    // 0x10a9c0: 0xa603000c  sh          $v1, 0xC($s0)
    ctx->pc = 0x10a9c0u;
    WRITE16(ADD32(GPR_U32(ctx, 16), 12), (uint16_t)GPR_U32(ctx, 3));
label_10a9c4:
    // 0x10a9c4: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x10a9c4u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x10a9c8: 0xdfbf0008  ld          $ra, 0x8($sp)
    ctx->pc = 0x10a9c8u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x10a9cc: 0x3e00008  jr          $ra
    ctx->pc = 0x10A9CCu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x10A9D0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x10A9CCu;
            // 0x10a9d0: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x10A994u: goto label_10a994;
            case 0x10A9B8u: goto label_10a9b8;
            case 0x10A9C4u: goto label_10a9c4;
            default: break;
        }
        return;
    }
    ctx->pc = 0x10A9D4u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
