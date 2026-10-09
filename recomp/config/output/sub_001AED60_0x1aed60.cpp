#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001AED60
// Address: 0x1aed60 - 0x1aee40
void sub_001AED60_0x1aed60(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001AED60_0x1aed60");
#endif

    switch (ctx->pc) {
        case 0x1aed7cu: goto label_1aed7c;
        case 0x1aed94u: goto label_1aed94;
        case 0x1aed9cu: goto label_1aed9c;
        default: break;
    }

    ctx->pc = 0x1aed60u;

    // 0x1aed60: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x1aed60u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x1aed64: 0x3c040032  lui         $a0, 0x32
    ctx->pc = 0x1aed64u;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)50 << 16));
    // 0x1aed68: 0xffbf0000  sd          $ra, 0x0($sp)
    ctx->pc = 0x1aed68u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 31));
    // 0x1aed6c: 0x248441a0  addiu       $a0, $a0, 0x41A0
    ctx->pc = 0x1aed6cu;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 16800));
    // 0x1aed70: 0x282d  daddu       $a1, $zero, $zero
    ctx->pc = 0x1aed70u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1aed74: 0xc041f1a  jal         func_107C68
    ctx->pc = 0x1AED74u;
    SET_GPR_U32(ctx, 31, 0x1AED7Cu);
    ctx->pc = 0x1AED78u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1AED74u;
            // 0x1aed78: 0x24060010  addiu       $a2, $zero, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 0), 16));
        ctx->in_delay_slot = false;
    ctx->pc = 0x107C68u;
    if (runtime->hasFunction(0x107C68u)) {
        auto targetFn = runtime->lookupFunction(0x107C68u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1AED7Cu; }
        if (ctx->pc != 0x1AED7Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00107C68_0x107c68(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1AED7Cu; }
        if (ctx->pc != 0x1AED7Cu) { return; }
    }
    ctx->pc = 0x1AED7Cu;
label_1aed7c:
    // 0x1aed7c: 0x3c040032  lui         $a0, 0x32
    ctx->pc = 0x1aed7cu;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)50 << 16));
    // 0x1aed80: 0x3c050025  lui         $a1, 0x25
    ctx->pc = 0x1aed80u;
    SET_GPR_S32(ctx, 5, (int32_t)((uint32_t)37 << 16));
    // 0x1aed84: 0x248441a0  addiu       $a0, $a0, 0x41A0
    ctx->pc = 0x1aed84u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 16800));
    // 0x1aed88: 0x24a5fe30  addiu       $a1, $a1, -0x1D0
    ctx->pc = 0x1aed88u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 4294966832));
    // 0x1aed8c: 0xc041eac  jal         func_107AB0
    ctx->pc = 0x1AED8Cu;
    SET_GPR_U32(ctx, 31, 0x1AED94u);
    ctx->pc = 0x1AED90u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1AED8Cu;
            // 0x1aed90: 0x24060010  addiu       $a2, $zero, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 0), 16));
        ctx->in_delay_slot = false;
    ctx->pc = 0x107AB0u;
    if (runtime->hasFunction(0x107AB0u)) {
        auto targetFn = runtime->lookupFunction(0x107AB0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1AED94u; }
        if (ctx->pc != 0x1AED94u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00107AB0_0x107ab0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1AED94u; }
        if (ctx->pc != 0x1AED94u) { return; }
    }
    ctx->pc = 0x1AED94u;
label_1aed94:
    // 0x1aed94: 0xc06e0a4  jal         func_1B8290
    ctx->pc = 0x1AED94u;
    SET_GPR_U32(ctx, 31, 0x1AED9Cu);
    ctx->pc = 0x1B8290u;
    if (runtime->hasFunction(0x1B8290u)) {
        auto targetFn = runtime->lookupFunction(0x1B8290u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1AED9Cu; }
        if (ctx->pc != 0x1AED9Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001B8290_0x1b8290(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1AED9Cu; }
        if (ctx->pc != 0x1AED9Cu) { return; }
    }
    ctx->pc = 0x1AED9Cu;
label_1aed9c:
    // 0x1aed9c: 0xdfbf0000  ld          $ra, 0x0($sp)
    ctx->pc = 0x1aed9cu;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1aeda0: 0x3e00008  jr          $ra
    ctx->pc = 0x1AEDA0u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1AEDA4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1AEDA0u;
            // 0x1aeda4: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1AED7Cu: goto label_1aed7c;
            case 0x1AED94u: goto label_1aed94;
            case 0x1AED9Cu: goto label_1aed9c;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1AEDA8u;
    // 0x1aeda8: 0x0  nop
    ctx->pc = 0x1aeda8u;
    // NOP
    // 0x1aedac: 0x0  nop
    ctx->pc = 0x1aedacu;
    // NOP
    // 0x1aedb0: 0x3c010032  lui         $at, 0x32
    ctx->pc = 0x1aedb0u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)50 << 16));
    // 0x1aedb4: 0x902843c5  lbu         $t0, 0x43C5($at)
    ctx->pc = 0x1aedb4u;
    SET_GPR_U32(ctx, 8, (uint8_t)READ8(ADD32(GPR_U32(ctx, 1), 17349)));
    // 0x1aedb8: 0x3c010032  lui         $at, 0x32
    ctx->pc = 0x1aedb8u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)50 << 16));
    // 0x1aedbc: 0x902743c9  lbu         $a3, 0x43C9($at)
    ctx->pc = 0x1aedbcu;
    SET_GPR_U32(ctx, 7, (uint8_t)READ8(ADD32(GPR_U32(ctx, 1), 17353)));
    // 0x1aedc0: 0x3c010032  lui         $at, 0x32
    ctx->pc = 0x1aedc0u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)50 << 16));
    // 0x1aedc4: 0x902643ca  lbu         $a2, 0x43CA($at)
    ctx->pc = 0x1aedc4u;
    SET_GPR_U32(ctx, 6, (uint8_t)READ8(ADD32(GPR_U32(ctx, 1), 17354)));
    // 0x1aedc8: 0x3c010032  lui         $at, 0x32
    ctx->pc = 0x1aedc8u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)50 << 16));
    // 0x1aedcc: 0x902543ec  lbu         $a1, 0x43EC($at)
    ctx->pc = 0x1aedccu;
    SET_GPR_U32(ctx, 5, (uint8_t)READ8(ADD32(GPR_U32(ctx, 1), 17388)));
    // 0x1aedd0: 0x3c010032  lui         $at, 0x32
    ctx->pc = 0x1aedd0u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)50 << 16));
    // 0x1aedd4: 0x902443ef  lbu         $a0, 0x43EF($at)
    ctx->pc = 0x1aedd4u;
    SET_GPR_U32(ctx, 4, (uint8_t)READ8(ADD32(GPR_U32(ctx, 1), 17391)));
    // 0x1aedd8: 0x3c010032  lui         $at, 0x32
    ctx->pc = 0x1aedd8u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)50 << 16));
    // 0x1aeddc: 0x802343ed  lb          $v1, 0x43ED($at)
    ctx->pc = 0x1aeddcu;
    SET_GPR_S32(ctx, 3, (int8_t)READ8(ADD32(GPR_U32(ctx, 1), 17389)));
    // 0x1aede0: 0x3c010032  lui         $at, 0x32
    ctx->pc = 0x1aede0u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)50 << 16));
    // 0x1aede4: 0xa02841a0  sb          $t0, 0x41A0($at)
    ctx->pc = 0x1aede4u;
    WRITE8(ADD32(GPR_U32(ctx, 1), 16800), (uint8_t)GPR_U32(ctx, 8));
    // 0x1aede8: 0x3c010032  lui         $at, 0x32
    ctx->pc = 0x1aede8u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)50 << 16));
    // 0x1aedec: 0xa02741a1  sb          $a3, 0x41A1($at)
    ctx->pc = 0x1aedecu;
    WRITE8(ADD32(GPR_U32(ctx, 1), 16801), (uint8_t)GPR_U32(ctx, 7));
    // 0x1aedf0: 0x3c010032  lui         $at, 0x32
    ctx->pc = 0x1aedf0u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)50 << 16));
    // 0x1aedf4: 0xa02641a2  sb          $a2, 0x41A2($at)
    ctx->pc = 0x1aedf4u;
    WRITE8(ADD32(GPR_U32(ctx, 1), 16802), (uint8_t)GPR_U32(ctx, 6));
    // 0x1aedf8: 0x3c010032  lui         $at, 0x32
    ctx->pc = 0x1aedf8u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)50 << 16));
    // 0x1aedfc: 0xa02541a3  sb          $a1, 0x41A3($at)
    ctx->pc = 0x1aedfcu;
    WRITE8(ADD32(GPR_U32(ctx, 1), 16803), (uint8_t)GPR_U32(ctx, 5));
    // 0x1aee00: 0x3c010032  lui         $at, 0x32
    ctx->pc = 0x1aee00u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)50 << 16));
    // 0x1aee04: 0xa02441a4  sb          $a0, 0x41A4($at)
    ctx->pc = 0x1aee04u;
    WRITE8(ADD32(GPR_U32(ctx, 1), 16804), (uint8_t)GPR_U32(ctx, 4));
    // 0x1aee08: 0x3c010032  lui         $at, 0x32
    ctx->pc = 0x1aee08u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)50 << 16));
    // 0x1aee0c: 0xa02341a6  sb          $v1, 0x41A6($at)
    ctx->pc = 0x1aee0cu;
    WRITE8(ADD32(GPR_U32(ctx, 1), 16806), (uint8_t)GPR_U32(ctx, 3));
    // 0x1aee10: 0x3c010032  lui         $at, 0x32
    ctx->pc = 0x1aee10u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)50 << 16));
    // 0x1aee14: 0x802443ee  lb          $a0, 0x43EE($at)
    ctx->pc = 0x1aee14u;
    SET_GPR_S32(ctx, 4, (int8_t)READ8(ADD32(GPR_U32(ctx, 1), 17390)));
    // 0x1aee18: 0x3c010032  lui         $at, 0x32
    ctx->pc = 0x1aee18u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)50 << 16));
    // 0x1aee1c: 0x902343f0  lbu         $v1, 0x43F0($at)
    ctx->pc = 0x1aee1cu;
    SET_GPR_U32(ctx, 3, (uint8_t)READ8(ADD32(GPR_U32(ctx, 1), 17392)));
    // 0x1aee20: 0x3c010032  lui         $at, 0x32
    ctx->pc = 0x1aee20u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)50 << 16));
    // 0x1aee24: 0xa02441a7  sb          $a0, 0x41A7($at)
    ctx->pc = 0x1aee24u;
    WRITE8(ADD32(GPR_U32(ctx, 1), 16807), (uint8_t)GPR_U32(ctx, 4));
    // 0x1aee28: 0x3c010032  lui         $at, 0x32
    ctx->pc = 0x1aee28u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)50 << 16));
    // 0x1aee2c: 0x3e00008  jr          $ra
    ctx->pc = 0x1AEE2Cu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1AEE30u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1AEE2Cu;
            // 0x1aee30: 0xa02341a5  sb          $v1, 0x41A5($at) (Delay Slot)
        WRITE8(ADD32(GPR_U32(ctx, 1), 16805), (uint8_t)GPR_U32(ctx, 3));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1AED7Cu: goto label_1aed7c;
            case 0x1AED94u: goto label_1aed94;
            case 0x1AED9Cu: goto label_1aed9c;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1AEE34u;
    // 0x1aee34: 0x0  nop
    ctx->pc = 0x1aee34u;
    // NOP
    // 0x1aee38: 0x0  nop
    ctx->pc = 0x1aee38u;
    // NOP
    // 0x1aee3c: 0x0  nop
    ctx->pc = 0x1aee3cu;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
