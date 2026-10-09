#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001B2CE0
// Address: 0x1b2ce0 - 0x1b33b0
void sub_001B2CE0_0x1b2ce0(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001B2CE0_0x1b2ce0");
#endif

    switch (ctx->pc) {
        case 0x1b2d44u: goto label_1b2d44;
        case 0x1b2d70u: goto label_1b2d70;
        case 0x1b2dacu: goto label_1b2dac;
        case 0x1b2dc0u: goto label_1b2dc0;
        case 0x1b2e64u: goto label_1b2e64;
        case 0x1b2ee0u: goto label_1b2ee0;
        case 0x1b2f94u: goto label_1b2f94;
        case 0x1b300cu: goto label_1b300c;
        case 0x1b30c8u: goto label_1b30c8;
        case 0x1b3130u: goto label_1b3130;
        case 0x1b31e4u: goto label_1b31e4;
        case 0x1b325cu: goto label_1b325c;
        default: break;
    }

    ctx->pc = 0x1b2ce0u;

    // 0x1b2ce0: 0x3c01004c  lui         $at, 0x4C
    ctx->pc = 0x1b2ce0u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)76 << 16));
    // 0x1b2ce4: 0xa420a828  sh          $zero, -0x57D8($at)
    ctx->pc = 0x1b2ce4u;
    WRITE16(ADD32(GPR_U32(ctx, 1), 4294944808), (uint16_t)GPR_U32(ctx, 0));
    // 0x1b2ce8: 0x3c01004c  lui         $at, 0x4C
    ctx->pc = 0x1b2ce8u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)76 << 16));
    // 0x1b2cec: 0x3e00008  jr          $ra
    ctx->pc = 0x1B2CECu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1B2CF0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1B2CECu;
            // 0x1b2cf0: 0xa420a82a  sh          $zero, -0x57D6($at) (Delay Slot)
        WRITE16(ADD32(GPR_U32(ctx, 1), 4294944810), (uint16_t)GPR_U32(ctx, 0));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1B2D44u: goto label_1b2d44;
            case 0x1B2D70u: goto label_1b2d70;
            case 0x1B2DACu: goto label_1b2dac;
            case 0x1B2DC0u: goto label_1b2dc0;
            case 0x1B2E58u: goto label_1b2e58;
            case 0x1B2E64u: goto label_1b2e64;
            case 0x1B2EE0u: goto label_1b2ee0;
            case 0x1B2F44u: goto label_1b2f44;
            case 0x1B2F8Cu: goto label_1b2f8c;
            case 0x1B2F94u: goto label_1b2f94;
            case 0x1B2FACu: goto label_1b2fac;
            case 0x1B2FB0u: goto label_1b2fb0;
            case 0x1B2FD8u: goto label_1b2fd8;
            case 0x1B3004u: goto label_1b3004;
            case 0x1B300Cu: goto label_1b300c;
            case 0x1B3034u: goto label_1b3034;
            case 0x1B3038u: goto label_1b3038;
            case 0x1B306Cu: goto label_1b306c;
            case 0x1B3074u: goto label_1b3074;
            case 0x1B30BCu: goto label_1b30bc;
            case 0x1B30C8u: goto label_1b30c8;
            case 0x1B3130u: goto label_1b3130;
            case 0x1B3194u: goto label_1b3194;
            case 0x1B31DCu: goto label_1b31dc;
            case 0x1B31E4u: goto label_1b31e4;
            case 0x1B31FCu: goto label_1b31fc;
            case 0x1B3200u: goto label_1b3200;
            case 0x1B3228u: goto label_1b3228;
            case 0x1B3254u: goto label_1b3254;
            case 0x1B325Cu: goto label_1b325c;
            case 0x1B3284u: goto label_1b3284;
            case 0x1B3288u: goto label_1b3288;
            case 0x1B32BCu: goto label_1b32bc;
            case 0x1B32C4u: goto label_1b32c4;
            case 0x1B3340u: goto label_1b3340;
            case 0x1B338Cu: goto label_1b338c;
            case 0x1B3390u: goto label_1b3390;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1B2CF4u;
    // 0x1b2cf4: 0x0  nop
    ctx->pc = 0x1b2cf4u;
    // NOP
    // 0x1b2cf8: 0x0  nop
    ctx->pc = 0x1b2cf8u;
    // NOP
    // 0x1b2cfc: 0x0  nop
    ctx->pc = 0x1b2cfcu;
    // NOP
    // 0x1b2d00: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x1b2d00u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x1b2d04: 0x3c03004c  lui         $v1, 0x4C
    ctx->pc = 0x1b2d04u;
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)76 << 16));
    // 0x1b2d08: 0xffbf0000  sd          $ra, 0x0($sp)
    ctx->pc = 0x1b2d08u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 31));
    // 0x1b2d0c: 0x3c01004c  lui         $at, 0x4C
    ctx->pc = 0x1b2d0cu;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)76 << 16));
    // 0x1b2d10: 0x9425a828  lhu         $a1, -0x57D8($at)
    ctx->pc = 0x1b2d10u;
    SET_GPR_U32(ctx, 5, (uint16_t)READ16(ADD32(GPR_U32(ctx, 1), 4294944808)));
    // 0x1b2d14: 0x2463a420  addiu       $v1, $v1, -0x5BE0
    ctx->pc = 0x1b2d14u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 4294943776));
    // 0x1b2d18: 0x3c010032  lui         $at, 0x32
    ctx->pc = 0x1b2d18u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)50 << 16));
    // 0x1b2d1c: 0x942443dc  lhu         $a0, 0x43DC($at)
    ctx->pc = 0x1b2d1cu;
    SET_GPR_U32(ctx, 4, (uint16_t)READ16(ADD32(GPR_U32(ctx, 1), 17372)));
    // 0x1b2d20: 0x42040  sll         $a0, $a0, 1
    ctx->pc = 0x1b2d20u;
    SET_GPR_S32(ctx, 4, (int32_t)SLL32(GPR_U32(ctx, 4), 1));
    // 0x1b2d24: 0x641821  addu        $v1, $v1, $a0
    ctx->pc = 0x1b2d24u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 4)));
    // 0x1b2d28: 0x94630000  lhu         $v1, 0x0($v1)
    ctx->pc = 0x1b2d28u;
    SET_GPR_U32(ctx, 3, (uint16_t)READ16(ADD32(GPR_U32(ctx, 3), 0)));
    // 0x1b2d2c: 0x10650010  beq         $v1, $a1, . + 4 + (0x10 << 2)
    ctx->pc = 0x1B2D2Cu;
    {
        const bool branch_taken_0x1b2d2c = (GPR_U64(ctx, 3) == GPR_U64(ctx, 5));
        if (branch_taken_0x1b2d2c) {
            ctx->pc = 0x1B2D70u;
            goto label_1b2d70;
        }
    }
    ctx->pc = 0x1B2D34u;
    // 0x1b2d34: 0x10a00003  beqz        $a1, . + 4 + (0x3 << 2)
    ctx->pc = 0x1B2D34u;
    {
        const bool branch_taken_0x1b2d34 = (GPR_U64(ctx, 5) == GPR_U64(ctx, 0));
        if (branch_taken_0x1b2d34) {
            ctx->pc = 0x1B2D44u;
            goto label_1b2d44;
        }
    }
    ctx->pc = 0x1B2D3Cu;
    // 0x1b2d3c: 0xc06c788  jal         func_1B1E20
    ctx->pc = 0x1B2D3Cu;
    SET_GPR_U32(ctx, 31, 0x1B2D44u);
    ctx->pc = 0x1B1E20u;
    if (runtime->hasFunction(0x1B1E20u)) {
        auto targetFn = runtime->lookupFunction(0x1B1E20u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1B2D44u; }
        if (ctx->pc != 0x1B2D44u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001B1E20_0x1b1e20(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1B2D44u; }
        if (ctx->pc != 0x1B2D44u) { return; }
    }
    ctx->pc = 0x1B2D44u;
label_1b2d44:
    // 0x1b2d44: 0x3c010032  lui         $at, 0x32
    ctx->pc = 0x1b2d44u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)50 << 16));
    // 0x1b2d48: 0x3c02004c  lui         $v0, 0x4C
    ctx->pc = 0x1b2d48u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)76 << 16));
    // 0x1b2d4c: 0x942343dc  lhu         $v1, 0x43DC($at)
    ctx->pc = 0x1b2d4cu;
    SET_GPR_U32(ctx, 3, (uint16_t)READ16(ADD32(GPR_U32(ctx, 1), 17372)));
    // 0x1b2d50: 0x2442a420  addiu       $v0, $v0, -0x5BE0
    ctx->pc = 0x1b2d50u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 4294943776));
    // 0x1b2d54: 0x31840  sll         $v1, $v1, 1
    ctx->pc = 0x1b2d54u;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 3), 1));
    // 0x1b2d58: 0x3c01004c  lui         $at, 0x4C
    ctx->pc = 0x1b2d58u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)76 << 16));
    // 0x1b2d5c: 0x431821  addu        $v1, $v0, $v1
    ctx->pc = 0x1b2d5cu;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 3)));
    // 0x1b2d60: 0x94620000  lhu         $v0, 0x0($v1)
    ctx->pc = 0x1b2d60u;
    SET_GPR_U32(ctx, 2, (uint16_t)READ16(ADD32(GPR_U32(ctx, 3), 0)));
    // 0x1b2d64: 0xa422a828  sh          $v0, -0x57D8($at)
    ctx->pc = 0x1b2d64u;
    WRITE16(ADD32(GPR_U32(ctx, 1), 4294944808), (uint16_t)GPR_U32(ctx, 2));
    // 0x1b2d68: 0xc0746c4  jal         func_1D1B10
    ctx->pc = 0x1B2D68u;
    SET_GPR_U32(ctx, 31, 0x1B2D70u);
    ctx->pc = 0x1B2D6Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1B2D68u;
            // 0x1b2d6c: 0x94640000  lhu         $a0, 0x0($v1) (Delay Slot)
        SET_GPR_U32(ctx, 4, (uint16_t)READ16(ADD32(GPR_U32(ctx, 3), 0)));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1D1B10u;
    if (runtime->hasFunction(0x1D1B10u)) {
        auto targetFn = runtime->lookupFunction(0x1D1B10u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1B2D70u; }
        if (ctx->pc != 0x1B2D70u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001D1B10_0x1d1b10(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1B2D70u; }
        if (ctx->pc != 0x1B2D70u) { return; }
    }
    ctx->pc = 0x1B2D70u;
label_1b2d70:
    // 0x1b2d70: 0xdfbf0000  ld          $ra, 0x0($sp)
    ctx->pc = 0x1b2d70u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1b2d74: 0x3e00008  jr          $ra
    ctx->pc = 0x1B2D74u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1B2D78u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1B2D74u;
            // 0x1b2d78: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1B2D44u: goto label_1b2d44;
            case 0x1B2D70u: goto label_1b2d70;
            case 0x1B2DACu: goto label_1b2dac;
            case 0x1B2DC0u: goto label_1b2dc0;
            case 0x1B2E58u: goto label_1b2e58;
            case 0x1B2E64u: goto label_1b2e64;
            case 0x1B2EE0u: goto label_1b2ee0;
            case 0x1B2F44u: goto label_1b2f44;
            case 0x1B2F8Cu: goto label_1b2f8c;
            case 0x1B2F94u: goto label_1b2f94;
            case 0x1B2FACu: goto label_1b2fac;
            case 0x1B2FB0u: goto label_1b2fb0;
            case 0x1B2FD8u: goto label_1b2fd8;
            case 0x1B3004u: goto label_1b3004;
            case 0x1B300Cu: goto label_1b300c;
            case 0x1B3034u: goto label_1b3034;
            case 0x1B3038u: goto label_1b3038;
            case 0x1B306Cu: goto label_1b306c;
            case 0x1B3074u: goto label_1b3074;
            case 0x1B30BCu: goto label_1b30bc;
            case 0x1B30C8u: goto label_1b30c8;
            case 0x1B3130u: goto label_1b3130;
            case 0x1B3194u: goto label_1b3194;
            case 0x1B31DCu: goto label_1b31dc;
            case 0x1B31E4u: goto label_1b31e4;
            case 0x1B31FCu: goto label_1b31fc;
            case 0x1B3200u: goto label_1b3200;
            case 0x1B3228u: goto label_1b3228;
            case 0x1B3254u: goto label_1b3254;
            case 0x1B325Cu: goto label_1b325c;
            case 0x1B3284u: goto label_1b3284;
            case 0x1B3288u: goto label_1b3288;
            case 0x1B32BCu: goto label_1b32bc;
            case 0x1B32C4u: goto label_1b32c4;
            case 0x1B3340u: goto label_1b3340;
            case 0x1B338Cu: goto label_1b338c;
            case 0x1B3390u: goto label_1b3390;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1B2D7Cu;
    // 0x1b2d7c: 0x0  nop
    ctx->pc = 0x1b2d7cu;
    // NOP
    // 0x1b2d80: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x1b2d80u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x1b2d84: 0x3c04004c  lui         $a0, 0x4C
    ctx->pc = 0x1b2d84u;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)76 << 16));
    // 0x1b2d88: 0xffbf0000  sd          $ra, 0x0($sp)
    ctx->pc = 0x1b2d88u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 31));
    // 0x1b2d8c: 0x3c01004c  lui         $at, 0x4C
    ctx->pc = 0x1b2d8cu;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)76 << 16));
    // 0x1b2d90: 0xa420a82c  sh          $zero, -0x57D4($at)
    ctx->pc = 0x1b2d90u;
    WRITE16(ADD32(GPR_U32(ctx, 1), 4294944812), (uint16_t)GPR_U32(ctx, 0));
    // 0x1b2d94: 0x2484a830  addiu       $a0, $a0, -0x57D0
    ctx->pc = 0x1b2d94u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 4294944816));
    // 0x1b2d98: 0x3c01004c  lui         $at, 0x4C
    ctx->pc = 0x1b2d98u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)76 << 16));
    // 0x1b2d9c: 0x282d  daddu       $a1, $zero, $zero
    ctx->pc = 0x1b2d9cu;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1b2da0: 0x24060004  addiu       $a2, $zero, 0x4
    ctx->pc = 0x1b2da0u;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 0), 4));
    // 0x1b2da4: 0xc041f1a  jal         func_107C68
    ctx->pc = 0x1B2DA4u;
    SET_GPR_U32(ctx, 31, 0x1B2DACu);
    ctx->pc = 0x1B2DA8u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1B2DA4u;
            // 0x1b2da8: 0xa420a82e  sh          $zero, -0x57D2($at) (Delay Slot)
        WRITE16(ADD32(GPR_U32(ctx, 1), 4294944814), (uint16_t)GPR_U32(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x107C68u;
    if (runtime->hasFunction(0x107C68u)) {
        auto targetFn = runtime->lookupFunction(0x107C68u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1B2DACu; }
        if (ctx->pc != 0x1B2DACu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00107C68_0x107c68(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1B2DACu; }
        if (ctx->pc != 0x1B2DACu) { return; }
    }
    ctx->pc = 0x1B2DACu;
label_1b2dac:
    // 0x1b2dac: 0x3c04004c  lui         $a0, 0x4C
    ctx->pc = 0x1b2dacu;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)76 << 16));
    // 0x1b2db0: 0x240500ff  addiu       $a1, $zero, 0xFF
    ctx->pc = 0x1b2db0u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 255));
    // 0x1b2db4: 0x24849680  addiu       $a0, $a0, -0x6980
    ctx->pc = 0x1b2db4u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 4294940288));
    // 0x1b2db8: 0xc041f1a  jal         func_107C68
    ctx->pc = 0x1B2DB8u;
    SET_GPR_U32(ctx, 31, 0x1B2DC0u);
    ctx->pc = 0x1B2DBCu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1B2DB8u;
            // 0x1b2dbc: 0x24060400  addiu       $a2, $zero, 0x400 (Delay Slot)
        SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 0), 1024));
        ctx->in_delay_slot = false;
    ctx->pc = 0x107C68u;
    if (runtime->hasFunction(0x107C68u)) {
        auto targetFn = runtime->lookupFunction(0x107C68u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1B2DC0u; }
        if (ctx->pc != 0x1B2DC0u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00107C68_0x107c68(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1B2DC0u; }
        if (ctx->pc != 0x1B2DC0u) { return; }
    }
    ctx->pc = 0x1B2DC0u;
label_1b2dc0:
    // 0x1b2dc0: 0xdfbf0000  ld          $ra, 0x0($sp)
    ctx->pc = 0x1b2dc0u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1b2dc4: 0x3e00008  jr          $ra
    ctx->pc = 0x1B2DC4u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1B2DC8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1B2DC4u;
            // 0x1b2dc8: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1B2D44u: goto label_1b2d44;
            case 0x1B2D70u: goto label_1b2d70;
            case 0x1B2DACu: goto label_1b2dac;
            case 0x1B2DC0u: goto label_1b2dc0;
            case 0x1B2E58u: goto label_1b2e58;
            case 0x1B2E64u: goto label_1b2e64;
            case 0x1B2EE0u: goto label_1b2ee0;
            case 0x1B2F44u: goto label_1b2f44;
            case 0x1B2F8Cu: goto label_1b2f8c;
            case 0x1B2F94u: goto label_1b2f94;
            case 0x1B2FACu: goto label_1b2fac;
            case 0x1B2FB0u: goto label_1b2fb0;
            case 0x1B2FD8u: goto label_1b2fd8;
            case 0x1B3004u: goto label_1b3004;
            case 0x1B300Cu: goto label_1b300c;
            case 0x1B3034u: goto label_1b3034;
            case 0x1B3038u: goto label_1b3038;
            case 0x1B306Cu: goto label_1b306c;
            case 0x1B3074u: goto label_1b3074;
            case 0x1B30BCu: goto label_1b30bc;
            case 0x1B30C8u: goto label_1b30c8;
            case 0x1B3130u: goto label_1b3130;
            case 0x1B3194u: goto label_1b3194;
            case 0x1B31DCu: goto label_1b31dc;
            case 0x1B31E4u: goto label_1b31e4;
            case 0x1B31FCu: goto label_1b31fc;
            case 0x1B3200u: goto label_1b3200;
            case 0x1B3228u: goto label_1b3228;
            case 0x1B3254u: goto label_1b3254;
            case 0x1B325Cu: goto label_1b325c;
            case 0x1B3284u: goto label_1b3284;
            case 0x1B3288u: goto label_1b3288;
            case 0x1B32BCu: goto label_1b32bc;
            case 0x1B32C4u: goto label_1b32c4;
            case 0x1B3340u: goto label_1b3340;
            case 0x1B338Cu: goto label_1b338c;
            case 0x1B3390u: goto label_1b3390;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1B2DCCu;
    // 0x1b2dcc: 0x0  nop
    ctx->pc = 0x1b2dccu;
    // NOP
    // 0x1b2dd0: 0x3c01004c  lui         $at, 0x4C
    ctx->pc = 0x1b2dd0u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)76 << 16));
    // 0x1b2dd4: 0x3c04004c  lui         $a0, 0x4C
    ctx->pc = 0x1b2dd4u;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)76 << 16));
    // 0x1b2dd8: 0xa420a82c  sh          $zero, -0x57D4($at)
    ctx->pc = 0x1b2dd8u;
    WRITE16(ADD32(GPR_U32(ctx, 1), 4294944812), (uint16_t)GPR_U32(ctx, 0));
    // 0x1b2ddc: 0x24849680  addiu       $a0, $a0, -0x6980
    ctx->pc = 0x1b2ddcu;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 4294940288));
    // 0x1b2de0: 0x3c01004c  lui         $at, 0x4C
    ctx->pc = 0x1b2de0u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)76 << 16));
    // 0x1b2de4: 0x240500ff  addiu       $a1, $zero, 0xFF
    ctx->pc = 0x1b2de4u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 255));
    // 0x1b2de8: 0xa420a82e  sh          $zero, -0x57D2($at)
    ctx->pc = 0x1b2de8u;
    WRITE16(ADD32(GPR_U32(ctx, 1), 4294944814), (uint16_t)GPR_U32(ctx, 0));
    // 0x1b2dec: 0x24060400  addiu       $a2, $zero, 0x400
    ctx->pc = 0x1b2decu;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 0), 1024));
    // 0x1b2df0: 0x3c01004c  lui         $at, 0x4C
    ctx->pc = 0x1b2df0u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)76 << 16));
    // 0x1b2df4: 0xa420a828  sh          $zero, -0x57D8($at)
    ctx->pc = 0x1b2df4u;
    WRITE16(ADD32(GPR_U32(ctx, 1), 4294944808), (uint16_t)GPR_U32(ctx, 0));
    // 0x1b2df8: 0x3c01004c  lui         $at, 0x4C
    ctx->pc = 0x1b2df8u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)76 << 16));
    // 0x1b2dfc: 0x8041f1a  j           func_107C68
    ctx->pc = 0x1B2DFCu;
    ctx->pc = 0x1B2E00u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1B2DFCu;
            // 0x1b2e00: 0xa420a82a  sh          $zero, -0x57D6($at) (Delay Slot)
        WRITE16(ADD32(GPR_U32(ctx, 1), 4294944810), (uint16_t)GPR_U32(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x107C68u;
    if (runtime->hasFunction(0x107C68u)) {
        auto targetFn = runtime->lookupFunction(0x107C68u);
        targetFn(rdram, ctx, runtime); return;
    } else {
        sub_00107C68_0x107c68(rdram, ctx, runtime); return;
    }
    ctx->pc = 0x1B2E04u;
    // 0x1b2e04: 0x0  nop
    ctx->pc = 0x1b2e04u;
    // NOP
    // 0x1b2e08: 0x0  nop
    ctx->pc = 0x1b2e08u;
    // NOP
    // 0x1b2e0c: 0x0  nop
    ctx->pc = 0x1b2e0cu;
    // NOP
    // 0x1b2e10: 0x27bdffd0  addiu       $sp, $sp, -0x30
    ctx->pc = 0x1b2e10u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967248));
    // 0x1b2e14: 0x3c04004c  lui         $a0, 0x4C
    ctx->pc = 0x1b2e14u;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)76 << 16));
    // 0x1b2e18: 0x7fb20020  sq          $s2, 0x20($sp)
    ctx->pc = 0x1b2e18u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 32), GPR_VEC(ctx, 18));
    // 0x1b2e1c: 0x3c010032  lui         $at, 0x32
    ctx->pc = 0x1b2e1cu;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)50 << 16));
    // 0x1b2e20: 0x7fb10010  sq          $s1, 0x10($sp)
    ctx->pc = 0x1b2e20u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 16), GPR_VEC(ctx, 17));
    // 0x1b2e24: 0x2484a620  addiu       $a0, $a0, -0x59E0
    ctx->pc = 0x1b2e24u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 4294944288));
    // 0x1b2e28: 0x7fb00000  sq          $s0, 0x0($sp)
    ctx->pc = 0x1b2e28u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 0), GPR_VEC(ctx, 16));
    // 0x1b2e2c: 0x942543dc  lhu         $a1, 0x43DC($at)
    ctx->pc = 0x1b2e2cu;
    SET_GPR_U32(ctx, 5, (uint16_t)READ16(ADD32(GPR_U32(ctx, 1), 17372)));
    // 0x1b2e30: 0x53840  sll         $a3, $a1, 1
    ctx->pc = 0x1b2e30u;
    SET_GPR_S32(ctx, 7, (int32_t)SLL32(GPR_U32(ctx, 5), 1));
    // 0x1b2e34: 0x3c01004c  lui         $at, 0x4C
    ctx->pc = 0x1b2e34u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)76 << 16));
    // 0x1b2e38: 0x872021  addu        $a0, $a0, $a3
    ctx->pc = 0x1b2e38u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), GPR_U32(ctx, 7)));
    // 0x1b2e3c: 0x9423a82c  lhu         $v1, -0x57D4($at)
    ctx->pc = 0x1b2e3cu;
    SET_GPR_U32(ctx, 3, (uint16_t)READ16(ADD32(GPR_U32(ctx, 1), 4294944812)));
    // 0x1b2e40: 0x948b0000  lhu         $t3, 0x0($a0)
    ctx->pc = 0x1b2e40u;
    SET_GPR_U32(ctx, 11, (uint16_t)READ16(ADD32(GPR_U32(ctx, 4), 0)));
    // 0x1b2e44: 0x11630004  beq         $t3, $v1, . + 4 + (0x4 << 2)
    ctx->pc = 0x1B2E44u;
    {
        const bool branch_taken_0x1b2e44 = (GPR_U64(ctx, 11) == GPR_U64(ctx, 3));
        ctx->pc = 0x1B2E48u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1B2E44u;
            // 0x1b2e48: 0x2408001f  addiu       $t0, $zero, 0x1F (Delay Slot)
        SET_GPR_S32(ctx, 8, (int32_t)ADD32(GPR_U32(ctx, 0), 31));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1b2e44) {
            ctx->pc = 0x1B2E58u;
            goto label_1b2e58;
        }
    }
    ctx->pc = 0x1B2E4Cu;
    // 0x1b2e4c: 0x24030001  addiu       $v1, $zero, 0x1
    ctx->pc = 0x1b2e4cu;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x1b2e50: 0x3c01003b  lui         $at, 0x3B
    ctx->pc = 0x1b2e50u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)59 << 16));
    // 0x1b2e54: 0xa0235048  sb          $v1, 0x5048($at)
    ctx->pc = 0x1b2e54u;
    WRITE8(ADD32(GPR_U32(ctx, 1), 20552), (uint8_t)GPR_U32(ctx, 3));
label_1b2e58:
    // 0x1b2e58: 0x3c05004c  lui         $a1, 0x4C
    ctx->pc = 0x1b2e58u;
    SET_GPR_S32(ctx, 5, (int32_t)((uint32_t)76 << 16));
    // 0x1b2e5c: 0x2403ffff  addiu       $v1, $zero, -0x1
    ctx->pc = 0x1b2e5cu;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
    // 0x1b2e60: 0x24a59680  addiu       $a1, $a1, -0x6980
    ctx->pc = 0x1b2e60u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 4294940288));
label_1b2e64:
    // 0x1b2e64: 0x82080  sll         $a0, $t0, 2
    ctx->pc = 0x1b2e64u;
    SET_GPR_S32(ctx, 4, (int32_t)SLL32(GPR_U32(ctx, 8), 2));
    // 0x1b2e68: 0xa43021  addu        $a2, $a1, $a0
    ctx->pc = 0x1b2e68u;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 5), GPR_U32(ctx, 4)));
    // 0x1b2e6c: 0x2508ffff  addiu       $t0, $t0, -0x1
    ctx->pc = 0x1b2e6cu;
    SET_GPR_S32(ctx, 8, (int32_t)ADD32(GPR_U32(ctx, 8), 4294967295));
    // 0x1b2e70: 0x8cc40000  lw          $a0, 0x0($a2)
    ctx->pc = 0x1b2e70u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 6), 0)));
    // 0x1b2e74: 0xacc40200  sw          $a0, 0x200($a2)
    ctx->pc = 0x1b2e74u;
    WRITE32(ADD32(GPR_U32(ctx, 6), 512), GPR_U32(ctx, 4));
    // 0x1b2e78: 0x8cc40100  lw          $a0, 0x100($a2)
    ctx->pc = 0x1b2e78u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 6), 256)));
    // 0x1b2e7c: 0xacc40300  sw          $a0, 0x300($a2)
    ctx->pc = 0x1b2e7cu;
    WRITE32(ADD32(GPR_U32(ctx, 6), 768), GPR_U32(ctx, 4));
    // 0x1b2e80: 0xacc30000  sw          $v1, 0x0($a2)
    ctx->pc = 0x1b2e80u;
    WRITE32(ADD32(GPR_U32(ctx, 6), 0), GPR_U32(ctx, 3));
    // 0x1b2e84: 0x501fff7  bgez        $t0, . + 4 + (-0x9 << 2)
    ctx->pc = 0x1B2E84u;
    {
        const bool branch_taken_0x1b2e84 = (GPR_S64(ctx, 8) >= 0);
        ctx->pc = 0x1B2E88u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1B2E84u;
            // 0x1b2e88: 0xacc30100  sw          $v1, 0x100($a2) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 6), 256), GPR_U32(ctx, 3));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1b2e84) {
            ctx->pc = 0x1B2E64u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_1b2e64;
        }
    }
    ctx->pc = 0x1B2E8Cu;
    // 0x1b2e8c: 0x3c01004c  lui         $at, 0x4C
    ctx->pc = 0x1b2e8cu;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)76 << 16));
    // 0x1b2e90: 0x3c06004c  lui         $a2, 0x4C
    ctx->pc = 0x1b2e90u;
    SET_GPR_S32(ctx, 6, (int32_t)((uint32_t)76 << 16));
    // 0x1b2e94: 0x942da820  lhu         $t5, -0x57E0($at)
    ctx->pc = 0x1b2e94u;
    SET_GPR_U32(ctx, 13, (uint16_t)READ16(ADD32(GPR_U32(ctx, 1), 4294944800)));
    // 0x1b2e98: 0x24c69a80  addiu       $a2, $a2, -0x6580
    ctx->pc = 0x1b2e98u;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 6), 4294941312));
    // 0x1b2e9c: 0x3c180075  lui         $t8, 0x75
    ctx->pc = 0x1b2e9cu;
    SET_GPR_S32(ctx, 24, (int32_t)((uint32_t)117 << 16));
    // 0x1b2ea0: 0xc75021  addu        $t2, $a2, $a3
    ctx->pc = 0x1b2ea0u;
    SET_GPR_S32(ctx, 10, (int32_t)ADD32(GPR_U32(ctx, 6), GPR_U32(ctx, 7)));
    // 0x1b2ea4: 0x3c03004c  lui         $v1, 0x4C
    ctx->pc = 0x1b2ea4u;
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)76 << 16));
    // 0x1b2ea8: 0x3c050071  lui         $a1, 0x71
    ctx->pc = 0x1b2ea8u;
    SET_GPR_S32(ctx, 5, (int32_t)((uint32_t)113 << 16));
    // 0x1b2eac: 0x802d  daddu       $s0, $zero, $zero
    ctx->pc = 0x1b2eacu;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1b2eb0: 0xc82d  daddu       $t9, $zero, $zero
    ctx->pc = 0x1b2eb0u;
    SET_GPR_U64(ctx, 25, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1b2eb4: 0x2718f250  addiu       $t8, $t8, -0xDB0
    ctx->pc = 0x1b2eb4u;
    SET_GPR_S32(ctx, 24, (int32_t)ADD32(GPR_U32(ctx, 24), 4294963792));
    // 0x1b2eb8: 0x482d  daddu       $t1, $zero, $zero
    ctx->pc = 0x1b2eb8u;
    SET_GPR_U64(ctx, 9, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1b2ebc: 0x254c0ba0  addiu       $t4, $t2, 0xBA0
    ctx->pc = 0x1b2ebcu;
    SET_GPR_S32(ctx, 12, (int32_t)ADD32(GPR_U32(ctx, 10), 2976));
    // 0x1b2ec0: 0x24639680  addiu       $v1, $v1, -0x6980
    ctx->pc = 0x1b2ec0u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 4294940288));
    // 0x1b2ec4: 0x3c010032  lui         $at, 0x32
    ctx->pc = 0x1b2ec4u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)50 << 16));
    // 0x1b2ec8: 0x24040001  addiu       $a0, $zero, 0x1
    ctx->pc = 0x1b2ec8u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x1b2ecc: 0x942f43dc  lhu         $t7, 0x43DC($at)
    ctx->pc = 0x1b2eccu;
    SET_GPR_U32(ctx, 15, (uint16_t)READ16(ADD32(GPR_U32(ctx, 1), 17372)));
    // 0x1b2ed0: 0x3c01004c  lui         $at, 0x4C
    ctx->pc = 0x1b2ed0u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)76 << 16));
    // 0x1b2ed4: 0x902eae8e  lbu         $t6, -0x5172($at)
    ctx->pc = 0x1b2ed4u;
    SET_GPR_U32(ctx, 14, (uint8_t)READ8(ADD32(GPR_U32(ctx, 1), 4294946446)));
    // 0x1b2ed8: 0x10000066  b           . + 4 + (0x66 << 2)
    ctx->pc = 0x1B2ED8u;
    {
        const bool branch_taken_0x1b2ed8 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1B2EDCu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1B2ED8u;
            // 0x1b2edc: 0x24a59ac0  addiu       $a1, $a1, -0x6540 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 4294941376));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1b2ed8) {
            ctx->pc = 0x1B3074u;
            goto label_1b3074;
        }
    }
    ctx->pc = 0x1B2EE0u;
label_1b2ee0:
    // 0x1b2ee0: 0x93120002  lbu         $s2, 0x2($t8)
    ctx->pc = 0x1b2ee0u;
    SET_GPR_U32(ctx, 18, (uint8_t)READ8(ADD32(GPR_U32(ctx, 24), 2)));
    // 0x1b2ee4: 0x124142  srl         $t0, $s2, 5
    ctx->pc = 0x1b2ee4u;
    SET_GPR_S32(ctx, 8, (int32_t)SRL32(GPR_U32(ctx, 18), 5));
    // 0x1b2ee8: 0x3247001f  andi        $a3, $s2, 0x1F
    ctx->pc = 0x1b2ee8u;
    SET_GPR_U64(ctx, 7, GPR_U64(ctx, 18) & (uint64_t)(uint16_t)31);
    // 0x1b2eec: 0x88880  sll         $s1, $t0, 2
    ctx->pc = 0x1b2eecu;
    SET_GPR_S32(ctx, 17, (int32_t)SLL32(GPR_U32(ctx, 8), 2));
    // 0x1b2ef0: 0xe44004  sllv        $t0, $a0, $a3
    ctx->pc = 0x1b2ef0u;
    SET_GPR_S32(ctx, 8, (int32_t)SLL32(GPR_U32(ctx, 4), GPR_U32(ctx, 7) & 0x1F));
    // 0x1b2ef4: 0xb13821  addu        $a3, $a1, $s1
    ctx->pc = 0x1b2ef4u;
    SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 5), GPR_U32(ctx, 17)));
    // 0x1b2ef8: 0x8ce70000  lw          $a3, 0x0($a3)
    ctx->pc = 0x1b2ef8u;
    SET_GPR_S32(ctx, 7, (int32_t)READ32(ADD32(GPR_U32(ctx, 7), 0)));
    // 0x1b2efc: 0x1073824  and         $a3, $t0, $a3
    ctx->pc = 0x1b2efcu;
    SET_GPR_U64(ctx, 7, GPR_U64(ctx, 8) & GPR_U64(ctx, 7));
    // 0x1b2f00: 0x7382b  sltu        $a3, $zero, $a3
    ctx->pc = 0x1b2f00u;
    SET_GPR_U64(ctx, 7, ((uint64_t)GPR_U64(ctx, 0) < (uint64_t)GPR_U64(ctx, 7)) ? 1 : 0);
    // 0x1b2f04: 0x10e00059  beqz        $a3, . + 4 + (0x59 << 2)
    ctx->pc = 0x1B2F04u;
    {
        const bool branch_taken_0x1b2f04 = (GPR_U64(ctx, 7) == GPR_U64(ctx, 0));
        if (branch_taken_0x1b2f04) {
            ctx->pc = 0x1B306Cu;
            goto label_1b306c;
        }
    }
    ctx->pc = 0x1B2F0Cu;
    // 0x1b2f0c: 0x164d0057  bne         $s2, $t5, . + 4 + (0x57 << 2)
    ctx->pc = 0x1B2F0Cu;
    {
        const bool branch_taken_0x1b2f0c = (GPR_U64(ctx, 18) != GPR_U64(ctx, 13));
        if (branch_taken_0x1b2f0c) {
            ctx->pc = 0x1B306Cu;
            goto label_1b306c;
        }
    }
    ctx->pc = 0x1B2F14u;
    // 0x1b2f14: 0x93110022  lbu         $s1, 0x22($t8)
    ctx->pc = 0x1b2f14u;
    SET_GPR_U32(ctx, 17, (uint8_t)READ8(ADD32(GPR_U32(ctx, 24), 34)));
    // 0x1b2f18: 0x95870000  lhu         $a3, 0x0($t4)
    ctx->pc = 0x1b2f18u;
    SET_GPR_U32(ctx, 7, (uint16_t)READ16(ADD32(GPR_U32(ctx, 12), 0)));
    // 0x1b2f1c: 0x114040  sll         $t0, $s1, 1
    ctx->pc = 0x1b2f1cu;
    SET_GPR_S32(ctx, 8, (int32_t)SLL32(GPR_U32(ctx, 17), 1));
    // 0x1b2f20: 0xc84021  addu        $t0, $a2, $t0
    ctx->pc = 0x1b2f20u;
    SET_GPR_S32(ctx, 8, (int32_t)ADD32(GPR_U32(ctx, 6), GPR_U32(ctx, 8)));
    // 0x1b2f24: 0x95080ba0  lhu         $t0, 0xBA0($t0)
    ctx->pc = 0x1b2f24u;
    SET_GPR_U32(ctx, 8, (uint16_t)READ16(ADD32(GPR_U32(ctx, 8), 2976)));
    // 0x1b2f28: 0x15070050  bne         $t0, $a3, . + 4 + (0x50 << 2)
    ctx->pc = 0x1B2F28u;
    {
        const bool branch_taken_0x1b2f28 = (GPR_U64(ctx, 8) != GPR_U64(ctx, 7));
        if (branch_taken_0x1b2f28) {
            ctx->pc = 0x1B306Cu;
            goto label_1b306c;
        }
    }
    ctx->pc = 0x1B2F30u;
    // 0x1b2f30: 0x93070026  lbu         $a3, 0x26($t8)
    ctx->pc = 0x1b2f30u;
    SET_GPR_U32(ctx, 7, (uint8_t)READ8(ADD32(GPR_U32(ctx, 24), 38)));
    // 0x1b2f34: 0x14e00003  bnez        $a3, . + 4 + (0x3 << 2)
    ctx->pc = 0x1B2F34u;
    {
        const bool branch_taken_0x1b2f34 = (GPR_U64(ctx, 7) != GPR_U64(ctx, 0));
        if (branch_taken_0x1b2f34) {
            ctx->pc = 0x1B2F44u;
            goto label_1b2f44;
        }
    }
    ctx->pc = 0x1B2F3Cu;
    // 0x1b2f3c: 0x162f004b  bne         $s1, $t7, . + 4 + (0x4B << 2)
    ctx->pc = 0x1B2F3Cu;
    {
        const bool branch_taken_0x1b2f3c = (GPR_U64(ctx, 17) != GPR_U64(ctx, 15));
        if (branch_taken_0x1b2f3c) {
            ctx->pc = 0x1B306Cu;
            goto label_1b306c;
        }
    }
    ctx->pc = 0x1B2F44u;
label_1b2f44:
    // 0x1b2f44: 0x93070004  lbu         $a3, 0x4($t8)
    ctx->pc = 0x1b2f44u;
    SET_GPR_U32(ctx, 7, (uint8_t)READ8(ADD32(GPR_U32(ctx, 24), 4)));
    // 0x1b2f48: 0x74142  srl         $t0, $a3, 5
    ctx->pc = 0x1b2f48u;
    SET_GPR_S32(ctx, 8, (int32_t)SRL32(GPR_U32(ctx, 7), 5));
    // 0x1b2f4c: 0x30e7001f  andi        $a3, $a3, 0x1F
    ctx->pc = 0x1b2f4cu;
    SET_GPR_U64(ctx, 7, GPR_U64(ctx, 7) & (uint64_t)(uint16_t)31);
    // 0x1b2f50: 0x88880  sll         $s1, $t0, 2
    ctx->pc = 0x1b2f50u;
    SET_GPR_S32(ctx, 17, (int32_t)SLL32(GPR_U32(ctx, 8), 2));
    // 0x1b2f54: 0xe44004  sllv        $t0, $a0, $a3
    ctx->pc = 0x1b2f54u;
    SET_GPR_S32(ctx, 8, (int32_t)SLL32(GPR_U32(ctx, 4), GPR_U32(ctx, 7) & 0x1F));
    // 0x1b2f58: 0xd13821  addu        $a3, $a2, $s1
    ctx->pc = 0x1b2f58u;
    SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 6), GPR_U32(ctx, 17)));
    // 0x1b2f5c: 0x8ce70fb0  lw          $a3, 0xFB0($a3)
    ctx->pc = 0x1b2f5cu;
    SET_GPR_S32(ctx, 7, (int32_t)READ32(ADD32(GPR_U32(ctx, 7), 4016)));
    // 0x1b2f60: 0xe83824  and         $a3, $a3, $t0
    ctx->pc = 0x1b2f60u;
    SET_GPR_U64(ctx, 7, GPR_U64(ctx, 7) & GPR_U64(ctx, 8));
    // 0x1b2f64: 0x10e00041  beqz        $a3, . + 4 + (0x41 << 2)
    ctx->pc = 0x1B2F64u;
    {
        const bool branch_taken_0x1b2f64 = (GPR_U64(ctx, 7) == GPR_U64(ctx, 0));
        if (branch_taken_0x1b2f64) {
            ctx->pc = 0x1B306Cu;
            goto label_1b306c;
        }
    }
    ctx->pc = 0x1B2F6Cu;
    // 0x1b2f6c: 0x16000007  bnez        $s0, . + 4 + (0x7 << 2)
    ctx->pc = 0x1B2F6Cu;
    {
        const bool branch_taken_0x1b2f6c = (GPR_U64(ctx, 16) != GPR_U64(ctx, 0));
        ctx->pc = 0x1B2F70u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1B2F6Cu;
            // 0x1b2f70: 0x882d  daddu       $s1, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1b2f6c) {
            ctx->pc = 0x1B2F8Cu;
            goto label_1b2f8c;
        }
    }
    ctx->pc = 0x1B2F74u;
    // 0x1b2f74: 0x93080003  lbu         $t0, 0x3($t8)
    ctx->pc = 0x1b2f74u;
    SET_GPR_U32(ctx, 8, (uint8_t)READ8(ADD32(GPR_U32(ctx, 24), 3)));
    // 0x1b2f78: 0x103880  sll         $a3, $s0, 2
    ctx->pc = 0x1b2f78u;
    SET_GPR_S32(ctx, 7, (int32_t)SLL32(GPR_U32(ctx, 16), 2));
    // 0x1b2f7c: 0x673821  addu        $a3, $v1, $a3
    ctx->pc = 0x1b2f7cu;
    SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 7)));
    // 0x1b2f80: 0x26100001  addiu       $s0, $s0, 0x1
    ctx->pc = 0x1b2f80u;
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 16), 1));
    // 0x1b2f84: 0x10000014  b           . + 4 + (0x14 << 2)
    ctx->pc = 0x1B2F84u;
    {
        const bool branch_taken_0x1b2f84 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1B2F88u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1B2F84u;
            // 0x1b2f88: 0xace80000  sw          $t0, 0x0($a3) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 7), 0), GPR_U32(ctx, 8));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1b2f84) {
            ctx->pc = 0x1B2FD8u;
            goto label_1b2fd8;
        }
    }
    ctx->pc = 0x1B2F8Cu;
label_1b2f8c:
    // 0x1b2f8c: 0x10000008  b           . + 4 + (0x8 << 2)
    ctx->pc = 0x1B2F8Cu;
    {
        const bool branch_taken_0x1b2f8c = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1B2F90u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1B2F8Cu;
            // 0x1b2f90: 0x902d  daddu       $s2, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 18, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1b2f8c) {
            ctx->pc = 0x1B2FB0u;
            goto label_1b2fb0;
        }
    }
    ctx->pc = 0x1B2F94u;
label_1b2f94:
    // 0x1b2f94: 0x93080003  lbu         $t0, 0x3($t8)
    ctx->pc = 0x1b2f94u;
    SET_GPR_U32(ctx, 8, (uint8_t)READ8(ADD32(GPR_U32(ctx, 24), 3)));
    // 0x1b2f98: 0x673821  addu        $a3, $v1, $a3
    ctx->pc = 0x1b2f98u;
    SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 7)));
    // 0x1b2f9c: 0x8ce70000  lw          $a3, 0x0($a3)
    ctx->pc = 0x1b2f9cu;
    SET_GPR_S32(ctx, 7, (int32_t)READ32(ADD32(GPR_U32(ctx, 7), 0)));
    // 0x1b2fa0: 0x15070002  bne         $t0, $a3, . + 4 + (0x2 << 2)
    ctx->pc = 0x1B2FA0u;
    {
        const bool branch_taken_0x1b2fa0 = (GPR_U64(ctx, 8) != GPR_U64(ctx, 7));
        if (branch_taken_0x1b2fa0) {
            ctx->pc = 0x1B2FACu;
            goto label_1b2fac;
        }
    }
    ctx->pc = 0x1B2FA8u;
    // 0x1b2fa8: 0x24110001  addiu       $s1, $zero, 0x1
    ctx->pc = 0x1b2fa8u;
    SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
label_1b2fac:
    // 0x1b2fac: 0x26520001  addiu       $s2, $s2, 0x1
    ctx->pc = 0x1b2facu;
    SET_GPR_S32(ctx, 18, (int32_t)ADD32(GPR_U32(ctx, 18), 1));
label_1b2fb0:
    // 0x1b2fb0: 0x250382a  slt         $a3, $s2, $s0
    ctx->pc = 0x1b2fb0u;
    SET_GPR_U64(ctx, 7, ((int64_t)GPR_S64(ctx, 18) < (int64_t)GPR_S64(ctx, 16)) ? 1 : 0);
    // 0x1b2fb4: 0x14e0fff7  bnez        $a3, . + 4 + (-0x9 << 2)
    ctx->pc = 0x1B2FB4u;
    {
        const bool branch_taken_0x1b2fb4 = (GPR_U64(ctx, 7) != GPR_U64(ctx, 0));
        ctx->pc = 0x1B2FB8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1B2FB4u;
            // 0x1b2fb8: 0x123880  sll         $a3, $s2, 2 (Delay Slot)
        SET_GPR_S32(ctx, 7, (int32_t)SLL32(GPR_U32(ctx, 18), 2));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1b2fb4) {
            ctx->pc = 0x1B2F94u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_1b2f94;
        }
    }
    ctx->pc = 0x1B2FBCu;
    // 0x1b2fbc: 0x16200006  bnez        $s1, . + 4 + (0x6 << 2)
    ctx->pc = 0x1B2FBCu;
    {
        const bool branch_taken_0x1b2fbc = (GPR_U64(ctx, 17) != GPR_U64(ctx, 0));
        if (branch_taken_0x1b2fbc) {
            ctx->pc = 0x1B2FD8u;
            goto label_1b2fd8;
        }
    }
    ctx->pc = 0x1B2FC4u;
    // 0x1b2fc4: 0x93080003  lbu         $t0, 0x3($t8)
    ctx->pc = 0x1b2fc4u;
    SET_GPR_U32(ctx, 8, (uint8_t)READ8(ADD32(GPR_U32(ctx, 24), 3)));
    // 0x1b2fc8: 0x103880  sll         $a3, $s0, 2
    ctx->pc = 0x1b2fc8u;
    SET_GPR_S32(ctx, 7, (int32_t)SLL32(GPR_U32(ctx, 16), 2));
    // 0x1b2fcc: 0x673821  addu        $a3, $v1, $a3
    ctx->pc = 0x1b2fccu;
    SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 7)));
    // 0x1b2fd0: 0x26100001  addiu       $s0, $s0, 0x1
    ctx->pc = 0x1b2fd0u;
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 16), 1));
    // 0x1b2fd4: 0xace80000  sw          $t0, 0x0($a3)
    ctx->pc = 0x1b2fd4u;
    WRITE32(ADD32(GPR_U32(ctx, 7), 0), GPR_U32(ctx, 8));
label_1b2fd8:
    // 0x1b2fd8: 0x1720000a  bnez        $t9, . + 4 + (0xA << 2)
    ctx->pc = 0x1B2FD8u;
    {
        const bool branch_taken_0x1b2fd8 = (GPR_U64(ctx, 25) != GPR_U64(ctx, 0));
        ctx->pc = 0x1B2FDCu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1B2FD8u;
            // 0x1b2fdc: 0x402d  daddu       $t0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 8, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1b2fd8) {
            ctx->pc = 0x1B3004u;
            goto label_1b3004;
        }
    }
    ctx->pc = 0x1B2FE0u;
    // 0x1b2fe0: 0x95880000  lhu         $t0, 0x0($t4)
    ctx->pc = 0x1b2fe0u;
    SET_GPR_U32(ctx, 8, (uint16_t)READ16(ADD32(GPR_U32(ctx, 12), 0)));
    // 0x1b2fe4: 0x193880  sll         $a3, $t9, 2
    ctx->pc = 0x1b2fe4u;
    SET_GPR_S32(ctx, 7, (int32_t)SLL32(GPR_U32(ctx, 25), 2));
    // 0x1b2fe8: 0x673821  addu        $a3, $v1, $a3
    ctx->pc = 0x1b2fe8u;
    SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 7)));
    // 0x1b2fec: 0x27390001  addiu       $t9, $t9, 0x1
    ctx->pc = 0x1b2fecu;
    SET_GPR_S32(ctx, 25, (int32_t)ADD32(GPR_U32(ctx, 25), 1));
    // 0x1b2ff0: 0x84040  sll         $t0, $t0, 1
    ctx->pc = 0x1b2ff0u;
    SET_GPR_S32(ctx, 8, (int32_t)SLL32(GPR_U32(ctx, 8), 1));
    // 0x1b2ff4: 0xc84021  addu        $t0, $a2, $t0
    ctx->pc = 0x1b2ff4u;
    SET_GPR_S32(ctx, 8, (int32_t)ADD32(GPR_U32(ctx, 6), GPR_U32(ctx, 8)));
    // 0x1b2ff8: 0x95080db0  lhu         $t0, 0xDB0($t0)
    ctx->pc = 0x1b2ff8u;
    SET_GPR_U32(ctx, 8, (uint16_t)READ16(ADD32(GPR_U32(ctx, 8), 3504)));
    // 0x1b2ffc: 0x1000001b  b           . + 4 + (0x1B << 2)
    ctx->pc = 0x1B2FFCu;
    {
        const bool branch_taken_0x1b2ffc = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1B3000u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1B2FFCu;
            // 0x1b3000: 0xace80100  sw          $t0, 0x100($a3) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 7), 256), GPR_U32(ctx, 8));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1b2ffc) {
            ctx->pc = 0x1B306Cu;
            goto label_1b306c;
        }
    }
    ctx->pc = 0x1B3004u;
label_1b3004:
    // 0x1b3004: 0x1000000c  b           . + 4 + (0xC << 2)
    ctx->pc = 0x1B3004u;
    {
        const bool branch_taken_0x1b3004 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1B3008u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1B3004u;
            // 0x1b3008: 0x382d  daddu       $a3, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 7, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1b3004) {
            ctx->pc = 0x1B3038u;
            goto label_1b3038;
        }
    }
    ctx->pc = 0x1B300Cu;
label_1b300c:
    // 0x1b300c: 0x95910000  lhu         $s1, 0x0($t4)
    ctx->pc = 0x1b300cu;
    SET_GPR_U32(ctx, 17, (uint16_t)READ16(ADD32(GPR_U32(ctx, 12), 0)));
    // 0x1b3010: 0x79080  sll         $s2, $a3, 2
    ctx->pc = 0x1b3010u;
    SET_GPR_S32(ctx, 18, (int32_t)SLL32(GPR_U32(ctx, 7), 2));
    // 0x1b3014: 0x729021  addu        $s2, $v1, $s2
    ctx->pc = 0x1b3014u;
    SET_GPR_S32(ctx, 18, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 18)));
    // 0x1b3018: 0x8e520100  lw          $s2, 0x100($s2)
    ctx->pc = 0x1b3018u;
    SET_GPR_S32(ctx, 18, (int32_t)READ32(ADD32(GPR_U32(ctx, 18), 256)));
    // 0x1b301c: 0x118840  sll         $s1, $s1, 1
    ctx->pc = 0x1b301cu;
    SET_GPR_S32(ctx, 17, (int32_t)SLL32(GPR_U32(ctx, 17), 1));
    // 0x1b3020: 0xd18821  addu        $s1, $a2, $s1
    ctx->pc = 0x1b3020u;
    SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 6), GPR_U32(ctx, 17)));
    // 0x1b3024: 0x96310db0  lhu         $s1, 0xDB0($s1)
    ctx->pc = 0x1b3024u;
    SET_GPR_U32(ctx, 17, (uint16_t)READ16(ADD32(GPR_U32(ctx, 17), 3504)));
    // 0x1b3028: 0x16510002  bne         $s2, $s1, . + 4 + (0x2 << 2)
    ctx->pc = 0x1B3028u;
    {
        const bool branch_taken_0x1b3028 = (GPR_U64(ctx, 18) != GPR_U64(ctx, 17));
        if (branch_taken_0x1b3028) {
            ctx->pc = 0x1B3034u;
            goto label_1b3034;
        }
    }
    ctx->pc = 0x1B3030u;
    // 0x1b3030: 0x24080001  addiu       $t0, $zero, 0x1
    ctx->pc = 0x1b3030u;
    SET_GPR_S32(ctx, 8, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
label_1b3034:
    // 0x1b3034: 0x24e70001  addiu       $a3, $a3, 0x1
    ctx->pc = 0x1b3034u;
    SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 7), 1));
label_1b3038:
    // 0x1b3038: 0xf9882a  slt         $s1, $a3, $t9
    ctx->pc = 0x1b3038u;
    SET_GPR_U64(ctx, 17, ((int64_t)GPR_S64(ctx, 7) < (int64_t)GPR_S64(ctx, 25)) ? 1 : 0);
    // 0x1b303c: 0x1620fff3  bnez        $s1, . + 4 + (-0xD << 2)
    ctx->pc = 0x1B303Cu;
    {
        const bool branch_taken_0x1b303c = (GPR_U64(ctx, 17) != GPR_U64(ctx, 0));
        if (branch_taken_0x1b303c) {
            ctx->pc = 0x1B300Cu;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_1b300c;
        }
    }
    ctx->pc = 0x1B3044u;
    // 0x1b3044: 0x15000009  bnez        $t0, . + 4 + (0x9 << 2)
    ctx->pc = 0x1B3044u;
    {
        const bool branch_taken_0x1b3044 = (GPR_U64(ctx, 8) != GPR_U64(ctx, 0));
        if (branch_taken_0x1b3044) {
            ctx->pc = 0x1B306Cu;
            goto label_1b306c;
        }
    }
    ctx->pc = 0x1B304Cu;
    // 0x1b304c: 0x95880000  lhu         $t0, 0x0($t4)
    ctx->pc = 0x1b304cu;
    SET_GPR_U32(ctx, 8, (uint16_t)READ16(ADD32(GPR_U32(ctx, 12), 0)));
    // 0x1b3050: 0x193880  sll         $a3, $t9, 2
    ctx->pc = 0x1b3050u;
    SET_GPR_S32(ctx, 7, (int32_t)SLL32(GPR_U32(ctx, 25), 2));
    // 0x1b3054: 0x673821  addu        $a3, $v1, $a3
    ctx->pc = 0x1b3054u;
    SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 7)));
    // 0x1b3058: 0x27390001  addiu       $t9, $t9, 0x1
    ctx->pc = 0x1b3058u;
    SET_GPR_S32(ctx, 25, (int32_t)ADD32(GPR_U32(ctx, 25), 1));
    // 0x1b305c: 0x84040  sll         $t0, $t0, 1
    ctx->pc = 0x1b305cu;
    SET_GPR_S32(ctx, 8, (int32_t)SLL32(GPR_U32(ctx, 8), 1));
    // 0x1b3060: 0xc84021  addu        $t0, $a2, $t0
    ctx->pc = 0x1b3060u;
    SET_GPR_S32(ctx, 8, (int32_t)ADD32(GPR_U32(ctx, 6), GPR_U32(ctx, 8)));
    // 0x1b3064: 0x95080db0  lhu         $t0, 0xDB0($t0)
    ctx->pc = 0x1b3064u;
    SET_GPR_U32(ctx, 8, (uint16_t)READ16(ADD32(GPR_U32(ctx, 8), 3504)));
    // 0x1b3068: 0xace80100  sw          $t0, 0x100($a3)
    ctx->pc = 0x1b3068u;
    WRITE32(ADD32(GPR_U32(ctx, 7), 256), GPR_U32(ctx, 8));
label_1b306c:
    // 0x1b306c: 0x25290001  addiu       $t1, $t1, 0x1
    ctx->pc = 0x1b306cu;
    SET_GPR_S32(ctx, 9, (int32_t)ADD32(GPR_U32(ctx, 9), 1));
    // 0x1b3070: 0x27180060  addiu       $t8, $t8, 0x60
    ctx->pc = 0x1b3070u;
    SET_GPR_S32(ctx, 24, (int32_t)ADD32(GPR_U32(ctx, 24), 96));
label_1b3074:
    // 0x1b3074: 0x12e382a  slt         $a3, $t1, $t6
    ctx->pc = 0x1b3074u;
    SET_GPR_U64(ctx, 7, ((int64_t)GPR_S64(ctx, 9) < (int64_t)GPR_S64(ctx, 14)) ? 1 : 0);
    // 0x1b3078: 0x14e0ff99  bnez        $a3, . + 4 + (-0x67 << 2)
    ctx->pc = 0x1B3078u;
    {
        const bool branch_taken_0x1b3078 = (GPR_U64(ctx, 7) != GPR_U64(ctx, 0));
        if (branch_taken_0x1b3078) {
            ctx->pc = 0x1B2EE0u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_1b2ee0;
        }
    }
    ctx->pc = 0x1B3080u;
    // 0x1b3080: 0x31e3ffff  andi        $v1, $t7, 0xFFFF
    ctx->pc = 0x1b3080u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 15) & (uint64_t)(uint16_t)65535);
    // 0x1b3084: 0x3c01004c  lui         $at, 0x4C
    ctx->pc = 0x1b3084u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)76 << 16));
    // 0x1b3088: 0x32040  sll         $a0, $v1, 1
    ctx->pc = 0x1b3088u;
    SET_GPR_S32(ctx, 4, (int32_t)SLL32(GPR_U32(ctx, 3), 1));
    // 0x1b308c: 0xa42ba82c  sh          $t3, -0x57D4($at)
    ctx->pc = 0x1b308cu;
    WRITE16(ADD32(GPR_U32(ctx, 1), 4294944812), (uint16_t)GPR_U32(ctx, 11));
    // 0x1b3090: 0x3c03004c  lui         $v1, 0x4C
    ctx->pc = 0x1b3090u;
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)76 << 16));
    // 0x1b3094: 0x3c01004c  lui         $at, 0x4C
    ctx->pc = 0x1b3094u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)76 << 16));
    // 0x1b3098: 0x2463a720  addiu       $v1, $v1, -0x58E0
    ctx->pc = 0x1b3098u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 4294944544));
    // 0x1b309c: 0x642021  addu        $a0, $v1, $a0
    ctx->pc = 0x1b309cu;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 4)));
    // 0x1b30a0: 0x9423a82e  lhu         $v1, -0x57D2($at)
    ctx->pc = 0x1b30a0u;
    SET_GPR_U32(ctx, 3, (uint16_t)READ16(ADD32(GPR_U32(ctx, 1), 4294944814)));
    // 0x1b30a4: 0x948b0000  lhu         $t3, 0x0($a0)
    ctx->pc = 0x1b30a4u;
    SET_GPR_U32(ctx, 11, (uint16_t)READ16(ADD32(GPR_U32(ctx, 4), 0)));
    // 0x1b30a8: 0x11630004  beq         $t3, $v1, . + 4 + (0x4 << 2)
    ctx->pc = 0x1B30A8u;
    {
        const bool branch_taken_0x1b30a8 = (GPR_U64(ctx, 11) == GPR_U64(ctx, 3));
        ctx->pc = 0x1B30ACu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1B30A8u;
            // 0x1b30ac: 0x2406001f  addiu       $a2, $zero, 0x1F (Delay Slot)
        SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 0), 31));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1b30a8) {
            ctx->pc = 0x1B30BCu;
            goto label_1b30bc;
        }
    }
    ctx->pc = 0x1B30B0u;
    // 0x1b30b0: 0x24030001  addiu       $v1, $zero, 0x1
    ctx->pc = 0x1b30b0u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x1b30b4: 0x3c01003b  lui         $at, 0x3B
    ctx->pc = 0x1b30b4u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)59 << 16));
    // 0x1b30b8: 0xa0235049  sb          $v1, 0x5049($at)
    ctx->pc = 0x1b30b8u;
    WRITE8(ADD32(GPR_U32(ctx, 1), 20553), (uint8_t)GPR_U32(ctx, 3));
label_1b30bc:
    // 0x1b30bc: 0x3c05004c  lui         $a1, 0x4C
    ctx->pc = 0x1b30bcu;
    SET_GPR_S32(ctx, 5, (int32_t)((uint32_t)76 << 16));
    // 0x1b30c0: 0x2403ffff  addiu       $v1, $zero, -0x1
    ctx->pc = 0x1b30c0u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
    // 0x1b30c4: 0x24a59680  addiu       $a1, $a1, -0x6980
    ctx->pc = 0x1b30c4u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 4294940288));
label_1b30c8:
    // 0x1b30c8: 0x62080  sll         $a0, $a2, 2
    ctx->pc = 0x1b30c8u;
    SET_GPR_S32(ctx, 4, (int32_t)SLL32(GPR_U32(ctx, 6), 2));
    // 0x1b30cc: 0xa43821  addu        $a3, $a1, $a0
    ctx->pc = 0x1b30ccu;
    SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 5), GPR_U32(ctx, 4)));
    // 0x1b30d0: 0x24c6ffff  addiu       $a2, $a2, -0x1
    ctx->pc = 0x1b30d0u;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 6), 4294967295));
    // 0x1b30d4: 0x8ce40080  lw          $a0, 0x80($a3)
    ctx->pc = 0x1b30d4u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 7), 128)));
    // 0x1b30d8: 0xace40280  sw          $a0, 0x280($a3)
    ctx->pc = 0x1b30d8u;
    WRITE32(ADD32(GPR_U32(ctx, 7), 640), GPR_U32(ctx, 4));
    // 0x1b30dc: 0x8ce40180  lw          $a0, 0x180($a3)
    ctx->pc = 0x1b30dcu;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 7), 384)));
    // 0x1b30e0: 0xace40380  sw          $a0, 0x380($a3)
    ctx->pc = 0x1b30e0u;
    WRITE32(ADD32(GPR_U32(ctx, 7), 896), GPR_U32(ctx, 4));
    // 0x1b30e4: 0xace30080  sw          $v1, 0x80($a3)
    ctx->pc = 0x1b30e4u;
    WRITE32(ADD32(GPR_U32(ctx, 7), 128), GPR_U32(ctx, 3));
    // 0x1b30e8: 0x4c1fff7  bgez        $a2, . + 4 + (-0x9 << 2)
    ctx->pc = 0x1B30E8u;
    {
        const bool branch_taken_0x1b30e8 = (GPR_S64(ctx, 6) >= 0);
        ctx->pc = 0x1B30ECu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1B30E8u;
            // 0x1b30ec: 0xace30180  sw          $v1, 0x180($a3) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 7), 384), GPR_U32(ctx, 3));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1b30e8) {
            ctx->pc = 0x1B30C8u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_1b30c8;
        }
    }
    ctx->pc = 0x1B30F0u;
    // 0x1b30f0: 0x3c01004c  lui         $at, 0x4C
    ctx->pc = 0x1b30f0u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)76 << 16));
    // 0x1b30f4: 0x254c0ca0  addiu       $t4, $t2, 0xCA0
    ctx->pc = 0x1b30f4u;
    SET_GPR_S32(ctx, 12, (int32_t)ADD32(GPR_U32(ctx, 10), 3232));
    // 0x1b30f8: 0x942da822  lhu         $t5, -0x57DE($at)
    ctx->pc = 0x1b30f8u;
    SET_GPR_U32(ctx, 13, (uint16_t)READ16(ADD32(GPR_U32(ctx, 1), 4294944802)));
    // 0x1b30fc: 0x3c070075  lui         $a3, 0x75
    ctx->pc = 0x1b30fcu;
    SET_GPR_S32(ctx, 7, (int32_t)((uint32_t)117 << 16));
    // 0x1b3100: 0x3c03004c  lui         $v1, 0x4C
    ctx->pc = 0x1b3100u;
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)76 << 16));
    // 0x1b3104: 0x3c04004c  lui         $a0, 0x4C
    ctx->pc = 0x1b3104u;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)76 << 16));
    // 0x1b3108: 0x3c060071  lui         $a2, 0x71
    ctx->pc = 0x1b3108u;
    SET_GPR_S32(ctx, 6, (int32_t)((uint32_t)113 << 16));
    // 0x1b310c: 0x482d  daddu       $t1, $zero, $zero
    ctx->pc = 0x1b310cu;
    SET_GPR_U64(ctx, 9, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1b3110: 0x402d  daddu       $t0, $zero, $zero
    ctx->pc = 0x1b3110u;
    SET_GPR_U64(ctx, 8, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1b3114: 0x24e7f250  addiu       $a3, $a3, -0xDB0
    ctx->pc = 0x1b3114u;
    SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 7), 4294963792));
    // 0x1b3118: 0x502d  daddu       $t2, $zero, $zero
    ctx->pc = 0x1b3118u;
    SET_GPR_U64(ctx, 10, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1b311c: 0x24639680  addiu       $v1, $v1, -0x6980
    ctx->pc = 0x1b311cu;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 4294940288));
    // 0x1b3120: 0x24849a80  addiu       $a0, $a0, -0x6580
    ctx->pc = 0x1b3120u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 4294941312));
    // 0x1b3124: 0x24050001  addiu       $a1, $zero, 0x1
    ctx->pc = 0x1b3124u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x1b3128: 0x10000066  b           . + 4 + (0x66 << 2)
    ctx->pc = 0x1B3128u;
    {
        const bool branch_taken_0x1b3128 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1B312Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1B3128u;
            // 0x1b312c: 0x24c69ac0  addiu       $a2, $a2, -0x6540 (Delay Slot)
        SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 6), 4294941376));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1b3128) {
            ctx->pc = 0x1B32C4u;
            goto label_1b32c4;
        }
    }
    ctx->pc = 0x1B3130u;
label_1b3130:
    // 0x1b3130: 0x90f10002  lbu         $s1, 0x2($a3)
    ctx->pc = 0x1b3130u;
    SET_GPR_U32(ctx, 17, (uint8_t)READ8(ADD32(GPR_U32(ctx, 7), 2)));
    // 0x1b3134: 0x11c142  srl         $t8, $s1, 5
    ctx->pc = 0x1b3134u;
    SET_GPR_S32(ctx, 24, (int32_t)SRL32(GPR_U32(ctx, 17), 5));
    // 0x1b3138: 0x3230001f  andi        $s0, $s1, 0x1F
    ctx->pc = 0x1b3138u;
    SET_GPR_U64(ctx, 16, GPR_U64(ctx, 17) & (uint64_t)(uint16_t)31);
    // 0x1b313c: 0x18c880  sll         $t9, $t8, 2
    ctx->pc = 0x1b313cu;
    SET_GPR_S32(ctx, 25, (int32_t)SLL32(GPR_U32(ctx, 24), 2));
    // 0x1b3140: 0x205c004  sllv        $t8, $a1, $s0
    ctx->pc = 0x1b3140u;
    SET_GPR_S32(ctx, 24, (int32_t)SLL32(GPR_U32(ctx, 5), GPR_U32(ctx, 16) & 0x1F));
    // 0x1b3144: 0xd98021  addu        $s0, $a2, $t9
    ctx->pc = 0x1b3144u;
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 6), GPR_U32(ctx, 25)));
    // 0x1b3148: 0x8e100000  lw          $s0, 0x0($s0)
    ctx->pc = 0x1b3148u;
    SET_GPR_S32(ctx, 16, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 0)));
    // 0x1b314c: 0x3108024  and         $s0, $t8, $s0
    ctx->pc = 0x1b314cu;
    SET_GPR_U64(ctx, 16, GPR_U64(ctx, 24) & GPR_U64(ctx, 16));
    // 0x1b3150: 0x10802b  sltu        $s0, $zero, $s0
    ctx->pc = 0x1b3150u;
    SET_GPR_U64(ctx, 16, ((uint64_t)GPR_U64(ctx, 0) < (uint64_t)GPR_U64(ctx, 16)) ? 1 : 0);
    // 0x1b3154: 0x12000059  beqz        $s0, . + 4 + (0x59 << 2)
    ctx->pc = 0x1B3154u;
    {
        const bool branch_taken_0x1b3154 = (GPR_U64(ctx, 16) == GPR_U64(ctx, 0));
        if (branch_taken_0x1b3154) {
            ctx->pc = 0x1B32BCu;
            goto label_1b32bc;
        }
    }
    ctx->pc = 0x1B315Cu;
    // 0x1b315c: 0x162d0057  bne         $s1, $t5, . + 4 + (0x57 << 2)
    ctx->pc = 0x1B315Cu;
    {
        const bool branch_taken_0x1b315c = (GPR_U64(ctx, 17) != GPR_U64(ctx, 13));
        if (branch_taken_0x1b315c) {
            ctx->pc = 0x1B32BCu;
            goto label_1b32bc;
        }
    }
    ctx->pc = 0x1B3164u;
    // 0x1b3164: 0x90f90022  lbu         $t9, 0x22($a3)
    ctx->pc = 0x1b3164u;
    SET_GPR_U32(ctx, 25, (uint8_t)READ8(ADD32(GPR_U32(ctx, 7), 34)));
    // 0x1b3168: 0x95900000  lhu         $s0, 0x0($t4)
    ctx->pc = 0x1b3168u;
    SET_GPR_U32(ctx, 16, (uint16_t)READ16(ADD32(GPR_U32(ctx, 12), 0)));
    // 0x1b316c: 0x19c040  sll         $t8, $t9, 1
    ctx->pc = 0x1b316cu;
    SET_GPR_S32(ctx, 24, (int32_t)SLL32(GPR_U32(ctx, 25), 1));
    // 0x1b3170: 0x98c021  addu        $t8, $a0, $t8
    ctx->pc = 0x1b3170u;
    SET_GPR_S32(ctx, 24, (int32_t)ADD32(GPR_U32(ctx, 4), GPR_U32(ctx, 24)));
    // 0x1b3174: 0x97180ca0  lhu         $t8, 0xCA0($t8)
    ctx->pc = 0x1b3174u;
    SET_GPR_U32(ctx, 24, (uint16_t)READ16(ADD32(GPR_U32(ctx, 24), 3232)));
    // 0x1b3178: 0x17100050  bne         $t8, $s0, . + 4 + (0x50 << 2)
    ctx->pc = 0x1B3178u;
    {
        const bool branch_taken_0x1b3178 = (GPR_U64(ctx, 24) != GPR_U64(ctx, 16));
        if (branch_taken_0x1b3178) {
            ctx->pc = 0x1B32BCu;
            goto label_1b32bc;
        }
    }
    ctx->pc = 0x1B3180u;
    // 0x1b3180: 0x90f00026  lbu         $s0, 0x26($a3)
    ctx->pc = 0x1b3180u;
    SET_GPR_U32(ctx, 16, (uint8_t)READ8(ADD32(GPR_U32(ctx, 7), 38)));
    // 0x1b3184: 0x16000003  bnez        $s0, . + 4 + (0x3 << 2)
    ctx->pc = 0x1B3184u;
    {
        const bool branch_taken_0x1b3184 = (GPR_U64(ctx, 16) != GPR_U64(ctx, 0));
        if (branch_taken_0x1b3184) {
            ctx->pc = 0x1B3194u;
            goto label_1b3194;
        }
    }
    ctx->pc = 0x1B318Cu;
    // 0x1b318c: 0x172f004b  bne         $t9, $t7, . + 4 + (0x4B << 2)
    ctx->pc = 0x1B318Cu;
    {
        const bool branch_taken_0x1b318c = (GPR_U64(ctx, 25) != GPR_U64(ctx, 15));
        if (branch_taken_0x1b318c) {
            ctx->pc = 0x1B32BCu;
            goto label_1b32bc;
        }
    }
    ctx->pc = 0x1B3194u;
label_1b3194:
    // 0x1b3194: 0x90f00004  lbu         $s0, 0x4($a3)
    ctx->pc = 0x1b3194u;
    SET_GPR_U32(ctx, 16, (uint8_t)READ8(ADD32(GPR_U32(ctx, 7), 4)));
    // 0x1b3198: 0x10c142  srl         $t8, $s0, 5
    ctx->pc = 0x1b3198u;
    SET_GPR_S32(ctx, 24, (int32_t)SRL32(GPR_U32(ctx, 16), 5));
    // 0x1b319c: 0x3210001f  andi        $s0, $s0, 0x1F
    ctx->pc = 0x1b319cu;
    SET_GPR_U64(ctx, 16, GPR_U64(ctx, 16) & (uint64_t)(uint16_t)31);
    // 0x1b31a0: 0x18c880  sll         $t9, $t8, 2
    ctx->pc = 0x1b31a0u;
    SET_GPR_S32(ctx, 25, (int32_t)SLL32(GPR_U32(ctx, 24), 2));
    // 0x1b31a4: 0x205c004  sllv        $t8, $a1, $s0
    ctx->pc = 0x1b31a4u;
    SET_GPR_S32(ctx, 24, (int32_t)SLL32(GPR_U32(ctx, 5), GPR_U32(ctx, 16) & 0x1F));
    // 0x1b31a8: 0x998021  addu        $s0, $a0, $t9
    ctx->pc = 0x1b31a8u;
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 4), GPR_U32(ctx, 25)));
    // 0x1b31ac: 0x8e100fb0  lw          $s0, 0xFB0($s0)
    ctx->pc = 0x1b31acu;
    SET_GPR_S32(ctx, 16, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 4016)));
    // 0x1b31b0: 0x2188024  and         $s0, $s0, $t8
    ctx->pc = 0x1b31b0u;
    SET_GPR_U64(ctx, 16, GPR_U64(ctx, 16) & GPR_U64(ctx, 24));
    // 0x1b31b4: 0x12000041  beqz        $s0, . + 4 + (0x41 << 2)
    ctx->pc = 0x1B31B4u;
    {
        const bool branch_taken_0x1b31b4 = (GPR_U64(ctx, 16) == GPR_U64(ctx, 0));
        if (branch_taken_0x1b31b4) {
            ctx->pc = 0x1B32BCu;
            goto label_1b32bc;
        }
    }
    ctx->pc = 0x1B31BCu;
    // 0x1b31bc: 0x15200007  bnez        $t1, . + 4 + (0x7 << 2)
    ctx->pc = 0x1B31BCu;
    {
        const bool branch_taken_0x1b31bc = (GPR_U64(ctx, 9) != GPR_U64(ctx, 0));
        ctx->pc = 0x1B31C0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1B31BCu;
            // 0x1b31c0: 0x902d  daddu       $s2, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 18, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1b31bc) {
            ctx->pc = 0x1B31DCu;
            goto label_1b31dc;
        }
    }
    ctx->pc = 0x1B31C4u;
    // 0x1b31c4: 0x90f80003  lbu         $t8, 0x3($a3)
    ctx->pc = 0x1b31c4u;
    SET_GPR_U32(ctx, 24, (uint8_t)READ8(ADD32(GPR_U32(ctx, 7), 3)));
    // 0x1b31c8: 0x98080  sll         $s0, $t1, 2
    ctx->pc = 0x1b31c8u;
    SET_GPR_S32(ctx, 16, (int32_t)SLL32(GPR_U32(ctx, 9), 2));
    // 0x1b31cc: 0x708021  addu        $s0, $v1, $s0
    ctx->pc = 0x1b31ccu;
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 16)));
    // 0x1b31d0: 0x25290001  addiu       $t1, $t1, 0x1
    ctx->pc = 0x1b31d0u;
    SET_GPR_S32(ctx, 9, (int32_t)ADD32(GPR_U32(ctx, 9), 1));
    // 0x1b31d4: 0x10000014  b           . + 4 + (0x14 << 2)
    ctx->pc = 0x1B31D4u;
    {
        const bool branch_taken_0x1b31d4 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1B31D8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1B31D4u;
            // 0x1b31d8: 0xae180080  sw          $t8, 0x80($s0) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 16), 128), GPR_U32(ctx, 24));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1b31d4) {
            ctx->pc = 0x1B3228u;
            goto label_1b3228;
        }
    }
    ctx->pc = 0x1B31DCu;
label_1b31dc:
    // 0x1b31dc: 0x10000008  b           . + 4 + (0x8 << 2)
    ctx->pc = 0x1B31DCu;
    {
        const bool branch_taken_0x1b31dc = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1B31E0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1B31DCu;
            // 0x1b31e0: 0x882d  daddu       $s1, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1b31dc) {
            ctx->pc = 0x1B3200u;
            goto label_1b3200;
        }
    }
    ctx->pc = 0x1B31E4u;
label_1b31e4:
    // 0x1b31e4: 0x90f00003  lbu         $s0, 0x3($a3)
    ctx->pc = 0x1b31e4u;
    SET_GPR_U32(ctx, 16, (uint8_t)READ8(ADD32(GPR_U32(ctx, 7), 3)));
    // 0x1b31e8: 0x78c021  addu        $t8, $v1, $t8
    ctx->pc = 0x1b31e8u;
    SET_GPR_S32(ctx, 24, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 24)));
    // 0x1b31ec: 0x8f180080  lw          $t8, 0x80($t8)
    ctx->pc = 0x1b31ecu;
    SET_GPR_S32(ctx, 24, (int32_t)READ32(ADD32(GPR_U32(ctx, 24), 128)));
    // 0x1b31f0: 0x17100002  bne         $t8, $s0, . + 4 + (0x2 << 2)
    ctx->pc = 0x1B31F0u;
    {
        const bool branch_taken_0x1b31f0 = (GPR_U64(ctx, 24) != GPR_U64(ctx, 16));
        if (branch_taken_0x1b31f0) {
            ctx->pc = 0x1B31FCu;
            goto label_1b31fc;
        }
    }
    ctx->pc = 0x1B31F8u;
    // 0x1b31f8: 0x24120001  addiu       $s2, $zero, 0x1
    ctx->pc = 0x1b31f8u;
    SET_GPR_S32(ctx, 18, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
label_1b31fc:
    // 0x1b31fc: 0x26310001  addiu       $s1, $s1, 0x1
    ctx->pc = 0x1b31fcu;
    SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 17), 1));
label_1b3200:
    // 0x1b3200: 0x229802a  slt         $s0, $s1, $t1
    ctx->pc = 0x1b3200u;
    SET_GPR_U64(ctx, 16, ((int64_t)GPR_S64(ctx, 17) < (int64_t)GPR_S64(ctx, 9)) ? 1 : 0);
    // 0x1b3204: 0x1600fff7  bnez        $s0, . + 4 + (-0x9 << 2)
    ctx->pc = 0x1B3204u;
    {
        const bool branch_taken_0x1b3204 = (GPR_U64(ctx, 16) != GPR_U64(ctx, 0));
        ctx->pc = 0x1B3208u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1B3204u;
            // 0x1b3208: 0x11c080  sll         $t8, $s1, 2 (Delay Slot)
        SET_GPR_S32(ctx, 24, (int32_t)SLL32(GPR_U32(ctx, 17), 2));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1b3204) {
            ctx->pc = 0x1B31E4u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_1b31e4;
        }
    }
    ctx->pc = 0x1B320Cu;
    // 0x1b320c: 0x16400006  bnez        $s2, . + 4 + (0x6 << 2)
    ctx->pc = 0x1B320Cu;
    {
        const bool branch_taken_0x1b320c = (GPR_U64(ctx, 18) != GPR_U64(ctx, 0));
        if (branch_taken_0x1b320c) {
            ctx->pc = 0x1B3228u;
            goto label_1b3228;
        }
    }
    ctx->pc = 0x1B3214u;
    // 0x1b3214: 0x90f80003  lbu         $t8, 0x3($a3)
    ctx->pc = 0x1b3214u;
    SET_GPR_U32(ctx, 24, (uint8_t)READ8(ADD32(GPR_U32(ctx, 7), 3)));
    // 0x1b3218: 0x98080  sll         $s0, $t1, 2
    ctx->pc = 0x1b3218u;
    SET_GPR_S32(ctx, 16, (int32_t)SLL32(GPR_U32(ctx, 9), 2));
    // 0x1b321c: 0x708021  addu        $s0, $v1, $s0
    ctx->pc = 0x1b321cu;
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 16)));
    // 0x1b3220: 0x25290001  addiu       $t1, $t1, 0x1
    ctx->pc = 0x1b3220u;
    SET_GPR_S32(ctx, 9, (int32_t)ADD32(GPR_U32(ctx, 9), 1));
    // 0x1b3224: 0xae180080  sw          $t8, 0x80($s0)
    ctx->pc = 0x1b3224u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 128), GPR_U32(ctx, 24));
label_1b3228:
    // 0x1b3228: 0x1500000a  bnez        $t0, . + 4 + (0xA << 2)
    ctx->pc = 0x1B3228u;
    {
        const bool branch_taken_0x1b3228 = (GPR_U64(ctx, 8) != GPR_U64(ctx, 0));
        ctx->pc = 0x1B322Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1B3228u;
            // 0x1b322c: 0x902d  daddu       $s2, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 18, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1b3228) {
            ctx->pc = 0x1B3254u;
            goto label_1b3254;
        }
    }
    ctx->pc = 0x1B3230u;
    // 0x1b3230: 0x95980000  lhu         $t8, 0x0($t4)
    ctx->pc = 0x1b3230u;
    SET_GPR_U32(ctx, 24, (uint16_t)READ16(ADD32(GPR_U32(ctx, 12), 0)));
    // 0x1b3234: 0x88080  sll         $s0, $t0, 2
    ctx->pc = 0x1b3234u;
    SET_GPR_S32(ctx, 16, (int32_t)SLL32(GPR_U32(ctx, 8), 2));
    // 0x1b3238: 0x708021  addu        $s0, $v1, $s0
    ctx->pc = 0x1b3238u;
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 16)));
    // 0x1b323c: 0x25080001  addiu       $t0, $t0, 0x1
    ctx->pc = 0x1b323cu;
    SET_GPR_S32(ctx, 8, (int32_t)ADD32(GPR_U32(ctx, 8), 1));
    // 0x1b3240: 0x18c040  sll         $t8, $t8, 1
    ctx->pc = 0x1b3240u;
    SET_GPR_S32(ctx, 24, (int32_t)SLL32(GPR_U32(ctx, 24), 1));
    // 0x1b3244: 0x98c021  addu        $t8, $a0, $t8
    ctx->pc = 0x1b3244u;
    SET_GPR_S32(ctx, 24, (int32_t)ADD32(GPR_U32(ctx, 4), GPR_U32(ctx, 24)));
    // 0x1b3248: 0x97180eb0  lhu         $t8, 0xEB0($t8)
    ctx->pc = 0x1b3248u;
    SET_GPR_U32(ctx, 24, (uint16_t)READ16(ADD32(GPR_U32(ctx, 24), 3760)));
    // 0x1b324c: 0x1000001b  b           . + 4 + (0x1B << 2)
    ctx->pc = 0x1B324Cu;
    {
        const bool branch_taken_0x1b324c = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1B3250u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1B324Cu;
            // 0x1b3250: 0xae180180  sw          $t8, 0x180($s0) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 16), 384), GPR_U32(ctx, 24));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1b324c) {
            ctx->pc = 0x1B32BCu;
            goto label_1b32bc;
        }
    }
    ctx->pc = 0x1B3254u;
label_1b3254:
    // 0x1b3254: 0x1000000c  b           . + 4 + (0xC << 2)
    ctx->pc = 0x1B3254u;
    {
        const bool branch_taken_0x1b3254 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1B3258u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1B3254u;
            // 0x1b3258: 0x882d  daddu       $s1, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1b3254) {
            ctx->pc = 0x1B3288u;
            goto label_1b3288;
        }
    }
    ctx->pc = 0x1B325Cu;
label_1b325c:
    // 0x1b325c: 0x95900000  lhu         $s0, 0x0($t4)
    ctx->pc = 0x1b325cu;
    SET_GPR_U32(ctx, 16, (uint16_t)READ16(ADD32(GPR_U32(ctx, 12), 0)));
    // 0x1b3260: 0x11c080  sll         $t8, $s1, 2
    ctx->pc = 0x1b3260u;
    SET_GPR_S32(ctx, 24, (int32_t)SLL32(GPR_U32(ctx, 17), 2));
    // 0x1b3264: 0x78c021  addu        $t8, $v1, $t8
    ctx->pc = 0x1b3264u;
    SET_GPR_S32(ctx, 24, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 24)));
    // 0x1b3268: 0x8f180180  lw          $t8, 0x180($t8)
    ctx->pc = 0x1b3268u;
    SET_GPR_S32(ctx, 24, (int32_t)READ32(ADD32(GPR_U32(ctx, 24), 384)));
    // 0x1b326c: 0x108040  sll         $s0, $s0, 1
    ctx->pc = 0x1b326cu;
    SET_GPR_S32(ctx, 16, (int32_t)SLL32(GPR_U32(ctx, 16), 1));
    // 0x1b3270: 0x908021  addu        $s0, $a0, $s0
    ctx->pc = 0x1b3270u;
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 4), GPR_U32(ctx, 16)));
    // 0x1b3274: 0x96100eb0  lhu         $s0, 0xEB0($s0)
    ctx->pc = 0x1b3274u;
    SET_GPR_U32(ctx, 16, (uint16_t)READ16(ADD32(GPR_U32(ctx, 16), 3760)));
    // 0x1b3278: 0x17100002  bne         $t8, $s0, . + 4 + (0x2 << 2)
    ctx->pc = 0x1B3278u;
    {
        const bool branch_taken_0x1b3278 = (GPR_U64(ctx, 24) != GPR_U64(ctx, 16));
        if (branch_taken_0x1b3278) {
            ctx->pc = 0x1B3284u;
            goto label_1b3284;
        }
    }
    ctx->pc = 0x1B3280u;
    // 0x1b3280: 0x24120001  addiu       $s2, $zero, 0x1
    ctx->pc = 0x1b3280u;
    SET_GPR_S32(ctx, 18, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
label_1b3284:
    // 0x1b3284: 0x26310001  addiu       $s1, $s1, 0x1
    ctx->pc = 0x1b3284u;
    SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 17), 1));
label_1b3288:
    // 0x1b3288: 0x228802a  slt         $s0, $s1, $t0
    ctx->pc = 0x1b3288u;
    SET_GPR_U64(ctx, 16, ((int64_t)GPR_S64(ctx, 17) < (int64_t)GPR_S64(ctx, 8)) ? 1 : 0);
    // 0x1b328c: 0x1600fff3  bnez        $s0, . + 4 + (-0xD << 2)
    ctx->pc = 0x1B328Cu;
    {
        const bool branch_taken_0x1b328c = (GPR_U64(ctx, 16) != GPR_U64(ctx, 0));
        if (branch_taken_0x1b328c) {
            ctx->pc = 0x1B325Cu;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_1b325c;
        }
    }
    ctx->pc = 0x1B3294u;
    // 0x1b3294: 0x16400009  bnez        $s2, . + 4 + (0x9 << 2)
    ctx->pc = 0x1B3294u;
    {
        const bool branch_taken_0x1b3294 = (GPR_U64(ctx, 18) != GPR_U64(ctx, 0));
        if (branch_taken_0x1b3294) {
            ctx->pc = 0x1B32BCu;
            goto label_1b32bc;
        }
    }
    ctx->pc = 0x1B329Cu;
    // 0x1b329c: 0x95980000  lhu         $t8, 0x0($t4)
    ctx->pc = 0x1b329cu;
    SET_GPR_U32(ctx, 24, (uint16_t)READ16(ADD32(GPR_U32(ctx, 12), 0)));
    // 0x1b32a0: 0x88080  sll         $s0, $t0, 2
    ctx->pc = 0x1b32a0u;
    SET_GPR_S32(ctx, 16, (int32_t)SLL32(GPR_U32(ctx, 8), 2));
    // 0x1b32a4: 0x708021  addu        $s0, $v1, $s0
    ctx->pc = 0x1b32a4u;
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 16)));
    // 0x1b32a8: 0x25080001  addiu       $t0, $t0, 0x1
    ctx->pc = 0x1b32a8u;
    SET_GPR_S32(ctx, 8, (int32_t)ADD32(GPR_U32(ctx, 8), 1));
    // 0x1b32ac: 0x18c040  sll         $t8, $t8, 1
    ctx->pc = 0x1b32acu;
    SET_GPR_S32(ctx, 24, (int32_t)SLL32(GPR_U32(ctx, 24), 1));
    // 0x1b32b0: 0x98c021  addu        $t8, $a0, $t8
    ctx->pc = 0x1b32b0u;
    SET_GPR_S32(ctx, 24, (int32_t)ADD32(GPR_U32(ctx, 4), GPR_U32(ctx, 24)));
    // 0x1b32b4: 0x97180eb0  lhu         $t8, 0xEB0($t8)
    ctx->pc = 0x1b32b4u;
    SET_GPR_U32(ctx, 24, (uint16_t)READ16(ADD32(GPR_U32(ctx, 24), 3760)));
    // 0x1b32b8: 0xae180180  sw          $t8, 0x180($s0)
    ctx->pc = 0x1b32b8u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 384), GPR_U32(ctx, 24));
label_1b32bc:
    // 0x1b32bc: 0x254a0001  addiu       $t2, $t2, 0x1
    ctx->pc = 0x1b32bcu;
    SET_GPR_S32(ctx, 10, (int32_t)ADD32(GPR_U32(ctx, 10), 1));
    // 0x1b32c0: 0x24e70060  addiu       $a3, $a3, 0x60
    ctx->pc = 0x1b32c0u;
    SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 7), 96));
label_1b32c4:
    // 0x1b32c4: 0x14e802a  slt         $s0, $t2, $t6
    ctx->pc = 0x1b32c4u;
    SET_GPR_U64(ctx, 16, ((int64_t)GPR_S64(ctx, 10) < (int64_t)GPR_S64(ctx, 14)) ? 1 : 0);
    // 0x1b32c8: 0x1600ff99  bnez        $s0, . + 4 + (-0x67 << 2)
    ctx->pc = 0x1B32C8u;
    {
        const bool branch_taken_0x1b32c8 = (GPR_U64(ctx, 16) != GPR_U64(ctx, 0));
        ctx->pc = 0x1B32CCu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1B32C8u;
            // 0x1b32cc: 0x3c01004c  lui         $at, 0x4C (Delay Slot)
        SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)76 << 16));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1b32c8) {
            ctx->pc = 0x1B3130u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_1b3130;
        }
    }
    ctx->pc = 0x1B32D0u;
    // 0x1b32d0: 0xa42ba82e  sh          $t3, -0x57D2($at)
    ctx->pc = 0x1b32d0u;
    WRITE16(ADD32(GPR_U32(ctx, 1), 4294944814), (uint16_t)GPR_U32(ctx, 11));
    // 0x1b32d4: 0x7bb20020  lq          $s2, 0x20($sp)
    ctx->pc = 0x1b32d4u;
    SET_GPR_VEC(ctx, 18, READ128(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x1b32d8: 0x7bb10010  lq          $s1, 0x10($sp)
    ctx->pc = 0x1b32d8u;
    SET_GPR_VEC(ctx, 17, READ128(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x1b32dc: 0x7bb00000  lq          $s0, 0x0($sp)
    ctx->pc = 0x1b32dcu;
    SET_GPR_VEC(ctx, 16, READ128(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1b32e0: 0x3e00008  jr          $ra
    ctx->pc = 0x1B32E0u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1B32E4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1B32E0u;
            // 0x1b32e4: 0x27bd0030  addiu       $sp, $sp, 0x30 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 48));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1B2D44u: goto label_1b2d44;
            case 0x1B2D70u: goto label_1b2d70;
            case 0x1B2DACu: goto label_1b2dac;
            case 0x1B2DC0u: goto label_1b2dc0;
            case 0x1B2E58u: goto label_1b2e58;
            case 0x1B2E64u: goto label_1b2e64;
            case 0x1B2EE0u: goto label_1b2ee0;
            case 0x1B2F44u: goto label_1b2f44;
            case 0x1B2F8Cu: goto label_1b2f8c;
            case 0x1B2F94u: goto label_1b2f94;
            case 0x1B2FACu: goto label_1b2fac;
            case 0x1B2FB0u: goto label_1b2fb0;
            case 0x1B2FD8u: goto label_1b2fd8;
            case 0x1B3004u: goto label_1b3004;
            case 0x1B300Cu: goto label_1b300c;
            case 0x1B3034u: goto label_1b3034;
            case 0x1B3038u: goto label_1b3038;
            case 0x1B306Cu: goto label_1b306c;
            case 0x1B3074u: goto label_1b3074;
            case 0x1B30BCu: goto label_1b30bc;
            case 0x1B30C8u: goto label_1b30c8;
            case 0x1B3130u: goto label_1b3130;
            case 0x1B3194u: goto label_1b3194;
            case 0x1B31DCu: goto label_1b31dc;
            case 0x1B31E4u: goto label_1b31e4;
            case 0x1B31FCu: goto label_1b31fc;
            case 0x1B3200u: goto label_1b3200;
            case 0x1B3228u: goto label_1b3228;
            case 0x1B3254u: goto label_1b3254;
            case 0x1B325Cu: goto label_1b325c;
            case 0x1B3284u: goto label_1b3284;
            case 0x1B3288u: goto label_1b3288;
            case 0x1B32BCu: goto label_1b32bc;
            case 0x1B32C4u: goto label_1b32c4;
            case 0x1B3340u: goto label_1b3340;
            case 0x1B338Cu: goto label_1b338c;
            case 0x1B3390u: goto label_1b3390;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1B32E8u;
    // 0x1b32e8: 0x0  nop
    ctx->pc = 0x1b32e8u;
    // NOP
    // 0x1b32ec: 0x0  nop
    ctx->pc = 0x1b32ecu;
    // NOP
    // 0x1b32f0: 0x3c01004c  lui         $at, 0x4C
    ctx->pc = 0x1b32f0u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)76 << 16));
    // 0x1b32f4: 0x90860002  lbu         $a2, 0x2($a0)
    ctx->pc = 0x1b32f4u;
    SET_GPR_U32(ctx, 6, (uint8_t)READ8(ADD32(GPR_U32(ctx, 4), 2)));
    // 0x1b32f8: 0x9422a820  lhu         $v0, -0x57E0($at)
    ctx->pc = 0x1b32f8u;
    SET_GPR_U32(ctx, 2, (uint16_t)READ16(ADD32(GPR_U32(ctx, 1), 4294944800)));
    // 0x1b32fc: 0x14c20010  bne         $a2, $v0, . + 4 + (0x10 << 2)
    ctx->pc = 0x1B32FCu;
    {
        const bool branch_taken_0x1b32fc = (GPR_U64(ctx, 6) != GPR_U64(ctx, 2));
        if (branch_taken_0x1b32fc) {
            ctx->pc = 0x1B3340u;
            goto label_1b3340;
        }
    }
    ctx->pc = 0x1B3304u;
    // 0x1b3304: 0x3c010032  lui         $at, 0x32
    ctx->pc = 0x1b3304u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)50 << 16));
    // 0x1b3308: 0x90820022  lbu         $v0, 0x22($a0)
    ctx->pc = 0x1b3308u;
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 4), 34)));
    // 0x1b330c: 0x942343dc  lhu         $v1, 0x43DC($at)
    ctx->pc = 0x1b330cu;
    SET_GPR_U32(ctx, 3, (uint16_t)READ16(ADD32(GPR_U32(ctx, 1), 17372)));
    // 0x1b3310: 0x3c05004c  lui         $a1, 0x4C
    ctx->pc = 0x1b3310u;
    SET_GPR_S32(ctx, 5, (int32_t)((uint32_t)76 << 16));
    // 0x1b3314: 0x24a5a620  addiu       $a1, $a1, -0x59E0
    ctx->pc = 0x1b3314u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 4294944288));
    // 0x1b3318: 0x21040  sll         $v0, $v0, 1
    ctx->pc = 0x1b3318u;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 2), 1));
    // 0x1b331c: 0x31840  sll         $v1, $v1, 1
    ctx->pc = 0x1b331cu;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 3), 1));
    // 0x1b3320: 0xa21021  addu        $v0, $a1, $v0
    ctx->pc = 0x1b3320u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 5), GPR_U32(ctx, 2)));
    // 0x1b3324: 0xa31821  addu        $v1, $a1, $v1
    ctx->pc = 0x1b3324u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 5), GPR_U32(ctx, 3)));
    // 0x1b3328: 0x94420000  lhu         $v0, 0x0($v0)
    ctx->pc = 0x1b3328u;
    SET_GPR_U32(ctx, 2, (uint16_t)READ16(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x1b332c: 0x94630000  lhu         $v1, 0x0($v1)
    ctx->pc = 0x1b332cu;
    SET_GPR_U32(ctx, 3, (uint16_t)READ16(ADD32(GPR_U32(ctx, 3), 0)));
    // 0x1b3330: 0x14620003  bne         $v1, $v0, . + 4 + (0x3 << 2)
    ctx->pc = 0x1B3330u;
    {
        const bool branch_taken_0x1b3330 = (GPR_U64(ctx, 3) != GPR_U64(ctx, 2));
        if (branch_taken_0x1b3330) {
            ctx->pc = 0x1B3340u;
            goto label_1b3340;
        }
    }
    ctx->pc = 0x1B3338u;
    // 0x1b3338: 0x10000015  b           . + 4 + (0x15 << 2)
    ctx->pc = 0x1B3338u;
    {
        const bool branch_taken_0x1b3338 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1B333Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1B3338u;
            // 0x1b333c: 0x24020001  addiu       $v0, $zero, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1b3338) {
            ctx->pc = 0x1B3390u;
            goto label_1b3390;
        }
    }
    ctx->pc = 0x1B3340u;
label_1b3340:
    // 0x1b3340: 0x3c01004c  lui         $at, 0x4C
    ctx->pc = 0x1b3340u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)76 << 16));
    // 0x1b3344: 0x9422a822  lhu         $v0, -0x57DE($at)
    ctx->pc = 0x1b3344u;
    SET_GPR_U32(ctx, 2, (uint16_t)READ16(ADD32(GPR_U32(ctx, 1), 4294944802)));
    // 0x1b3348: 0x14c20011  bne         $a2, $v0, . + 4 + (0x11 << 2)
    ctx->pc = 0x1B3348u;
    {
        const bool branch_taken_0x1b3348 = (GPR_U64(ctx, 6) != GPR_U64(ctx, 2));
        ctx->pc = 0x1B334Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1B3348u;
            // 0x1b334c: 0x102d  daddu       $v0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1b3348) {
            ctx->pc = 0x1B3390u;
            goto label_1b3390;
        }
    }
    ctx->pc = 0x1B3350u;
    // 0x1b3350: 0x90820022  lbu         $v0, 0x22($a0)
    ctx->pc = 0x1b3350u;
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 4), 34)));
    // 0x1b3354: 0x3c010032  lui         $at, 0x32
    ctx->pc = 0x1b3354u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)50 << 16));
    // 0x1b3358: 0x3c03004c  lui         $v1, 0x4C
    ctx->pc = 0x1b3358u;
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)76 << 16));
    // 0x1b335c: 0x2463a720  addiu       $v1, $v1, -0x58E0
    ctx->pc = 0x1b335cu;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 4294944544));
    // 0x1b3360: 0x942443dc  lhu         $a0, 0x43DC($at)
    ctx->pc = 0x1b3360u;
    SET_GPR_U32(ctx, 4, (uint16_t)READ16(ADD32(GPR_U32(ctx, 1), 17372)));
    // 0x1b3364: 0x21040  sll         $v0, $v0, 1
    ctx->pc = 0x1b3364u;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 2), 1));
    // 0x1b3368: 0x621021  addu        $v0, $v1, $v0
    ctx->pc = 0x1b3368u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 2)));
    // 0x1b336c: 0x94420000  lhu         $v0, 0x0($v0)
    ctx->pc = 0x1b336cu;
    SET_GPR_U32(ctx, 2, (uint16_t)READ16(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x1b3370: 0x42040  sll         $a0, $a0, 1
    ctx->pc = 0x1b3370u;
    SET_GPR_S32(ctx, 4, (int32_t)SLL32(GPR_U32(ctx, 4), 1));
    // 0x1b3374: 0x641821  addu        $v1, $v1, $a0
    ctx->pc = 0x1b3374u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 4)));
    // 0x1b3378: 0x94630000  lhu         $v1, 0x0($v1)
    ctx->pc = 0x1b3378u;
    SET_GPR_U32(ctx, 3, (uint16_t)READ16(ADD32(GPR_U32(ctx, 3), 0)));
    // 0x1b337c: 0x14620003  bne         $v1, $v0, . + 4 + (0x3 << 2)
    ctx->pc = 0x1B337Cu;
    {
        const bool branch_taken_0x1b337c = (GPR_U64(ctx, 3) != GPR_U64(ctx, 2));
        ctx->pc = 0x1B3380u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1B337Cu;
            // 0x1b3380: 0x24020001  addiu       $v0, $zero, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1b337c) {
            ctx->pc = 0x1B338Cu;
            goto label_1b338c;
        }
    }
    ctx->pc = 0x1B3384u;
    // 0x1b3384: 0x10000002  b           . + 4 + (0x2 << 2)
    ctx->pc = 0x1B3384u;
    {
        const bool branch_taken_0x1b3384 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x1b3384) {
            ctx->pc = 0x1B3390u;
            goto label_1b3390;
        }
    }
    ctx->pc = 0x1B338Cu;
label_1b338c:
    // 0x1b338c: 0x102d  daddu       $v0, $zero, $zero
    ctx->pc = 0x1b338cu;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
label_1b3390:
    // 0x1b3390: 0x3e00008  jr          $ra
    ctx->pc = 0x1B3390u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1B2D44u: goto label_1b2d44;
            case 0x1B2D70u: goto label_1b2d70;
            case 0x1B2DACu: goto label_1b2dac;
            case 0x1B2DC0u: goto label_1b2dc0;
            case 0x1B2E58u: goto label_1b2e58;
            case 0x1B2E64u: goto label_1b2e64;
            case 0x1B2EE0u: goto label_1b2ee0;
            case 0x1B2F44u: goto label_1b2f44;
            case 0x1B2F8Cu: goto label_1b2f8c;
            case 0x1B2F94u: goto label_1b2f94;
            case 0x1B2FACu: goto label_1b2fac;
            case 0x1B2FB0u: goto label_1b2fb0;
            case 0x1B2FD8u: goto label_1b2fd8;
            case 0x1B3004u: goto label_1b3004;
            case 0x1B300Cu: goto label_1b300c;
            case 0x1B3034u: goto label_1b3034;
            case 0x1B3038u: goto label_1b3038;
            case 0x1B306Cu: goto label_1b306c;
            case 0x1B3074u: goto label_1b3074;
            case 0x1B30BCu: goto label_1b30bc;
            case 0x1B30C8u: goto label_1b30c8;
            case 0x1B3130u: goto label_1b3130;
            case 0x1B3194u: goto label_1b3194;
            case 0x1B31DCu: goto label_1b31dc;
            case 0x1B31E4u: goto label_1b31e4;
            case 0x1B31FCu: goto label_1b31fc;
            case 0x1B3200u: goto label_1b3200;
            case 0x1B3228u: goto label_1b3228;
            case 0x1B3254u: goto label_1b3254;
            case 0x1B325Cu: goto label_1b325c;
            case 0x1B3284u: goto label_1b3284;
            case 0x1B3288u: goto label_1b3288;
            case 0x1B32BCu: goto label_1b32bc;
            case 0x1B32C4u: goto label_1b32c4;
            case 0x1B3340u: goto label_1b3340;
            case 0x1B338Cu: goto label_1b338c;
            case 0x1B3390u: goto label_1b3390;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1B3398u;
    // 0x1b3398: 0x0  nop
    ctx->pc = 0x1b3398u;
    // NOP
    // 0x1b339c: 0x0  nop
    ctx->pc = 0x1b339cu;
    // NOP
    // 0x1b33a0: 0x806315c  j           func_18C570
    ctx->pc = 0x1B33A0u;
    ctx->pc = 0x18C570u;
    {
        auto targetFn = runtime->lookupFunction(0x18C570u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        return;
    }
    ctx->pc = 0x1B33A8u;
    // 0x1b33a8: 0x0  nop
    ctx->pc = 0x1b33a8u;
    // NOP
    // 0x1b33ac: 0x0  nop
    ctx->pc = 0x1b33acu;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
