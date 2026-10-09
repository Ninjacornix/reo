#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001A7C50
// Address: 0x1a7c50 - 0x1a7ce8
void sub_001A7C50_0x1a7c50(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001A7C50_0x1a7c50");
#endif

    switch (ctx->pc) {
        case 0x1a7c90u: goto label_1a7c90;
        default: break;
    }

    ctx->pc = 0x1a7c50u;

    // 0x1a7c50: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x1a7c50u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x1a7c54: 0x3c02002b  lui         $v0, 0x2B
    ctx->pc = 0x1a7c54u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)43 << 16));
    // 0x1a7c58: 0xffbf0000  sd          $ra, 0x0($sp)
    ctx->pc = 0x1a7c58u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 31));
    // 0x1a7c5c: 0x3c01002b  lui         $at, 0x2B
    ctx->pc = 0x1a7c5cu;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)43 << 16));
    // 0x1a7c60: 0x8c250a68  lw          $a1, 0xA68($at)
    ctx->pc = 0x1a7c60u;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 1), 2664)));
    // 0x1a7c64: 0x24420a80  addiu       $v0, $v0, 0xA80
    ctx->pc = 0x1a7c64u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 2688));
    // 0x1a7c68: 0x51840  sll         $v1, $a1, 1
    ctx->pc = 0x1a7c68u;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 5), 1));
    // 0x1a7c6c: 0x651821  addu        $v1, $v1, $a1
    ctx->pc = 0x1a7c6cu;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 5)));
    // 0x1a7c70: 0x31880  sll         $v1, $v1, 2
    ctx->pc = 0x1a7c70u;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 3), 2));
    // 0x1a7c74: 0x432821  addu        $a1, $v0, $v1
    ctx->pc = 0x1a7c74u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 3)));
    // 0x1a7c78: 0x8ca20000  lw          $v0, 0x0($a1)
    ctx->pc = 0x1a7c78u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 5), 0)));
    // 0x1a7c7c: 0x4400006  bltz        $v0, . + 4 + (0x6 << 2)
    ctx->pc = 0x1A7C7Cu;
    {
        const bool branch_taken_0x1a7c7c = (GPR_S64(ctx, 2) < 0);
        ctx->pc = 0x1A7C80u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1A7C7Cu;
            // 0x1a7c80: 0x4182b  sltu        $v1, $zero, $a0 (Delay Slot)
        SET_GPR_U64(ctx, 3, ((uint64_t)GPR_U64(ctx, 0) < (uint64_t)GPR_U64(ctx, 4)) ? 1 : 0);
        ctx->in_delay_slot = false;
        if (branch_taken_0x1a7c7c) {
            ctx->pc = 0x1A7C98u;
            goto label_1a7c98;
        }
    }
    ctx->pc = 0x1A7C84u;
    // 0x1a7c84: 0x3c040024  lui         $a0, 0x24
    ctx->pc = 0x1a7c84u;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)36 << 16));
    // 0x1a7c88: 0xc0423b4  jal         func_108ED0
    ctx->pc = 0x1A7C88u;
    SET_GPR_U32(ctx, 31, 0x1A7C90u);
    ctx->pc = 0x1A7C8Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1A7C88u;
            // 0x1a7c8c: 0x24842320  addiu       $a0, $a0, 0x2320 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 8992));
        ctx->in_delay_slot = false;
    ctx->pc = 0x108ED0u;
    if (runtime->hasFunction(0x108ED0u)) {
        auto targetFn = runtime->lookupFunction(0x108ED0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1A7C90u; }
        if (ctx->pc != 0x1A7C90u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00108ED0_0x108ed0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1A7C90u; }
        if (ctx->pc != 0x1A7C90u) { return; }
    }
    ctx->pc = 0x1A7C90u;
label_1a7c90:
    // 0x1a7c90: 0x10000012  b           . + 4 + (0x12 << 2)
    ctx->pc = 0x1A7C90u;
    {
        const bool branch_taken_0x1a7c90 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1A7C94u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1A7C90u;
            // 0x1a7c94: 0x2402ffff  addiu       $v0, $zero, -0x1 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1a7c90) {
            ctx->pc = 0x1A7CDCu;
            goto label_1a7cdc;
        }
    }
    ctx->pc = 0x1A7C98u;
label_1a7c98:
    // 0x1a7c98: 0x3c024200  lui         $v0, 0x4200
    ctx->pc = 0x1a7c98u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)16896 << 16));
    // 0x1a7c9c: 0x31c00  sll         $v1, $v1, 16
    ctx->pc = 0x1a7c9cu;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 3), 16));
    // 0x1a7ca0: 0x3c01002b  lui         $at, 0x2B
    ctx->pc = 0x1a7ca0u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)43 << 16));
    // 0x1a7ca4: 0x31a3c  dsll32      $v1, $v1, 8
    ctx->pc = 0x1a7ca4u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) << (32 + 8));
    // 0x1a7ca8: 0x31a3e  dsrl32      $v1, $v1, 8
    ctx->pc = 0x1a7ca8u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) >> (32 + 8));
    // 0x1a7cac: 0x621025  or          $v0, $v1, $v0
    ctx->pc = 0x1a7cacu;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 3) | GPR_U64(ctx, 2));
    // 0x1a7cb0: 0xaca20000  sw          $v0, 0x0($a1)
    ctx->pc = 0x1a7cb0u;
    WRITE32(ADD32(GPR_U32(ctx, 5), 0), GPR_U32(ctx, 2));
    // 0x1a7cb4: 0x8c220a68  lw          $v0, 0xA68($at)
    ctx->pc = 0x1a7cb4u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 1), 2664)));
    // 0x1a7cb8: 0x24430001  addiu       $v1, $v0, 0x1
    ctx->pc = 0x1a7cb8u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 2), 1));
    // 0x1a7cbc: 0x4610004  bgez        $v1, . + 4 + (0x4 << 2)
    ctx->pc = 0x1A7CBCu;
    {
        const bool branch_taken_0x1a7cbc = (GPR_S64(ctx, 3) >= 0);
        ctx->pc = 0x1A7CC0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1A7CBCu;
            // 0x1a7cc0: 0x3062001f  andi        $v0, $v1, 0x1F (Delay Slot)
        SET_GPR_U64(ctx, 2, GPR_U64(ctx, 3) & (uint64_t)(uint16_t)31);
        ctx->in_delay_slot = false;
        if (branch_taken_0x1a7cbc) {
            ctx->pc = 0x1A7CD0u;
            goto label_1a7cd0;
        }
    }
    ctx->pc = 0x1A7CC4u;
    // 0x1a7cc4: 0x10400002  beqz        $v0, . + 4 + (0x2 << 2)
    ctx->pc = 0x1A7CC4u;
    {
        const bool branch_taken_0x1a7cc4 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        if (branch_taken_0x1a7cc4) {
            ctx->pc = 0x1A7CD0u;
            goto label_1a7cd0;
        }
    }
    ctx->pc = 0x1A7CCCu;
    // 0x1a7ccc: 0x2442ffe0  addiu       $v0, $v0, -0x20
    ctx->pc = 0x1a7cccu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 4294967264));
label_1a7cd0:
    // 0x1a7cd0: 0x3c01002b  lui         $at, 0x2B
    ctx->pc = 0x1a7cd0u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)43 << 16));
    // 0x1a7cd4: 0xac220a68  sw          $v0, 0xA68($at)
    ctx->pc = 0x1a7cd4u;
    WRITE32(ADD32(GPR_U32(ctx, 1), 2664), GPR_U32(ctx, 2));
    // 0x1a7cd8: 0x102d  daddu       $v0, $zero, $zero
    ctx->pc = 0x1a7cd8u;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
label_1a7cdc:
    // 0x1a7cdc: 0xdfbf0000  ld          $ra, 0x0($sp)
    ctx->pc = 0x1a7cdcu;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1a7ce0: 0x3e00008  jr          $ra
    ctx->pc = 0x1A7CE0u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1A7CE4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1A7CE0u;
            // 0x1a7ce4: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1A7C90u: goto label_1a7c90;
            case 0x1A7C98u: goto label_1a7c98;
            case 0x1A7CD0u: goto label_1a7cd0;
            case 0x1A7CDCu: goto label_1a7cdc;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1A7CE8u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
