#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00134B40
// Address: 0x134b40 - 0x134bc0
void sub_00134B40_0x134b40(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00134B40_0x134b40");
#endif

    switch (ctx->pc) {
        case 0x134b64u: goto label_134b64;
        case 0x134b94u: goto label_134b94;
        default: break;
    }

    ctx->pc = 0x134b40u;

    // 0x134b40: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x134b40u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x134b44: 0xffb00000  sd          $s0, 0x0($sp)
    ctx->pc = 0x134b44u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x134b48: 0x80802d  daddu       $s0, $a0, $zero
    ctx->pc = 0x134b48u;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x134b4c: 0xffbf0008  sd          $ra, 0x8($sp)
    ctx->pc = 0x134b4cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 8), GPR_U64(ctx, 31));
    // 0x134b50: 0x8e020008  lw          $v0, 0x8($s0)
    ctx->pc = 0x134b50u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 8)));
    // 0x134b54: 0x1040000a  beqz        $v0, . + 4 + (0xA << 2)
    ctx->pc = 0x134B54u;
    {
        const bool branch_taken_0x134b54 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x134B58u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x134B54u;
            // 0x134b58: 0x40202d  daddu       $a0, $v0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x134b54) {
            ctx->pc = 0x134B80u;
            goto label_134b80;
        }
    }
    ctx->pc = 0x134B5Cu;
    // 0x134b5c: 0xc04c16e  jal         func_1305B8
    ctx->pc = 0x134B5Cu;
    SET_GPR_U32(ctx, 31, 0x134B64u);
    ctx->pc = 0x1305B8u;
    if (runtime->hasFunction(0x1305B8u)) {
        auto targetFn = runtime->lookupFunction(0x1305B8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x134B64u; }
        if (ctx->pc != 0x134B64u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001305B8_0x1305b8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x134B64u; }
        if (ctx->pc != 0x134B64u) { return; }
    }
    ctx->pc = 0x134B64u;
label_134b64:
    // 0x134b64: 0x24030004  addiu       $v1, $zero, 0x4
    ctx->pc = 0x134b64u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 4));
    // 0x134b68: 0x54430006  bnel        $v0, $v1, . + 4 + (0x6 << 2)
    ctx->pc = 0x134B68u;
    {
        const bool branch_taken_0x134b68 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 3));
        if (branch_taken_0x134b68) {
            ctx->pc = 0x134B6Cu;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x134B68u;
            // 0x134b6c: 0x8e040094  lw          $a0, 0x94($s0) (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 148)));
        ctx->in_delay_slot = false;
            ctx->pc = 0x134B84u;
            goto label_134b84;
        }
    }
    ctx->pc = 0x134B70u;
    // 0x134b70: 0x2402ffff  addiu       $v0, $zero, -0x1
    ctx->pc = 0x134b70u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
    // 0x134b74: 0x24030006  addiu       $v1, $zero, 0x6
    ctx->pc = 0x134b74u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 6));
    // 0x134b78: 0xa6020060  sh          $v0, 0x60($s0)
    ctx->pc = 0x134b78u;
    WRITE16(ADD32(GPR_U32(ctx, 16), 96), (uint16_t)GPR_U32(ctx, 2));
    // 0x134b7c: 0xa2030001  sb          $v1, 0x1($s0)
    ctx->pc = 0x134b7cu;
    WRITE8(ADD32(GPR_U32(ctx, 16), 1), (uint8_t)GPR_U32(ctx, 3));
label_134b80:
    // 0x134b80: 0x8e040094  lw          $a0, 0x94($s0)
    ctx->pc = 0x134b80u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 148)));
label_134b84:
    // 0x134b84: 0x5080000b  beql        $a0, $zero, . + 4 + (0xB << 2)
    ctx->pc = 0x134B84u;
    {
        const bool branch_taken_0x134b84 = (GPR_U64(ctx, 4) == GPR_U64(ctx, 0));
        if (branch_taken_0x134b84) {
            ctx->pc = 0x134B88u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x134B84u;
            // 0x134b88: 0xdfb00000  ld          $s0, 0x0($sp) (Delay Slot)
        SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
        ctx->in_delay_slot = false;
            ctx->pc = 0x134BB4u;
            goto label_134bb4;
        }
    }
    ctx->pc = 0x134B8Cu;
    // 0x134b8c: 0xc04f428  jal         func_13D0A0
    ctx->pc = 0x134B8Cu;
    SET_GPR_U32(ctx, 31, 0x134B94u);
    ctx->pc = 0x13D0A0u;
    if (runtime->hasFunction(0x13D0A0u)) {
        auto targetFn = runtime->lookupFunction(0x13D0A0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x134B94u; }
        if (ctx->pc != 0x134B94u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0013D0A0_0x13d0a0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x134B94u; }
        if (ctx->pc != 0x134B94u) { return; }
    }
    ctx->pc = 0x134B94u;
label_134b94:
    // 0x134b94: 0x24030003  addiu       $v1, $zero, 0x3
    ctx->pc = 0x134b94u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 3));
    // 0x134b98: 0x54430006  bnel        $v0, $v1, . + 4 + (0x6 << 2)
    ctx->pc = 0x134B98u;
    {
        const bool branch_taken_0x134b98 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 3));
        if (branch_taken_0x134b98) {
            ctx->pc = 0x134B9Cu;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x134B98u;
            // 0x134b9c: 0xdfb00000  ld          $s0, 0x0($sp) (Delay Slot)
        SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
        ctx->in_delay_slot = false;
            ctx->pc = 0x134BB4u;
            goto label_134bb4;
        }
    }
    ctx->pc = 0x134BA0u;
    // 0x134ba0: 0x24020006  addiu       $v0, $zero, 0x6
    ctx->pc = 0x134ba0u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 6));
    // 0x134ba4: 0x2403ffff  addiu       $v1, $zero, -0x1
    ctx->pc = 0x134ba4u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
    // 0x134ba8: 0xa2020001  sb          $v0, 0x1($s0)
    ctx->pc = 0x134ba8u;
    WRITE8(ADD32(GPR_U32(ctx, 16), 1), (uint8_t)GPR_U32(ctx, 2));
    // 0x134bac: 0xa6030060  sh          $v1, 0x60($s0)
    ctx->pc = 0x134bacu;
    WRITE16(ADD32(GPR_U32(ctx, 16), 96), (uint16_t)GPR_U32(ctx, 3));
    // 0x134bb0: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x134bb0u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
label_134bb4:
    // 0x134bb4: 0xdfbf0008  ld          $ra, 0x8($sp)
    ctx->pc = 0x134bb4u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x134bb8: 0x3e00008  jr          $ra
    ctx->pc = 0x134BB8u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x134BBCu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x134BB8u;
            // 0x134bbc: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x134B64u: goto label_134b64;
            case 0x134B80u: goto label_134b80;
            case 0x134B84u: goto label_134b84;
            case 0x134B94u: goto label_134b94;
            case 0x134BB4u: goto label_134bb4;
            default: break;
        }
        return;
    }
    ctx->pc = 0x134BC0u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
