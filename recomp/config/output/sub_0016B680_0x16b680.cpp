#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_0016B680
// Address: 0x16b680 - 0x16b738
void sub_0016B680_0x16b680(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_0016B680_0x16b680");
#endif

    switch (ctx->pc) {
        case 0x16b694u: goto label_16b694;
        default: break;
    }

    ctx->pc = 0x16b680u;

    // 0x16b680: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x16b680u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x16b684: 0xffb00000  sd          $s0, 0x0($sp)
    ctx->pc = 0x16b684u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x16b688: 0xffbf0008  sd          $ra, 0x8($sp)
    ctx->pc = 0x16b688u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 8), GPR_U64(ctx, 31));
    // 0x16b68c: 0xc05aee6  jal         func_16BB98
    ctx->pc = 0x16B68Cu;
    SET_GPR_U32(ctx, 31, 0x16B694u);
    ctx->pc = 0x16B690u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x16B68Cu;
            // 0x16b690: 0x80802d  daddu       $s0, $a0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x16BB98u;
    if (runtime->hasFunction(0x16BB98u)) {
        auto targetFn = runtime->lookupFunction(0x16BB98u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x16B694u; }
        if (ctx->pc != 0x16B694u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0016BB98_0x16bb98(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x16B694u; }
        if (ctx->pc != 0x16B694u) { return; }
    }
    ctx->pc = 0x16B694u;
label_16b694:
    // 0x16b694: 0x40282d  daddu       $a1, $v0, $zero
    ctx->pc = 0x16b694u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x16b698: 0x10a00022  beqz        $a1, . + 4 + (0x22 << 2)
    ctx->pc = 0x16B698u;
    {
        const bool branch_taken_0x16b698 = (GPR_U64(ctx, 5) == GPR_U64(ctx, 0));
        ctx->pc = 0x16B69Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x16B698u;
            // 0x16b69c: 0x3c027fff  lui         $v0, 0x7FFF (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)32767 << 16));
        ctx->in_delay_slot = false;
        if (branch_taken_0x16b698) {
            ctx->pc = 0x16B724u;
            goto label_16b724;
        }
    }
    ctx->pc = 0x16B6A0u;
    // 0x16b6a0: 0x8e061aec  lw          $a2, 0x1AEC($s0)
    ctx->pc = 0x16b6a0u;
    SET_GPR_S32(ctx, 6, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 6892)));
    // 0x16b6a4: 0x3442ffff  ori         $v0, $v0, 0xFFFF
    ctx->pc = 0x16b6a4u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) | (uint64_t)(uint16_t)65535);
    // 0x16b6a8: 0x26070cc0  addiu       $a3, $s0, 0xCC0
    ctx->pc = 0x16b6a8u;
    SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 16), 3264));
    // 0x16b6ac: 0x8cc30010  lw          $v1, 0x10($a2)
    ctx->pc = 0x16b6acu;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 6), 16)));
    // 0x16b6b0: 0x1062001c  beq         $v1, $v0, . + 4 + (0x1C << 2)
    ctx->pc = 0x16B6B0u;
    {
        const bool branch_taken_0x16b6b0 = (GPR_U64(ctx, 3) == GPR_U64(ctx, 2));
        ctx->pc = 0x16B6B4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x16B6B0u;
            // 0x16b6b4: 0x2604090c  addiu       $a0, $s0, 0x90C (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 16), 2316));
        ctx->in_delay_slot = false;
        if (branch_taken_0x16b6b0) {
            ctx->pc = 0x16B724u;
            goto label_16b724;
        }
    }
    ctx->pc = 0x16B6B8u;
    // 0x16b6b8: 0x8ca20018  lw          $v0, 0x18($a1)
    ctx->pc = 0x16b6b8u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 5), 24)));
    // 0x16b6bc: 0x621023  subu        $v0, $v1, $v0
    ctx->pc = 0x16b6bcu;
    SET_GPR_S32(ctx, 2, (int32_t)SUB32(GPR_U32(ctx, 3), GPR_U32(ctx, 2)));
    // 0x16b6c0: 0xace20118  sw          $v0, 0x118($a3)
    ctx->pc = 0x16b6c0u;
    WRITE32(ADD32(GPR_U32(ctx, 7), 280), GPR_U32(ctx, 2));
    // 0x16b6c4: 0x8ca30000  lw          $v1, 0x0($a1)
    ctx->pc = 0x16b6c4u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 5), 0)));
    // 0x16b6c8: 0x14600017  bnez        $v1, . + 4 + (0x17 << 2)
    ctx->pc = 0x16B6C8u;
    {
        const bool branch_taken_0x16b6c8 = (GPR_U64(ctx, 3) != GPR_U64(ctx, 0));
        ctx->pc = 0x16B6CCu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x16B6C8u;
            // 0x16b6cc: 0xdfb00000  ld          $s0, 0x0($sp) (Delay Slot)
        SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x16b6c8) {
            ctx->pc = 0x16B728u;
            goto label_16b728;
        }
    }
    ctx->pc = 0x16B6D0u;
    // 0x16b6d0: 0x8c830018  lw          $v1, 0x18($a0)
    ctx->pc = 0x16b6d0u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 24)));
    // 0x16b6d4: 0x31040  sll         $v0, $v1, 1
    ctx->pc = 0x16b6d4u;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 3), 1));
    // 0x16b6d8: 0x431021  addu        $v0, $v0, $v1
    ctx->pc = 0x16b6d8u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 3)));
    // 0x16b6dc: 0x210c0  sll         $v0, $v0, 3
    ctx->pc = 0x16b6dcu;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 2), 3));
    // 0x16b6e0: 0x431021  addu        $v0, $v0, $v1
    ctx->pc = 0x16b6e0u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 3)));
    // 0x16b6e4: 0x21040  sll         $v0, $v0, 1
    ctx->pc = 0x16b6e4u;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 2), 1));
    // 0x16b6e8: 0xaca20004  sw          $v0, 0x4($a1)
    ctx->pc = 0x16b6e8u;
    WRITE32(ADD32(GPR_U32(ctx, 5), 4), GPR_U32(ctx, 2));
    // 0x16b6ec: 0x8c83001c  lw          $v1, 0x1C($a0)
    ctx->pc = 0x16b6ecu;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 28)));
    // 0x16b6f0: 0xaca30008  sw          $v1, 0x8($a1)
    ctx->pc = 0x16b6f0u;
    WRITE32(ADD32(GPR_U32(ctx, 5), 8), GPR_U32(ctx, 3));
    // 0x16b6f4: 0x8cc20004  lw          $v0, 0x4($a2)
    ctx->pc = 0x16b6f4u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 6), 4)));
    // 0x16b6f8: 0xaca2000c  sw          $v0, 0xC($a1)
    ctx->pc = 0x16b6f8u;
    WRITE32(ADD32(GPR_U32(ctx, 5), 12), GPR_U32(ctx, 2));
    // 0x16b6fc: 0x8cc30008  lw          $v1, 0x8($a2)
    ctx->pc = 0x16b6fcu;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 6), 8)));
    // 0x16b700: 0xaca30010  sw          $v1, 0x10($a1)
    ctx->pc = 0x16b700u;
    WRITE32(ADD32(GPR_U32(ctx, 5), 16), GPR_U32(ctx, 3));
    // 0x16b704: 0x8ce20114  lw          $v0, 0x114($a3)
    ctx->pc = 0x16b704u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 7), 276)));
    // 0x16b708: 0xaca20014  sw          $v0, 0x14($a1)
    ctx->pc = 0x16b708u;
    WRITE32(ADD32(GPR_U32(ctx, 5), 20), GPR_U32(ctx, 2));
    // 0x16b70c: 0x8cc3000c  lw          $v1, 0xC($a2)
    ctx->pc = 0x16b70cu;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 6), 12)));
    // 0x16b710: 0xaca30018  sw          $v1, 0x18($a1)
    ctx->pc = 0x16b710u;
    WRITE32(ADD32(GPR_U32(ctx, 5), 24), GPR_U32(ctx, 3));
    // 0x16b714: 0x8cc20020  lw          $v0, 0x20($a2)
    ctx->pc = 0x16b714u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 6), 32)));
    // 0x16b718: 0xaca2001c  sw          $v0, 0x1C($a1)
    ctx->pc = 0x16b718u;
    WRITE32(ADD32(GPR_U32(ctx, 5), 28), GPR_U32(ctx, 2));
    // 0x16b71c: 0x8cc30024  lw          $v1, 0x24($a2)
    ctx->pc = 0x16b71cu;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 6), 36)));
    // 0x16b720: 0xaca30020  sw          $v1, 0x20($a1)
    ctx->pc = 0x16b720u;
    WRITE32(ADD32(GPR_U32(ctx, 5), 32), GPR_U32(ctx, 3));
label_16b724:
    // 0x16b724: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x16b724u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
label_16b728:
    // 0x16b728: 0xdfbf0008  ld          $ra, 0x8($sp)
    ctx->pc = 0x16b728u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x16b72c: 0x3e00008  jr          $ra
    ctx->pc = 0x16B72Cu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x16B730u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x16B72Cu;
            // 0x16b730: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x16B694u: goto label_16b694;
            case 0x16B724u: goto label_16b724;
            case 0x16B728u: goto label_16b728;
            default: break;
        }
        return;
    }
    ctx->pc = 0x16B734u;
    // 0x16b734: 0x0  nop
    ctx->pc = 0x16b734u;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
