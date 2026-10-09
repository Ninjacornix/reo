#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001B7CB0
// Address: 0x1b7cb0 - 0x1b7ee0
void sub_001B7CB0_0x1b7cb0(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001B7CB0_0x1b7cb0");
#endif

    switch (ctx->pc) {
        case 0x1b7ce4u: goto label_1b7ce4;
        case 0x1b7d1cu: goto label_1b7d1c;
        case 0x1b7d44u: goto label_1b7d44;
        case 0x1b7da8u: goto label_1b7da8;
        case 0x1b7dc0u: goto label_1b7dc0;
        case 0x1b7e40u: goto label_1b7e40;
        case 0x1b7ea0u: goto label_1b7ea0;
        case 0x1b7eb0u: goto label_1b7eb0;
        case 0x1b7eb8u: goto label_1b7eb8;
        default: break;
    }

    ctx->pc = 0x1b7cb0u;

    // 0x1b7cb0: 0x27bdffb0  addiu       $sp, $sp, -0x50
    ctx->pc = 0x1b7cb0u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967216));
    // 0x1b7cb4: 0x3c010023  lui         $at, 0x23
    ctx->pc = 0x1b7cb4u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)35 << 16));
    // 0x1b7cb8: 0xffbf0040  sd          $ra, 0x40($sp)
    ctx->pc = 0x1b7cb8u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 64), GPR_U64(ctx, 31));
    // 0x1b7cbc: 0x2402ffff  addiu       $v0, $zero, -0x1
    ctx->pc = 0x1b7cbcu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
    // 0x1b7cc0: 0x7fb30030  sq          $s3, 0x30($sp)
    ctx->pc = 0x1b7cc0u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 48), GPR_VEC(ctx, 19));
    // 0x1b7cc4: 0x7fb20020  sq          $s2, 0x20($sp)
    ctx->pc = 0x1b7cc4u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 32), GPR_VEC(ctx, 18));
    // 0x1b7cc8: 0x7fb10010  sq          $s1, 0x10($sp)
    ctx->pc = 0x1b7cc8u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 16), GPR_VEC(ctx, 17));
    // 0x1b7ccc: 0x7fb00000  sq          $s0, 0x0($sp)
    ctx->pc = 0x1b7cccu;
    WRITE128(ADD32(GPR_U32(ctx, 29), 0), GPR_VEC(ctx, 16));
    // 0x1b7cd0: 0x802447f0  lb          $a0, 0x47F0($at)
    ctx->pc = 0x1b7cd0u;
    SET_GPR_S32(ctx, 4, (int8_t)READ8(ADD32(GPR_U32(ctx, 1), 18416)));
    // 0x1b7cd4: 0x10820014  beq         $a0, $v0, . + 4 + (0x14 << 2)
    ctx->pc = 0x1B7CD4u;
    {
        const bool branch_taken_0x1b7cd4 = (GPR_U64(ctx, 4) == GPR_U64(ctx, 2));
        if (branch_taken_0x1b7cd4) {
            ctx->pc = 0x1B7D28u;
            goto label_1b7d28;
        }
    }
    ctx->pc = 0x1B7CDCu;
    // 0x1b7cdc: 0xc06a568  jal         func_1A95A0
    ctx->pc = 0x1B7CDCu;
    SET_GPR_U32(ctx, 31, 0x1B7CE4u);
    ctx->pc = 0x1A95A0u;
    if (runtime->hasFunction(0x1A95A0u)) {
        auto targetFn = runtime->lookupFunction(0x1A95A0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1B7CE4u; }
        if (ctx->pc != 0x1B7CE4u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001A95A0_0x1a95a0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1B7CE4u; }
        if (ctx->pc != 0x1B7CE4u) { return; }
    }
    ctx->pc = 0x1B7CE4u;
label_1b7ce4:
    // 0x1b7ce4: 0x3c010023  lui         $at, 0x23
    ctx->pc = 0x1b7ce4u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)35 << 16));
    // 0x1b7ce8: 0x3c110031  lui         $s1, 0x31
    ctx->pc = 0x1b7ce8u;
    SET_GPR_S32(ctx, 17, (int32_t)((uint32_t)49 << 16));
    // 0x1b7cec: 0x802347f0  lb          $v1, 0x47F0($at)
    ctx->pc = 0x1b7cecu;
    SET_GPR_S32(ctx, 3, (int8_t)READ8(ADD32(GPR_U32(ctx, 1), 18416)));
    // 0x1b7cf0: 0x263163d0  addiu       $s1, $s1, 0x63D0
    ctx->pc = 0x1b7cf0u;
    SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 17), 25552));
    // 0x1b7cf4: 0x2402ffff  addiu       $v0, $zero, -0x1
    ctx->pc = 0x1b7cf4u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
    // 0x1b7cf8: 0x282d  daddu       $a1, $zero, $zero
    ctx->pc = 0x1b7cf8u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1b7cfc: 0x220202d  daddu       $a0, $s1, $zero
    ctx->pc = 0x1b7cfcu;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1b7d00: 0x3c010032  lui         $at, 0x32
    ctx->pc = 0x1b7d00u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)50 << 16));
    // 0x1b7d04: 0xa02343f8  sb          $v1, 0x43F8($at)
    ctx->pc = 0x1b7d04u;
    WRITE8(ADD32(GPR_U32(ctx, 1), 17400), (uint8_t)GPR_U32(ctx, 3));
    // 0x1b7d08: 0x3c010023  lui         $at, 0x23
    ctx->pc = 0x1b7d08u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)35 << 16));
    // 0x1b7d0c: 0xa02247f0  sb          $v0, 0x47F0($at)
    ctx->pc = 0x1b7d0cu;
    WRITE8(ADD32(GPR_U32(ctx, 1), 18416), (uint8_t)GPR_U32(ctx, 2));
    // 0x1b7d10: 0x8e300004  lw          $s0, 0x4($s1)
    ctx->pc = 0x1b7d10u;
    SET_GPR_S32(ctx, 16, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 4)));
    // 0x1b7d14: 0xc041f1a  jal         func_107C68
    ctx->pc = 0x1B7D14u;
    SET_GPR_U32(ctx, 31, 0x1B7D1Cu);
    ctx->pc = 0x1B7D18u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1B7D14u;
            // 0x1b7d18: 0x24060020  addiu       $a2, $zero, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 0), 32));
        ctx->in_delay_slot = false;
    ctx->pc = 0x107C68u;
    if (runtime->hasFunction(0x107C68u)) {
        auto targetFn = runtime->lookupFunction(0x107C68u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1B7D1Cu; }
        if (ctx->pc != 0x1B7D1Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00107C68_0x107c68(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1B7D1Cu; }
        if (ctx->pc != 0x1B7D1Cu) { return; }
    }
    ctx->pc = 0x1B7D1Cu;
label_1b7d1c:
    // 0x1b7d1c: 0xae300004  sw          $s0, 0x4($s1)
    ctx->pc = 0x1b7d1cu;
    WRITE32(ADD32(GPR_U32(ctx, 17), 4), GPR_U32(ctx, 16));
    // 0x1b7d20: 0x24020004  addiu       $v0, $zero, 0x4
    ctx->pc = 0x1b7d20u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4));
    // 0x1b7d24: 0xa6220000  sh          $v0, 0x0($s1)
    ctx->pc = 0x1b7d24u;
    WRITE16(ADD32(GPR_U32(ctx, 17), 0), (uint16_t)GPR_U32(ctx, 2));
label_1b7d28:
    // 0x1b7d28: 0x3c010023  lui         $at, 0x23
    ctx->pc = 0x1b7d28u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)35 << 16));
    // 0x1b7d2c: 0x2402ffff  addiu       $v0, $zero, -0x1
    ctx->pc = 0x1b7d2cu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
    // 0x1b7d30: 0x802447f8  lb          $a0, 0x47F8($at)
    ctx->pc = 0x1b7d30u;
    SET_GPR_S32(ctx, 4, (int8_t)READ8(ADD32(GPR_U32(ctx, 1), 18424)));
    // 0x1b7d34: 0x1082000a  beq         $a0, $v0, . + 4 + (0xA << 2)
    ctx->pc = 0x1B7D34u;
    {
        const bool branch_taken_0x1b7d34 = (GPR_U64(ctx, 4) == GPR_U64(ctx, 2));
        if (branch_taken_0x1b7d34) {
            ctx->pc = 0x1B7D60u;
            goto label_1b7d60;
        }
    }
    ctx->pc = 0x1B7D3Cu;
    // 0x1b7d3c: 0xc06a568  jal         func_1A95A0
    ctx->pc = 0x1B7D3Cu;
    SET_GPR_U32(ctx, 31, 0x1B7D44u);
    ctx->pc = 0x1A95A0u;
    if (runtime->hasFunction(0x1A95A0u)) {
        auto targetFn = runtime->lookupFunction(0x1A95A0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1B7D44u; }
        if (ctx->pc != 0x1B7D44u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001A95A0_0x1a95a0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1B7D44u; }
        if (ctx->pc != 0x1B7D44u) { return; }
    }
    ctx->pc = 0x1B7D44u;
label_1b7d44:
    // 0x1b7d44: 0x3c010023  lui         $at, 0x23
    ctx->pc = 0x1b7d44u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)35 << 16));
    // 0x1b7d48: 0x2402ffff  addiu       $v0, $zero, -0x1
    ctx->pc = 0x1b7d48u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
    // 0x1b7d4c: 0x802347f8  lb          $v1, 0x47F8($at)
    ctx->pc = 0x1b7d4cu;
    SET_GPR_S32(ctx, 3, (int8_t)READ8(ADD32(GPR_U32(ctx, 1), 18424)));
    // 0x1b7d50: 0x3c010032  lui         $at, 0x32
    ctx->pc = 0x1b7d50u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)50 << 16));
    // 0x1b7d54: 0xa02343f9  sb          $v1, 0x43F9($at)
    ctx->pc = 0x1b7d54u;
    WRITE8(ADD32(GPR_U32(ctx, 1), 17401), (uint8_t)GPR_U32(ctx, 3));
    // 0x1b7d58: 0x3c010023  lui         $at, 0x23
    ctx->pc = 0x1b7d58u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)35 << 16));
    // 0x1b7d5c: 0xa02247f8  sb          $v0, 0x47F8($at)
    ctx->pc = 0x1b7d5cu;
    WRITE8(ADD32(GPR_U32(ctx, 1), 18424), (uint8_t)GPR_U32(ctx, 2));
label_1b7d60:
    // 0x1b7d60: 0x3c010032  lui         $at, 0x32
    ctx->pc = 0x1b7d60u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)50 << 16));
    // 0x1b7d64: 0x942244d0  lhu         $v0, 0x44D0($at)
    ctx->pc = 0x1b7d64u;
    SET_GPR_U32(ctx, 2, (uint16_t)READ16(ADD32(GPR_U32(ctx, 1), 17616)));
    // 0x1b7d68: 0x1440000c  bnez        $v0, . + 4 + (0xC << 2)
    ctx->pc = 0x1B7D68u;
    {
        const bool branch_taken_0x1b7d68 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x1B7D6Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1B7D68u;
            // 0x1b7d6c: 0x24120004  addiu       $s2, $zero, 0x4 (Delay Slot)
        SET_GPR_S32(ctx, 18, (int32_t)ADD32(GPR_U32(ctx, 0), 4));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1b7d68) {
            ctx->pc = 0x1B7D9Cu;
            goto label_1b7d9c;
        }
    }
    ctx->pc = 0x1B7D70u;
    // 0x1b7d70: 0x3c010032  lui         $at, 0x32
    ctx->pc = 0x1b7d70u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)50 << 16));
    // 0x1b7d74: 0x902243c0  lbu         $v0, 0x43C0($at)
    ctx->pc = 0x1b7d74u;
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 1), 17344)));
    // 0x1b7d78: 0x10400005  beqz        $v0, . + 4 + (0x5 << 2)
    ctx->pc = 0x1B7D78u;
    {
        const bool branch_taken_0x1b7d78 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x1B7D7Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1B7D78u;
            // 0x1b7d7c: 0x24120010  addiu       $s2, $zero, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 18, (int32_t)ADD32(GPR_U32(ctx, 0), 16));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1b7d78) {
            ctx->pc = 0x1B7D90u;
            goto label_1b7d90;
        }
    }
    ctx->pc = 0x1B7D80u;
    // 0x1b7d80: 0x3c01004c  lui         $at, 0x4C
    ctx->pc = 0x1b7d80u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)76 << 16));
    // 0x1b7d84: 0x9022adec  lbu         $v0, -0x5214($at)
    ctx->pc = 0x1b7d84u;
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 1), 4294946284)));
    // 0x1b7d88: 0x14400003  bnez        $v0, . + 4 + (0x3 << 2)
    ctx->pc = 0x1B7D88u;
    {
        const bool branch_taken_0x1b7d88 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x1b7d88) {
            ctx->pc = 0x1B7D98u;
            goto label_1b7d98;
        }
    }
    ctx->pc = 0x1B7D90u;
label_1b7d90:
    // 0x1b7d90: 0x10000003  b           . + 4 + (0x3 << 2)
    ctx->pc = 0x1B7D90u;
    {
        const bool branch_taken_0x1b7d90 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1B7D94u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1B7D90u;
            // 0x1b7d94: 0x2411ffff  addiu       $s1, $zero, -0x1 (Delay Slot)
        SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1b7d90) {
            ctx->pc = 0x1B7DA0u;
            goto label_1b7da0;
        }
    }
    ctx->pc = 0x1B7D98u;
label_1b7d98:
    // 0x1b7d98: 0x24120004  addiu       $s2, $zero, 0x4
    ctx->pc = 0x1b7d98u;
    SET_GPR_S32(ctx, 18, (int32_t)ADD32(GPR_U32(ctx, 0), 4));
label_1b7d9c:
    // 0x1b7d9c: 0x2411000c  addiu       $s1, $zero, 0xC
    ctx->pc = 0x1b7d9cu;
    SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 0), 12));
label_1b7da0:
    // 0x1b7da0: 0xc06e0a0  jal         func_1B8280
    ctx->pc = 0x1B7DA0u;
    SET_GPR_U32(ctx, 31, 0x1B7DA8u);
    ctx->pc = 0x1B8280u;
    if (runtime->hasFunction(0x1B8280u)) {
        auto targetFn = runtime->lookupFunction(0x1B8280u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1B7DA8u; }
        if (ctx->pc != 0x1B7DA8u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001B8280_0x1b8280(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1B7DA8u; }
        if (ctx->pc != 0x1B7DA8u) { return; }
    }
    ctx->pc = 0x1B7DA8u;
label_1b7da8:
    // 0x1b7da8: 0x10400003  beqz        $v0, . + 4 + (0x3 << 2)
    ctx->pc = 0x1B7DA8u;
    {
        const bool branch_taken_0x1b7da8 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x1B7DACu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1B7DA8u;
            // 0x1b7dac: 0x3c100031  lui         $s0, 0x31 (Delay Slot)
        SET_GPR_S32(ctx, 16, (int32_t)((uint32_t)49 << 16));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1b7da8) {
            ctx->pc = 0x1B7DB8u;
            goto label_1b7db8;
        }
    }
    ctx->pc = 0x1B7DB0u;
    // 0x1b7db0: 0x902d  daddu       $s2, $zero, $zero
    ctx->pc = 0x1b7db0u;
    SET_GPR_U64(ctx, 18, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1b7db4: 0x2411000c  addiu       $s1, $zero, 0xC
    ctx->pc = 0x1b7db4u;
    SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 0), 12));
label_1b7db8:
    // 0x1b7db8: 0x982d  daddu       $s3, $zero, $zero
    ctx->pc = 0x1b7db8u;
    SET_GPR_U64(ctx, 19, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1b7dbc: 0x26106350  addiu       $s0, $s0, 0x6350
    ctx->pc = 0x1b7dbcu;
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 16), 25424));
label_1b7dc0:
    // 0x1b7dc0: 0x272102a  slt         $v0, $s3, $s2
    ctx->pc = 0x1b7dc0u;
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 19) < (int64_t)GPR_S64(ctx, 18)) ? 1 : 0);
    // 0x1b7dc4: 0x14400003  bnez        $v0, . + 4 + (0x3 << 2)
    ctx->pc = 0x1B7DC4u;
    {
        const bool branch_taken_0x1b7dc4 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x1B7DC8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1B7DC4u;
            // 0x1b7dc8: 0x233082a  slt         $at, $s1, $s3 (Delay Slot)
        SET_GPR_U64(ctx, 1, ((int64_t)GPR_S64(ctx, 17) < (int64_t)GPR_S64(ctx, 19)) ? 1 : 0);
        ctx->in_delay_slot = false;
        if (branch_taken_0x1b7dc4) {
            ctx->pc = 0x1B7DD4u;
            goto label_1b7dd4;
        }
    }
    ctx->pc = 0x1B7DCCu;
    // 0x1b7dcc: 0x1020002e  beqz        $at, . + 4 + (0x2E << 2)
    ctx->pc = 0x1B7DCCu;
    {
        const bool branch_taken_0x1b7dcc = (GPR_U64(ctx, 1) == GPR_U64(ctx, 0));
        if (branch_taken_0x1b7dcc) {
            ctx->pc = 0x1B7E88u;
            goto label_1b7e88;
        }
    }
    ctx->pc = 0x1B7DD4u;
label_1b7dd4:
    // 0x1b7dd4: 0x86040000  lh          $a0, 0x0($s0)
    ctx->pc = 0x1b7dd4u;
    SET_GPR_S32(ctx, 4, (int16_t)READ16(ADD32(GPR_U32(ctx, 16), 0)));
    // 0x1b7dd8: 0x24020010  addiu       $v0, $zero, 0x10
    ctx->pc = 0x1b7dd8u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 16));
    // 0x1b7ddc: 0x1082001e  beq         $a0, $v0, . + 4 + (0x1E << 2)
    ctx->pc = 0x1B7DDCu;
    {
        const bool branch_taken_0x1b7ddc = (GPR_U64(ctx, 4) == GPR_U64(ctx, 2));
        ctx->pc = 0x1B7DE0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1B7DDCu;
            // 0x1b7de0: 0x24020002  addiu       $v0, $zero, 0x2 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 2));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1b7ddc) {
            ctx->pc = 0x1B7E58u;
            goto label_1b7e58;
        }
    }
    ctx->pc = 0x1B7DE4u;
    // 0x1b7de4: 0x10820018  beq         $a0, $v0, . + 4 + (0x18 << 2)
    ctx->pc = 0x1B7DE4u;
    {
        const bool branch_taken_0x1b7de4 = (GPR_U64(ctx, 4) == GPR_U64(ctx, 2));
        if (branch_taken_0x1b7de4) {
            ctx->pc = 0x1B7E48u;
            goto label_1b7e48;
        }
    }
    ctx->pc = 0x1B7DECu;
    // 0x1b7dec: 0x24020001  addiu       $v0, $zero, 0x1
    ctx->pc = 0x1b7decu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x1b7df0: 0x10820025  beq         $a0, $v0, . + 4 + (0x25 << 2)
    ctx->pc = 0x1B7DF0u;
    {
        const bool branch_taken_0x1b7df0 = (GPR_U64(ctx, 4) == GPR_U64(ctx, 2));
        ctx->pc = 0x1B7DF4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1B7DF0u;
            // 0x1b7df4: 0x24030008  addiu       $v1, $zero, 0x8 (Delay Slot)
        SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 8));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1b7df0) {
            ctx->pc = 0x1B7E88u;
            goto label_1b7e88;
        }
    }
    ctx->pc = 0x1B7DF8u;
    // 0x1b7df8: 0x1083000e  beq         $a0, $v1, . + 4 + (0xE << 2)
    ctx->pc = 0x1B7DF8u;
    {
        const bool branch_taken_0x1b7df8 = (GPR_U64(ctx, 4) == GPR_U64(ctx, 3));
        ctx->pc = 0x1B7DFCu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1B7DF8u;
            // 0x1b7dfc: 0x2402000c  addiu       $v0, $zero, 0xC (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 12));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1b7df8) {
            ctx->pc = 0x1B7E34u;
            goto label_1b7e34;
        }
    }
    ctx->pc = 0x1B7E00u;
    // 0x1b7e00: 0x1082000a  beq         $a0, $v0, . + 4 + (0xA << 2)
    ctx->pc = 0x1B7E00u;
    {
        const bool branch_taken_0x1b7e00 = (GPR_U64(ctx, 4) == GPR_U64(ctx, 2));
        if (branch_taken_0x1b7e00) {
            ctx->pc = 0x1B7E2Cu;
            goto label_1b7e2c;
        }
    }
    ctx->pc = 0x1B7E08u;
    // 0x1b7e08: 0x24020004  addiu       $v0, $zero, 0x4
    ctx->pc = 0x1b7e08u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4));
    // 0x1b7e0c: 0x10820005  beq         $a0, $v0, . + 4 + (0x5 << 2)
    ctx->pc = 0x1B7E0Cu;
    {
        const bool branch_taken_0x1b7e0c = (GPR_U64(ctx, 4) == GPR_U64(ctx, 2));
        if (branch_taken_0x1b7e0c) {
            ctx->pc = 0x1B7E24u;
            goto label_1b7e24;
        }
    }
    ctx->pc = 0x1B7E14u;
    // 0x1b7e14: 0x1080001c  beqz        $a0, . + 4 + (0x1C << 2)
    ctx->pc = 0x1B7E14u;
    {
        const bool branch_taken_0x1b7e14 = (GPR_U64(ctx, 4) == GPR_U64(ctx, 0));
        if (branch_taken_0x1b7e14) {
            ctx->pc = 0x1B7E88u;
            goto label_1b7e88;
        }
    }
    ctx->pc = 0x1B7E1Cu;
    // 0x1b7e1c: 0x1000001b  b           . + 4 + (0x1B << 2)
    ctx->pc = 0x1B7E1Cu;
    {
        const bool branch_taken_0x1b7e1c = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1B7E20u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1B7E1Cu;
            // 0x1b7e20: 0x26730001  addiu       $s3, $s3, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 19, (int32_t)ADD32(GPR_U32(ctx, 19), 1));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1b7e1c) {
            ctx->pc = 0x1B7E8Cu;
            goto label_1b7e8c;
        }
    }
    ctx->pc = 0x1B7E24u;
label_1b7e24:
    // 0x1b7e24: 0x10000018  b           . + 4 + (0x18 << 2)
    ctx->pc = 0x1B7E24u;
    {
        const bool branch_taken_0x1b7e24 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1B7E28u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1B7E24u;
            // 0x1b7e28: 0xa6030000  sh          $v1, 0x0($s0) (Delay Slot)
        WRITE16(ADD32(GPR_U32(ctx, 16), 0), (uint16_t)GPR_U32(ctx, 3));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1b7e24) {
            ctx->pc = 0x1B7E88u;
            goto label_1b7e88;
        }
    }
    ctx->pc = 0x1B7E2Cu;
label_1b7e2c:
    // 0x1b7e2c: 0x10000016  b           . + 4 + (0x16 << 2)
    ctx->pc = 0x1B7E2Cu;
    {
        const bool branch_taken_0x1b7e2c = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1B7E30u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1B7E2Cu;
            // 0x1b7e30: 0xa6030000  sh          $v1, 0x0($s0) (Delay Slot)
        WRITE16(ADD32(GPR_U32(ctx, 16), 0), (uint16_t)GPR_U32(ctx, 3));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1b7e2c) {
            ctx->pc = 0x1B7E88u;
            goto label_1b7e88;
        }
    }
    ctx->pc = 0x1B7E34u;
label_1b7e34:
    // 0x1b7e34: 0x8e020004  lw          $v0, 0x4($s0)
    ctx->pc = 0x1b7e34u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 4)));
    // 0x1b7e38: 0x40f809  jalr        $v0
    ctx->pc = 0x1B7E38u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 2);
        SET_GPR_U32(ctx, 31, 0x1B7E40u);
        ctx->pc = 0x1B7E3Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1B7E38u;
            // 0x1b7e3c: 0x200202d  daddu       $a0, $s0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (jumpTarget == 0u) {
            ctx->pc = 0x1B7E40u;
        } else {
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1B7CE4u: goto label_1b7ce4;
            case 0x1B7D1Cu: goto label_1b7d1c;
            case 0x1B7D28u: goto label_1b7d28;
            case 0x1B7D44u: goto label_1b7d44;
            case 0x1B7D60u: goto label_1b7d60;
            case 0x1B7D90u: goto label_1b7d90;
            case 0x1B7D98u: goto label_1b7d98;
            case 0x1B7D9Cu: goto label_1b7d9c;
            case 0x1B7DA0u: goto label_1b7da0;
            case 0x1B7DA8u: goto label_1b7da8;
            case 0x1B7DB8u: goto label_1b7db8;
            case 0x1B7DC0u: goto label_1b7dc0;
            case 0x1B7DD4u: goto label_1b7dd4;
            case 0x1B7E24u: goto label_1b7e24;
            case 0x1B7E2Cu: goto label_1b7e2c;
            case 0x1B7E34u: goto label_1b7e34;
            case 0x1B7E40u: goto label_1b7e40;
            case 0x1B7E48u: goto label_1b7e48;
            case 0x1B7E58u: goto label_1b7e58;
            case 0x1B7E78u: goto label_1b7e78;
            case 0x1B7E88u: goto label_1b7e88;
            case 0x1B7E8Cu: goto label_1b7e8c;
            case 0x1B7EA0u: goto label_1b7ea0;
            case 0x1B7EB0u: goto label_1b7eb0;
            case 0x1B7EB8u: goto label_1b7eb8;
            default: break;
        }
        {
            auto targetFn = runtime->lookupFunction(jumpTarget);
            const uint32_t __entryPc = ctx->pc;
            targetFn(rdram, ctx, runtime);
            if (ctx->pc == __entryPc) { ctx->pc = 0x1B7E40u; }
            if (ctx->pc != 0x1B7E40u) { return; }
        }
        }
    }
    ctx->pc = 0x1B7E40u;
label_1b7e40:
    // 0x1b7e40: 0x10000011  b           . + 4 + (0x11 << 2)
    ctx->pc = 0x1B7E40u;
    {
        const bool branch_taken_0x1b7e40 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x1b7e40) {
            ctx->pc = 0x1B7E88u;
            goto label_1b7e88;
        }
    }
    ctx->pc = 0x1B7E48u;
label_1b7e48:
    // 0x1b7e48: 0xa6000002  sh          $zero, 0x2($s0)
    ctx->pc = 0x1b7e48u;
    WRITE16(ADD32(GPR_U32(ctx, 16), 2), (uint16_t)GPR_U32(ctx, 0));
    // 0x1b7e4c: 0x24020004  addiu       $v0, $zero, 0x4
    ctx->pc = 0x1b7e4cu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4));
    // 0x1b7e50: 0x1000000d  b           . + 4 + (0xD << 2)
    ctx->pc = 0x1B7E50u;
    {
        const bool branch_taken_0x1b7e50 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1B7E54u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1B7E50u;
            // 0x1b7e54: 0xa6020000  sh          $v0, 0x0($s0) (Delay Slot)
        WRITE16(ADD32(GPR_U32(ctx, 16), 0), (uint16_t)GPR_U32(ctx, 2));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1b7e50) {
            ctx->pc = 0x1B7E88u;
            goto label_1b7e88;
        }
    }
    ctx->pc = 0x1B7E58u;
label_1b7e58:
    // 0x1b7e58: 0x86020002  lh          $v0, 0x2($s0)
    ctx->pc = 0x1b7e58u;
    SET_GPR_S32(ctx, 2, (int16_t)READ16(ADD32(GPR_U32(ctx, 16), 2)));
    // 0x1b7e5c: 0x2442ffff  addiu       $v0, $v0, -0x1
    ctx->pc = 0x1b7e5cu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 4294967295));
    // 0x1b7e60: 0xa6020002  sh          $v0, 0x2($s0)
    ctx->pc = 0x1b7e60u;
    WRITE16(ADD32(GPR_U32(ctx, 16), 2), (uint16_t)GPR_U32(ctx, 2));
    // 0x1b7e64: 0x86020002  lh          $v0, 0x2($s0)
    ctx->pc = 0x1b7e64u;
    SET_GPR_S32(ctx, 2, (int16_t)READ16(ADD32(GPR_U32(ctx, 16), 2)));
    // 0x1b7e68: 0x4410003  bgez        $v0, . + 4 + (0x3 << 2)
    ctx->pc = 0x1B7E68u;
    {
        const bool branch_taken_0x1b7e68 = (GPR_S64(ctx, 2) >= 0);
        if (branch_taken_0x1b7e68) {
            ctx->pc = 0x1B7E78u;
            goto label_1b7e78;
        }
    }
    ctx->pc = 0x1B7E70u;
    // 0x1b7e70: 0x10000005  b           . + 4 + (0x5 << 2)
    ctx->pc = 0x1B7E70u;
    {
        const bool branch_taken_0x1b7e70 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1B7E74u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1B7E70u;
            // 0x1b7e74: 0xa6000002  sh          $zero, 0x2($s0) (Delay Slot)
        WRITE16(ADD32(GPR_U32(ctx, 16), 2), (uint16_t)GPR_U32(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1b7e70) {
            ctx->pc = 0x1B7E88u;
            goto label_1b7e88;
        }
    }
    ctx->pc = 0x1B7E78u;
label_1b7e78:
    // 0x1b7e78: 0x14400003  bnez        $v0, . + 4 + (0x3 << 2)
    ctx->pc = 0x1B7E78u;
    {
        const bool branch_taken_0x1b7e78 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x1b7e78) {
            ctx->pc = 0x1B7E88u;
            goto label_1b7e88;
        }
    }
    ctx->pc = 0x1B7E80u;
    // 0x1b7e80: 0x24020004  addiu       $v0, $zero, 0x4
    ctx->pc = 0x1b7e80u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4));
    // 0x1b7e84: 0xa6020000  sh          $v0, 0x0($s0)
    ctx->pc = 0x1b7e84u;
    WRITE16(ADD32(GPR_U32(ctx, 16), 0), (uint16_t)GPR_U32(ctx, 2));
label_1b7e88:
    // 0x1b7e88: 0x26730001  addiu       $s3, $s3, 0x1
    ctx->pc = 0x1b7e88u;
    SET_GPR_S32(ctx, 19, (int32_t)ADD32(GPR_U32(ctx, 19), 1));
label_1b7e8c:
    // 0x1b7e8c: 0x2a620010  slti        $v0, $s3, 0x10
    ctx->pc = 0x1b7e8cu;
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 19) < (int64_t)(int32_t)16) ? 1 : 0);
    // 0x1b7e90: 0x1440ffcb  bnez        $v0, . + 4 + (-0x35 << 2)
    ctx->pc = 0x1B7E90u;
    {
        const bool branch_taken_0x1b7e90 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x1B7E94u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1B7E90u;
            // 0x1b7e94: 0x26100020  addiu       $s0, $s0, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 16), 32));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1b7e90) {
            ctx->pc = 0x1B7DC0u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_1b7dc0;
        }
    }
    ctx->pc = 0x1B7E98u;
    // 0x1b7e98: 0xc06e0a0  jal         func_1B8280
    ctx->pc = 0x1B7E98u;
    SET_GPR_U32(ctx, 31, 0x1B7EA0u);
    ctx->pc = 0x1B8280u;
    if (runtime->hasFunction(0x1B8280u)) {
        auto targetFn = runtime->lookupFunction(0x1B8280u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1B7EA0u; }
        if (ctx->pc != 0x1B7EA0u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001B8280_0x1b8280(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1B7EA0u; }
        if (ctx->pc != 0x1B7EA0u) { return; }
    }
    ctx->pc = 0x1B7EA0u;
label_1b7ea0:
    // 0x1b7ea0: 0x14400005  bnez        $v0, . + 4 + (0x5 << 2)
    ctx->pc = 0x1B7EA0u;
    {
        const bool branch_taken_0x1b7ea0 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x1b7ea0) {
            ctx->pc = 0x1B7EB8u;
            goto label_1b7eb8;
        }
    }
    ctx->pc = 0x1B7EA8u;
    // 0x1b7ea8: 0xc06bec8  jal         func_1AFB20
    ctx->pc = 0x1B7EA8u;
    SET_GPR_U32(ctx, 31, 0x1B7EB0u);
    ctx->pc = 0x1AFB20u;
    if (runtime->hasFunction(0x1AFB20u)) {
        auto targetFn = runtime->lookupFunction(0x1AFB20u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1B7EB0u; }
        if (ctx->pc != 0x1B7EB0u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001AFB20_0x1afb20(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1B7EB0u; }
        if (ctx->pc != 0x1B7EB0u) { return; }
    }
    ctx->pc = 0x1B7EB0u;
label_1b7eb0:
    // 0x1b7eb0: 0xc06efe8  jal         func_1BBFA0
    ctx->pc = 0x1B7EB0u;
    SET_GPR_U32(ctx, 31, 0x1B7EB8u);
    ctx->pc = 0x1BBFA0u;
    if (runtime->hasFunction(0x1BBFA0u)) {
        auto targetFn = runtime->lookupFunction(0x1BBFA0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1B7EB8u; }
        if (ctx->pc != 0x1B7EB8u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001BBFA0_0x1bbfa0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1B7EB8u; }
        if (ctx->pc != 0x1B7EB8u) { return; }
    }
    ctx->pc = 0x1B7EB8u;
label_1b7eb8:
    // 0x1b7eb8: 0xdfbf0040  ld          $ra, 0x40($sp)
    ctx->pc = 0x1b7eb8u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 64)));
    // 0x1b7ebc: 0x7bb30030  lq          $s3, 0x30($sp)
    ctx->pc = 0x1b7ebcu;
    SET_GPR_VEC(ctx, 19, READ128(ADD32(GPR_U32(ctx, 29), 48)));
    // 0x1b7ec0: 0x7bb20020  lq          $s2, 0x20($sp)
    ctx->pc = 0x1b7ec0u;
    SET_GPR_VEC(ctx, 18, READ128(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x1b7ec4: 0x7bb10010  lq          $s1, 0x10($sp)
    ctx->pc = 0x1b7ec4u;
    SET_GPR_VEC(ctx, 17, READ128(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x1b7ec8: 0x7bb00000  lq          $s0, 0x0($sp)
    ctx->pc = 0x1b7ec8u;
    SET_GPR_VEC(ctx, 16, READ128(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1b7ecc: 0x3e00008  jr          $ra
    ctx->pc = 0x1B7ECCu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1B7ED0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1B7ECCu;
            // 0x1b7ed0: 0x27bd0050  addiu       $sp, $sp, 0x50 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 80));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1B7CE4u: goto label_1b7ce4;
            case 0x1B7D1Cu: goto label_1b7d1c;
            case 0x1B7D28u: goto label_1b7d28;
            case 0x1B7D44u: goto label_1b7d44;
            case 0x1B7D60u: goto label_1b7d60;
            case 0x1B7D90u: goto label_1b7d90;
            case 0x1B7D98u: goto label_1b7d98;
            case 0x1B7D9Cu: goto label_1b7d9c;
            case 0x1B7DA0u: goto label_1b7da0;
            case 0x1B7DA8u: goto label_1b7da8;
            case 0x1B7DB8u: goto label_1b7db8;
            case 0x1B7DC0u: goto label_1b7dc0;
            case 0x1B7DD4u: goto label_1b7dd4;
            case 0x1B7E24u: goto label_1b7e24;
            case 0x1B7E2Cu: goto label_1b7e2c;
            case 0x1B7E34u: goto label_1b7e34;
            case 0x1B7E40u: goto label_1b7e40;
            case 0x1B7E48u: goto label_1b7e48;
            case 0x1B7E58u: goto label_1b7e58;
            case 0x1B7E78u: goto label_1b7e78;
            case 0x1B7E88u: goto label_1b7e88;
            case 0x1B7E8Cu: goto label_1b7e8c;
            case 0x1B7EA0u: goto label_1b7ea0;
            case 0x1B7EB0u: goto label_1b7eb0;
            case 0x1B7EB8u: goto label_1b7eb8;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1B7ED4u;
    // 0x1b7ed4: 0x0  nop
    ctx->pc = 0x1b7ed4u;
    // NOP
    // 0x1b7ed8: 0x0  nop
    ctx->pc = 0x1b7ed8u;
    // NOP
    // 0x1b7edc: 0x0  nop
    ctx->pc = 0x1b7edcu;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
