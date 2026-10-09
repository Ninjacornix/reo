#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00140CC0
// Address: 0x140cc0 - 0x140d2c
void sub_00140CC0_0x140cc0(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00140CC0_0x140cc0");
#endif

    switch (ctx->pc) {
        case 0x140d08u: goto label_140d08;
        default: break;
    }

    ctx->pc = 0x140cc0u;

    // 0x140cc0: 0x27bdffe0  addiu       $sp, $sp, -0x20
    ctx->pc = 0x140cc0u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967264));
    // 0x140cc4: 0x3c020026  lui         $v0, 0x26
    ctx->pc = 0x140cc4u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)38 << 16));
    // 0x140cc8: 0xffb00000  sd          $s0, 0x0($sp)
    ctx->pc = 0x140cc8u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x140ccc: 0x3c100026  lui         $s0, 0x26
    ctx->pc = 0x140cccu;
    SET_GPR_S32(ctx, 16, (int32_t)((uint32_t)38 << 16));
    // 0x140cd0: 0x24424600  addiu       $v0, $v0, 0x4600
    ctx->pc = 0x140cd0u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 17920));
    // 0x140cd4: 0xffb10008  sd          $s1, 0x8($sp)
    ctx->pc = 0x140cd4u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 8), GPR_U64(ctx, 17));
    // 0x140cd8: 0xffbf0010  sd          $ra, 0x10($sp)
    ctx->pc = 0x140cd8u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 31));
    // 0x140cdc: 0x26104700  addiu       $s0, $s0, 0x4700
    ctx->pc = 0x140cdcu;
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 16), 18176));
    // 0x140ce0: 0xac440000  sw          $a0, 0x0($v0)
    ctx->pc = 0x140ce0u;
    WRITE32(ADD32(GPR_U32(ctx, 2), 0), GPR_U32(ctx, 4));
    // 0x140ce4: 0x24040026  addiu       $a0, $zero, 0x26
    ctx->pc = 0x140ce4u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 38));
    // 0x140ce8: 0xac450004  sw          $a1, 0x4($v0)
    ctx->pc = 0x140ce8u;
    WRITE32(ADD32(GPR_U32(ctx, 2), 4), GPR_U32(ctx, 5));
    // 0x140cec: 0x40282d  daddu       $a1, $v0, $zero
    ctx->pc = 0x140cecu;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x140cf0: 0xac460008  sw          $a2, 0x8($v0)
    ctx->pc = 0x140cf0u;
    WRITE32(ADD32(GPR_U32(ctx, 2), 8), GPR_U32(ctx, 6));
    // 0x140cf4: 0x24060003  addiu       $a2, $zero, 0x3
    ctx->pc = 0x140cf4u;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 0), 3));
    // 0x140cf8: 0xe0882d  daddu       $s1, $a3, $zero
    ctx->pc = 0x140cf8u;
    SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 7) + (uint64_t)GPR_U64(ctx, 0));
    // 0x140cfc: 0x200382d  daddu       $a3, $s0, $zero
    ctx->pc = 0x140cfcu;
    SET_GPR_U64(ctx, 7, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x140d00: 0xc04e518  jal         func_139460
    ctx->pc = 0x140D00u;
    SET_GPR_U32(ctx, 31, 0x140D08u);
    ctx->pc = 0x140D04u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x140D00u;
            // 0x140d04: 0x24080002  addiu       $t0, $zero, 0x2 (Delay Slot)
        SET_GPR_S32(ctx, 8, (int32_t)ADD32(GPR_U32(ctx, 0), 2));
        ctx->in_delay_slot = false;
    ctx->pc = 0x139460u;
    if (runtime->hasFunction(0x139460u)) {
        auto targetFn = runtime->lookupFunction(0x139460u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x140D08u; }
        if (ctx->pc != 0x140D08u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00139460_0x139460(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x140D08u; }
        if (ctx->pc != 0x140D08u) { return; }
    }
    ctx->pc = 0x140D08u;
label_140d08:
    // 0x140d08: 0x8e030000  lw          $v1, 0x0($s0)
    ctx->pc = 0x140d08u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 0)));
    // 0x140d0c: 0x8e020004  lw          $v0, 0x4($s0)
    ctx->pc = 0x140d0cu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 4)));
    // 0x140d10: 0xae230000  sw          $v1, 0x0($s1)
    ctx->pc = 0x140d10u;
    WRITE32(ADD32(GPR_U32(ctx, 17), 0), GPR_U32(ctx, 3));
    // 0x140d14: 0xae220004  sw          $v0, 0x4($s1)
    ctx->pc = 0x140d14u;
    WRITE32(ADD32(GPR_U32(ctx, 17), 4), GPR_U32(ctx, 2));
    // 0x140d18: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x140d18u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x140d1c: 0xdfb10008  ld          $s1, 0x8($sp)
    ctx->pc = 0x140d1cu;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x140d20: 0xdfbf0010  ld          $ra, 0x10($sp)
    ctx->pc = 0x140d20u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x140d24: 0x3e00008  jr          $ra
    ctx->pc = 0x140D24u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x140D28u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x140D24u;
            // 0x140d28: 0x27bd0020  addiu       $sp, $sp, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x140D08u: goto label_140d08;
            default: break;
        }
        return;
    }
    ctx->pc = 0x140D2Cu;
    ctx->pc = GPR_U32(ctx, 31); return;
}
