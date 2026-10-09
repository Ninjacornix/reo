#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001BADF0
// Address: 0x1badf0 - 0x1baec0
void sub_001BADF0_0x1badf0(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001BADF0_0x1badf0");
#endif

    switch (ctx->pc) {
        case 0x1bae8cu: goto label_1bae8c;
        case 0x1bae98u: goto label_1bae98;
        case 0x1baea4u: goto label_1baea4;
        case 0x1baeb0u: goto label_1baeb0;
        default: break;
    }

    ctx->pc = 0x1badf0u;

    // 0x1badf0: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x1badf0u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x1badf4: 0x3c010032  lui         $at, 0x32
    ctx->pc = 0x1badf4u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)50 << 16));
    // 0x1badf8: 0xffbf0000  sd          $ra, 0x0($sp)
    ctx->pc = 0x1badf8u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 31));
    // 0x1badfc: 0x802741a0  lb          $a3, 0x41A0($at)
    ctx->pc = 0x1badfcu;
    SET_GPR_S32(ctx, 7, (int8_t)READ8(ADD32(GPR_U32(ctx, 1), 16800)));
    // 0x1bae00: 0x3c010032  lui         $at, 0x32
    ctx->pc = 0x1bae00u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)50 << 16));
    // 0x1bae04: 0x802641a1  lb          $a2, 0x41A1($at)
    ctx->pc = 0x1bae04u;
    SET_GPR_S32(ctx, 6, (int8_t)READ8(ADD32(GPR_U32(ctx, 1), 16801)));
    // 0x1bae08: 0x3c010032  lui         $at, 0x32
    ctx->pc = 0x1bae08u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)50 << 16));
    // 0x1bae0c: 0x802541a2  lb          $a1, 0x41A2($at)
    ctx->pc = 0x1bae0cu;
    SET_GPR_S32(ctx, 5, (int8_t)READ8(ADD32(GPR_U32(ctx, 1), 16802)));
    // 0x1bae10: 0x3c010032  lui         $at, 0x32
    ctx->pc = 0x1bae10u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)50 << 16));
    // 0x1bae14: 0x802441a3  lb          $a0, 0x41A3($at)
    ctx->pc = 0x1bae14u;
    SET_GPR_S32(ctx, 4, (int8_t)READ8(ADD32(GPR_U32(ctx, 1), 16803)));
    // 0x1bae18: 0x3c010032  lui         $at, 0x32
    ctx->pc = 0x1bae18u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)50 << 16));
    // 0x1bae1c: 0x802341a4  lb          $v1, 0x41A4($at)
    ctx->pc = 0x1bae1cu;
    SET_GPR_S32(ctx, 3, (int8_t)READ8(ADD32(GPR_U32(ctx, 1), 16804)));
    // 0x1bae20: 0x3c010032  lui         $at, 0x32
    ctx->pc = 0x1bae20u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)50 << 16));
    // 0x1bae24: 0x802241a6  lb          $v0, 0x41A6($at)
    ctx->pc = 0x1bae24u;
    SET_GPR_S32(ctx, 2, (int8_t)READ8(ADD32(GPR_U32(ctx, 1), 16806)));
    // 0x1bae28: 0x3c010032  lui         $at, 0x32
    ctx->pc = 0x1bae28u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)50 << 16));
    // 0x1bae2c: 0xa02743c5  sb          $a3, 0x43C5($at)
    ctx->pc = 0x1bae2cu;
    WRITE8(ADD32(GPR_U32(ctx, 1), 17349), (uint8_t)GPR_U32(ctx, 7));
    // 0x1bae30: 0x3c010032  lui         $at, 0x32
    ctx->pc = 0x1bae30u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)50 << 16));
    // 0x1bae34: 0xa02643c9  sb          $a2, 0x43C9($at)
    ctx->pc = 0x1bae34u;
    WRITE8(ADD32(GPR_U32(ctx, 1), 17353), (uint8_t)GPR_U32(ctx, 6));
    // 0x1bae38: 0x3c010032  lui         $at, 0x32
    ctx->pc = 0x1bae38u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)50 << 16));
    // 0x1bae3c: 0xa02543ca  sb          $a1, 0x43CA($at)
    ctx->pc = 0x1bae3cu;
    WRITE8(ADD32(GPR_U32(ctx, 1), 17354), (uint8_t)GPR_U32(ctx, 5));
    // 0x1bae40: 0x3c010032  lui         $at, 0x32
    ctx->pc = 0x1bae40u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)50 << 16));
    // 0x1bae44: 0xa02443ec  sb          $a0, 0x43EC($at)
    ctx->pc = 0x1bae44u;
    WRITE8(ADD32(GPR_U32(ctx, 1), 17388), (uint8_t)GPR_U32(ctx, 4));
    // 0x1bae48: 0x3c010032  lui         $at, 0x32
    ctx->pc = 0x1bae48u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)50 << 16));
    // 0x1bae4c: 0xa02343ef  sb          $v1, 0x43EF($at)
    ctx->pc = 0x1bae4cu;
    WRITE8(ADD32(GPR_U32(ctx, 1), 17391), (uint8_t)GPR_U32(ctx, 3));
    // 0x1bae50: 0x3c010032  lui         $at, 0x32
    ctx->pc = 0x1bae50u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)50 << 16));
    // 0x1bae54: 0xa02243ed  sb          $v0, 0x43ED($at)
    ctx->pc = 0x1bae54u;
    WRITE8(ADD32(GPR_U32(ctx, 1), 17389), (uint8_t)GPR_U32(ctx, 2));
    // 0x1bae58: 0x3c010032  lui         $at, 0x32
    ctx->pc = 0x1bae58u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)50 << 16));
    // 0x1bae5c: 0x802341a7  lb          $v1, 0x41A7($at)
    ctx->pc = 0x1bae5cu;
    SET_GPR_S32(ctx, 3, (int8_t)READ8(ADD32(GPR_U32(ctx, 1), 16807)));
    // 0x1bae60: 0x3c010032  lui         $at, 0x32
    ctx->pc = 0x1bae60u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)50 << 16));
    // 0x1bae64: 0x802241a5  lb          $v0, 0x41A5($at)
    ctx->pc = 0x1bae64u;
    SET_GPR_S32(ctx, 2, (int8_t)READ8(ADD32(GPR_U32(ctx, 1), 16805)));
    // 0x1bae68: 0x3c010032  lui         $at, 0x32
    ctx->pc = 0x1bae68u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)50 << 16));
    // 0x1bae6c: 0x802443ed  lb          $a0, 0x43ED($at)
    ctx->pc = 0x1bae6cu;
    SET_GPR_S32(ctx, 4, (int8_t)READ8(ADD32(GPR_U32(ctx, 1), 17389)));
    // 0x1bae70: 0x3c010032  lui         $at, 0x32
    ctx->pc = 0x1bae70u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)50 << 16));
    // 0x1bae74: 0xa02343ee  sb          $v1, 0x43EE($at)
    ctx->pc = 0x1bae74u;
    WRITE8(ADD32(GPR_U32(ctx, 1), 17390), (uint8_t)GPR_U32(ctx, 3));
    // 0x1bae78: 0x3c010032  lui         $at, 0x32
    ctx->pc = 0x1bae78u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)50 << 16));
    // 0x1bae7c: 0xa02243f0  sb          $v0, 0x43F0($at)
    ctx->pc = 0x1bae7cu;
    WRITE8(ADD32(GPR_U32(ctx, 1), 17392), (uint8_t)GPR_U32(ctx, 2));
    // 0x1bae80: 0x3c010032  lui         $at, 0x32
    ctx->pc = 0x1bae80u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)50 << 16));
    // 0x1bae84: 0xc06bde4  jal         func_1AF790
    ctx->pc = 0x1BAE84u;
    SET_GPR_U32(ctx, 31, 0x1BAE8Cu);
    ctx->pc = 0x1BAE88u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1BAE84u;
            // 0x1bae88: 0x802543ee  lb          $a1, 0x43EE($at) (Delay Slot)
        SET_GPR_S32(ctx, 5, (int8_t)READ8(ADD32(GPR_U32(ctx, 1), 17390)));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1AF790u;
    if (runtime->hasFunction(0x1AF790u)) {
        auto targetFn = runtime->lookupFunction(0x1AF790u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1BAE8Cu; }
        if (ctx->pc != 0x1BAE8Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001AF790_0x1af790(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1BAE8Cu; }
        if (ctx->pc != 0x1BAE8Cu) { return; }
    }
    ctx->pc = 0x1BAE8Cu;
label_1bae8c:
    // 0x1bae8c: 0x3c010032  lui         $at, 0x32
    ctx->pc = 0x1bae8cu;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)50 << 16));
    // 0x1bae90: 0xc06e1b0  jal         func_1B86C0
    ctx->pc = 0x1BAE90u;
    SET_GPR_U32(ctx, 31, 0x1BAE98u);
    ctx->pc = 0x1BAE94u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1BAE90u;
            // 0x1bae94: 0x902443c5  lbu         $a0, 0x43C5($at) (Delay Slot)
        SET_GPR_U32(ctx, 4, (uint8_t)READ8(ADD32(GPR_U32(ctx, 1), 17349)));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1B86C0u;
    if (runtime->hasFunction(0x1B86C0u)) {
        auto targetFn = runtime->lookupFunction(0x1B86C0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1BAE98u; }
        if (ctx->pc != 0x1BAE98u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001B86C0_0x1b86c0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1BAE98u; }
        if (ctx->pc != 0x1BAE98u) { return; }
    }
    ctx->pc = 0x1BAE98u;
label_1bae98:
    // 0x1bae98: 0x3c010032  lui         $at, 0x32
    ctx->pc = 0x1bae98u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)50 << 16));
    // 0x1bae9c: 0xc06e1bc  jal         func_1B86F0
    ctx->pc = 0x1BAE9Cu;
    SET_GPR_U32(ctx, 31, 0x1BAEA4u);
    ctx->pc = 0x1BAEA0u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1BAE9Cu;
            // 0x1baea0: 0x902443ca  lbu         $a0, 0x43CA($at) (Delay Slot)
        SET_GPR_U32(ctx, 4, (uint8_t)READ8(ADD32(GPR_U32(ctx, 1), 17354)));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1B86F0u;
    if (runtime->hasFunction(0x1B86F0u)) {
        auto targetFn = runtime->lookupFunction(0x1B86F0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1BAEA4u; }
        if (ctx->pc != 0x1BAEA4u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001B86F0_0x1b86f0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1BAEA4u; }
        if (ctx->pc != 0x1BAEA4u) { return; }
    }
    ctx->pc = 0x1BAEA4u;
label_1baea4:
    // 0x1baea4: 0x3c010032  lui         $at, 0x32
    ctx->pc = 0x1baea4u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)50 << 16));
    // 0x1baea8: 0xc06e1e0  jal         func_1B8780
    ctx->pc = 0x1BAEA8u;
    SET_GPR_U32(ctx, 31, 0x1BAEB0u);
    ctx->pc = 0x1BAEACu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1BAEA8u;
            // 0x1baeac: 0x902443c9  lbu         $a0, 0x43C9($at) (Delay Slot)
        SET_GPR_U32(ctx, 4, (uint8_t)READ8(ADD32(GPR_U32(ctx, 1), 17353)));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1B8780u;
    if (runtime->hasFunction(0x1B8780u)) {
        auto targetFn = runtime->lookupFunction(0x1B8780u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1BAEB0u; }
        if (ctx->pc != 0x1BAEB0u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001B8780_0x1b8780(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1BAEB0u; }
        if (ctx->pc != 0x1BAEB0u) { return; }
    }
    ctx->pc = 0x1BAEB0u;
label_1baeb0:
    // 0x1baeb0: 0xdfbf0000  ld          $ra, 0x0($sp)
    ctx->pc = 0x1baeb0u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1baeb4: 0x3e00008  jr          $ra
    ctx->pc = 0x1BAEB4u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1BAEB8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1BAEB4u;
            // 0x1baeb8: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1BAE8Cu: goto label_1bae8c;
            case 0x1BAE98u: goto label_1bae98;
            case 0x1BAEA4u: goto label_1baea4;
            case 0x1BAEB0u: goto label_1baeb0;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1BAEBCu;
    // 0x1baebc: 0x0  nop
    ctx->pc = 0x1baebcu;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
